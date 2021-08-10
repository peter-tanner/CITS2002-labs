/*
* 🌶 Write a program that prints out the "byte size" description of the (assumed
  to be numerical) arguments supplied to the program. For example:

prompt> ./bytesize 1 1200 2444555 5666777888
1Byte
1KByte
2MByte
5GByte  (this one may be a challenge!)
*/

#include <stdio.h>
#include <stdlib.h>

#define UNIT "Byte"

static char *METRIC_PREFIX[] = {"K", "M", "G", "T", "P", "E", "Z", "Y"};

/*
* Let's use the old standard which defines the size of 1kb to be 1024b, rather
  than 1000b (SI/IEC definition). Allows us to use bitshifts.
* https://en.wikipedia.org/wiki/Kilobyte
*/
char byteSize(unsigned long long size) {
    int level = 0;
    while ((size >> 10) > 0) {
        size >>= 10;
        level++;
    }
	
	if (level > 0) {
    	printf("%llu%s%s\n", size, METRIC_PREFIX[level-1], UNIT);
	} else {
    	printf("%llu%s\n", size, UNIT);
	}
	
}

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		printf("Must pass at least one size as a parameter\n");
		exit(EXIT_FAILURE);
	}
	
	for (int i = 1; i < argc; i++)
	{
		byteSize(atoll(argv[i]));
	}
	exit(EXIT_SUCCESS);
	return 0;
}
