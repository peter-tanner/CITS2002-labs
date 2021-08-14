/*
* 🌶 Write a function named replace() that replaces all instances of one string
  for another string in a third string. For example:

    prompt> ./replace red blue aredrobin
    abluerobin

    prompt> ./replace cat bison catocathartic
    bisonobisonhartic
	
* A reasonable prototype for the function is:
    void replace( char oldword[], char newword[], char whole_sentence[] );
* Ensure you have terminated your string correctly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool __match(int m_len, char m[], char s_len, char s[], int start)
{
    int offset = start + m_len;
    if (offset <= s_len)
    {
        int idx = 0;
        for (int i = start; i < offset; i++)
        {
            if (m[idx] != s[i])
            {
                return false;
            }
            idx++;
        }
        return true;
    }
    return false;
}

// assume match and replacement length > 0
void replace(char match[], char replacement[], char string[])
{
    int match_length = strlen(match);
    int replacement_length = strlen(replacement);
    int string_length = strlen(string);
    int positions[string_length]; // easy solution - probably memory wasteful
    int valid_positions[string_length];
    memset(positions, -1, sizeof positions);
    memset(valid_positions, -1, sizeof valid_positions);

    int idx = 0;
    int idx_v = 0;
    int idx_new = 0;
    int last_position = -__INT32_MAX__;

    // get possible positions.
    for (int i = 0; i < string_length; i++)
    {
        if (string[i] == match[0])
        {
            positions[idx] = i;
            idx++;
        }
    }

    // get valid positions for replacement.
    idx = 0;
    do
    {
        int position = positions[idx];
        if (__match(match_length, match, string_length, string, position))
        {
            // prevent overlapping matches
            if (position > last_position + match_length) {
                valid_positions[idx_v] = position;
                last_position = position;
                idx_v++;
            }
        }
        idx++;
    } while (positions[idx] != -1);

    // make new string
    char new_string[string_length + idx_v*(match_length - replacement_length)];
    idx = 0;
    idx_v = 0;
    while (string[idx] != '\0')
    {
        if (idx == valid_positions[idx_v]) {
            idx_v++;
            idx += match_length-1;
            for (size_t i = 0; i < replacement_length; i++)
            {
                new_string[idx_new] = replacement[i];
                idx_new++;
            }
        } else {
            new_string[idx_new] = string[idx];
            idx_new++;
        }
        idx++;
    }
    new_string[idx_new] = '\0';
    strcpy(string, new_string);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Error - only three arguments allowed\nreplace pattern replacement string\n");
        exit(EXIT_FAILURE);
    }
    
    replace(argv[1], argv[2], argv[3]);
    printf("%s\n", argv[3]);
    return 0;
}
