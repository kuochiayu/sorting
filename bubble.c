#include <stdio.h>
#include <stdlib.h>     // srand(), rand()
#include <sys/time.h>   // gettimeofday()
#include <string.h>
#include <math.h>
#include <time.h>

#define LEN 101
#define idx 10000

void bubble_sort_1(int test_data_1[]);
void bubble_sort_2(char test_data_2[idx+1][LEN]);
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
    char test_data_2[idx+1][LEN];
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
    bubble_sort_1(test_data_1);
    gettimeofday(&end, NULL);
    diff_1 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;

    gettimeofday(&start, NULL);
    bubble_sort_2(test_data_2);
    gettimeofday(&end, NULL);
    diff_2 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    // 實際的時間差
    printf("Sorting performance %ld us (equal %f sec)\n", diff_1, diff_1 / 1000000.0);
    printf("Sorting performance %ld us (equal %f sec)\n", diff_2, diff_2 / 1000000.0);
    return 0;
}

void bubble_sort_1(int test_data_1[])
{
    for(int j=1 ; j<=idx; j++)
    {
        for(int k=0 ; k<=idx-2 ; k++)
        {
            int tmp;
            if(test_data_1[k]>test_data_1[k+1])
            {
                tmp = test_data_1[k+1];
                test_data_1[k+1] = test_data_1[k];
                test_data_1[k] = tmp;
            }
        }
    }
    return ;
}

void bubble_sort_2(char test_data_2[idx+1][LEN])
{
    for(int i=1; i<=idx; i++)
    {
        for(int j=0; j<=idx-2; j++)
        {
            char tmp[LEN] = {0};
            if(strcmp(test_data_2[j],test_data_2[j+1])<0)
            {
                strcpy(tmp, test_data_2[j+1]);
                strcpy(test_data_2[j+1], test_data_2[j]);
                strcpy(test_data_2[j], tmp);
            }
        }
    }
    return;
}
