#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
 
int main(void)
{
	srand(time(NULL));//種種子
	int i,j;
	FILE *fp = NULL;
    fp = fopen("C:\\Users\\Lenovo\\Desktop\\c\\dataset1.txt","w");//在指定目錄創建.txt檔案
	for(i = 0 ; i < 1000000 ; i ++) //產生10000000個隨機數
	{
		j = rand()%100 ;
		//printf("j:%d\n",j);
        	fprintf(fp,"%d\n",j); //寫進文件
    }
    fclose(fp); //關閉文件
    return 0;
}
