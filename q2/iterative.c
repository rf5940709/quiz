/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char smallest_character(char str[], char c);

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main()
{
	char str[]="cfjpv";
        char result = NULL;
        struct timespec start, end;
        double cpu_time;

        char c = 'u';
        clock_gettime(CLOCK_REALTIME, &start);
	for(int x = 0; x < 500; x++)
	        result = smallest_character(str,c);
        clock_gettime(CLOCK_REALTIME, &end);
        cpu_time = diff_in_second(start, end);
        printf("in:%c out:%c\n",c,result);
        printf("execution time of smallest_character() : %lf sec\n", cpu_time);


        /*c = 'i';
        result = smallest_character(str,c);
        printf("in:%c out:%c\n",c,result);*/

	return 0;
}
//iterative
char smallest_character(char str[], char c)
{
        for(int i=0; i<strlen(str); i++)
        {
                if(c < str[i])
                        return str[i];
        }
        return str[0];
}

