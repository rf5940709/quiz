/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
static void swap(int arr[], int i, int j);
void shuffle_cards(int arr[], int array_len);
void shuffle_cards_r(int arr[], int array_len);

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
	int arr[52];
	for(int a = 0; a < 52; a++)
		arr[a] = a + 1;
	clock_gettime(CLOCK_REALTIME, &start);
        for(int x = 0; x < 500; x++)
                shuffle_cards(arr,52);
        clock_gettime(CLOCK_REALTIME, &end);
        cpu_time = diff_in_second(start, end);
        //printf("in:%c out:%c\n",c,result);
        printf("execution time of shuffle_cards() : %lf sec\n", cpu_time);
	return 0;
}
static void swap(int arr[], int i, int j)
{
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
}

void shuffle_cards(int arr[], int array_len)
{
        int value;
        srand((unsigned)time(NULL));//使rand出來的亂數和上次執行的不一樣
        for(int i = 0; i < array_len; i++)
        {
                value = i + rand() % (array_len - i);
                //printf("rand:%d org:%d\n", value, i);
                swap(arr, value, i);
        }
}
void shuffle_cards_r(int arr[], int array_len)
{
        static int value = 0, N = 0;
        if(N == 0)
                srand((unsigned)time(NULL));//使rand出來的亂數和上次執行的不一樣
        N++;
        if(1 < array_len)
        {
                shuffle_cards(arr, array_len - 1);
                value = (array_len - 1) + rand() % (N - (array_len - 1));
                //printf("rand : %d org : %d\n", value, array_len - 1);        
                swap(arr, value, array_len - 1);
	}
        else
        {
                value = rand() % (N);
                //printf("rand : %d org : %d\n", value, array_len - 1);        
                swap(arr, value, array_len - 1);
        }
	if(N == array_len-2)
	{
		N = 0;
		printf("%d\n", N);
	}
	//	printf("%d %d\n", N, array_len);
}
