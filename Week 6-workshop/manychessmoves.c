
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

struct current_instance {
    char *gamestate;
    char *output;
    int instance_no;
};

struct fork_list {
    pid_t *fork_list;
    int concurrent_forks;
};

int execute_chessmove(struct current_instance *instance)
{
    // concatenate original filename and the instance number
    int len = snprintf(NULL, 0, "%s-%d ", instance->output, instance->instance_no);
    char output_filename[len];
    snprintf(output_filename, len, "%s-%d ", instance->output, instance->instance_no);
    char *arguments[] = {
        "./goodchessmove",
        instance->gamestate, 
        output_filename,
        NULL
    };
    return execvp(arguments[0], arguments);
}

pid_t new_fork(struct current_instance *instance)
{
    pid_t pid;
    switch (pid = fork()) 
    {
    case -1:
        printf("fork() failed\n");
        exit(EXIT_FAILURE);
    case 0:
        exit( execute_chessmove(instance) );
    }
    return pid;
}

void populate_forks(int fork_count, struct fork_list *forks, struct current_instance *instance)
{
    if (fork_count > forks->concurrent_forks) {
        fork_count = forks->concurrent_forks;
    }
    
    for (size_t i = 0; i < fork_count; i++) {
        forks->fork_list[i] = new_fork(instance);
        instance->instance_no++;
    }
}

void replace_fork(pid_t old_pid, struct fork_list *forks, struct current_instance *instance)
{
    for (size_t i = 0; i < forks->concurrent_forks; i++) {
        if (forks->fork_list[i] == old_pid) {
            forks->fork_list[i] = new_fork(instance);
            instance->instance_no++;
            return;
        }
    }
}

int numberOfCores(void) // From worshop spec.
{
    return sysconf(_SC_NPROCESSORS_ONLN);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: manychessmoves [N PROCESSES] [GAMESTATE] [OUTPUT]\n");
        exit(EXIT_FAILURE);
    }

    int n_forks = atoi(argv[1]);
    int concurrent_forks = numberOfCores();
    pid_t fork_pids[concurrent_forks];

    struct fork_list fork_list = { fork_pids, concurrent_forks };
    struct current_instance instance = { argv[2], argv[3], 0 };

    populate_forks(n_forks, &fork_list, &instance);

    pid_t child;
    int status;
    while (concurrent_forks > 0)
    {
        child = wait( &status );
        if (status != 0) {
            printf("chess instance failed.\n");
            exit(EXIT_FAILURE);
        }

        if (instance.instance_no < n_forks) {
            replace_fork(child, &fork_list, &instance);
        } else {
            concurrent_forks--;
        }
    }
    exit(EXIT_SUCCESS);    
}
