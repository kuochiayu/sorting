#include <stdio.h>
#include <stdlib.h>     // srand(), rand()
#include <sys/time.h>   // gettimeofday()
#include <string.h>
#include <math.h>
#include <time.h>

#define LEN 101
#define idx 10000

void selection_sort_1(int test_data[]);
void selection_sort_2(char test_data_2[idx][LEN]);

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
    selection_sort_1(test_data_1);
    gettimeofday(&end, NULL);
    diff_1 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;

    gettimeofday(&start, NULL);
    selection_sort_2(test_data_2);
    gettimeofday(&end, NULL);
    diff_2 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    // 實際的時間差
    printf("Sorting performance %ld us (equal %f sec)\n", diff_1, diff_1 / 1000000.0);
    printf("Sorting performance %ld us (equal %f sec)\n", diff_2, diff_2 / 1000000.0);
    return 0;
}

void selection_sort_1(int test_data[])
{
    for (int i=0 ; i<idx-1 ;i++)
    {
        int j;
        int min = i;
        for (j=i+1 ; j<idx ;j++)     //走訪未排序的元素
        {
            if (test_data[j] < test_data[min])    //找到目前最小值
            {
                min = j;    //紀錄最小值
            }
        }
        if(min != i)
        {
          int tmp;
          tmp=test_data[min];  //交換兩個變數
          test_data[min]=test_data[i];
          test_data[i]=tmp;
        }
        /* swap(&a[min], &a[i]);  */   //做交換
    }
}

void selection_sort_2(char test_data_2[idx][LEN])
{
    for (int i=0 ; i<idx-1 ;i++)
    {
        int j;
        int min = i;
        for (j=i+1 ; j<idx ;j++)     //走訪未排序的元素
        {
            if (strcmp(test_data_2[j], test_data_2[min])<0)    //找到目前最小值
            {
                min = j;    //紀錄最小值
            }
        }
        if(min != i)
        {
            char tmp[LEN] = {0};
            strcpy(tmp, test_data_2[min]);
            strcpy(test_data_2[min], test_data_2[i]);
            strcpy(test_data_2[i], tmp);
        }
        /* swap(&a[min], &a[i]);  */   //做交換
    }
}
