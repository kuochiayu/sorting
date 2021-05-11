#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LEN 101
#define idx 50000

int main() 
{
    srand(time(NULL));
    char text[LEN];
    char words[idx][LEN];
    FILE *fp = NULL;
    fp = fopen("C:\\Users\\Lenovo\\Desktop\\c\\dataset2.txt","w");//在指定目录下创建.txt文件
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
        printf("%d: %s\n",i+1,words[i]);
        fprintf(fp,"%s\n",words[i]); //把随机数写进文件
    }
    fclose(fp); //关闭文件

}