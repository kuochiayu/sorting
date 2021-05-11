#include <stdio.h>
#include <stdlib.h>     // srand(), rand()
#include <sys/time.h>   // gettimeofday()
#include <string.h>
#include <math.h>
#include <time.h>

#define LEN 101
#define idx 10000

void insertion_sort_1(int test_data_1[]);
void insertion_sort_2(char test_data_2[idx][LEN]);
int main()
{
    int test_data_1[idx + 1];
    //int test_data_2[10000 + 1];
    srand(1);
    for(int i = 0 ; i < idx ; i++)
    {
        test_data_1[i] = rand();
        //test_data_2[i] = rand();
    }

    srand(time(NULL));
    char text[LEN];
    char test_data_2[idx][LEN];
    memset(text, 1, LEN);
    for (int j=0; j<idx; j++) 
    {
        for(int i = 0; i < LEN-1; i++)
        {
            int b = rand() % 26; //生成0-25的随機數
            text[i] = b += 'a';
            strcpy(test_data_2[j], text);
            text[LEN-1] = 0;
        }
    }
    /********************************/
    /*      Test Performance        */
    /********************************/
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff_1;
    unsigned  long diff_2;
    // 儲存計算時間差
    gettimeofday(&start, NULL);
    insertion_sort_1(test_data_1);
    gettimeofday(&end, NULL);
    diff_1 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;

    gettimeofday(&start, NULL);
    insertion_sort_2(test_data_2);
    gettimeofday(&end, NULL);
    diff_2 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    // 實際的時間差
    printf("Sorting performance %ld us (equal %f sec)\n", diff_1, diff_1 / 1000000.0);
    printf("Sorting performance %ld us (equal %f sec)\n", diff_2, diff_2 / 1000000.0);
    return 0;
}

void insertion_sort_1(int test_data_1[])
{
    int key;
    for (int i=1;i!=idx;++i)
    {
        key = test_data_1[i];
        int j=i-1;
        while((j>=0) && (test_data_1[j]>key))
        {
            test_data_1[j+1] = test_data_1[j];
            j--;
        }
        test_data_1[j+1] = key;
    }
    return ;
}

void insertion_sort_2(char test_data_2[idx][LEN])
{
    char key[LEN]={0};
    for(int i=1; i!=idx; ++i)
    {
        strcpy(key, test_data_2[i]);
        int j = i-1;
        while((j>0) && strcmp(test_data_2[j],key)>0)
        {
            strcpy(test_data_2[j+1],test_data_2[j]);
            j--;
        }
        strcpy(test_data_2[j+1], key);
    }
    return;
}
