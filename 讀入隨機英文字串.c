#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LEN 101
#define idx 10000

int main() 
{
    srand(time(NULL));
    char text[LEN];
    char words[idx][LEN];
    FILE *fp = NULL;
    fp = fopen("D:\\Users\\desktop\\sort\\dataset2.txt","a");//在指定目錄建.txt文件
    memset(text, 1, LEN);
    for (int j=0; j<idx; j++) 
    {
        for(int i = 0; i < LEN-1; i++)
        {
            int b = rand() % 26; //生成0-25的随機數
            text[i] = b += 'a';
            strcpy(words[j], text);
            text[LEN-1] = 0;
        }
    }
    //text[LEN-1] = 0;
    for(int i=0; i<idx; i++)
    {
        //printf("%d:\t%s\n", i+1, words[i]);
        fprintf(fp,"%s\n",words[i]); //把隨機寫進文件
    }
    fclose(fp); //關閉文件

}
