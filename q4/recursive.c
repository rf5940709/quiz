/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int maxSubArray(int arr[], int len);

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
	struct timespec start, end;
        double cpu_time;
        int result = NULL;
        int A[9]={-2,1,-3,4,-1,2,1,-5,4};
        int p = 9;
        clock_gettime(CLOCK_REALTIME, &start);
 	for(int x = 0; x < 500; x++)
		result = maxSubArray(A,p);
        clock_gettime(CLOCK_REALTIME, &end);
        cpu_time = diff_in_second(start, end);
        printf("largestsum：%d\n",result);
        printf("execution time of maxSubArray() : %lf sec\n", cpu_time);
        //printf("largestsum：%d\n",maxSubArray(A,p));
	return 0;
}
int maxSubArray(int arr[], int len)
{
        static int largestsum = 0;//largestsum
        static int N = 0, n = 0;//N = len
        int sum;
	n++;
        if(len > 1)
        {
                sum = arr[len-1] + maxSubArray(arr, len-1);
                if(sum < arr[len-1])
                {
                        sum = arr[len-1];
                        if(sum > largestsum)
                                largestsum = sum;
                }
                else 
		{
                        if(sum > largestsum)
                                largestsum = sum;
                }
        }
        else
	{
                largestsum = sum = arr[len-1];
		N = n;
		n = 0;
        }
        //printf("j= %d  sum= %d  largestsum= %d\n", len, sum, largestsum);
        if(N == len)
	{
		N = 0;
                return largestsum;
	}
        else
                return sum;        
}
