#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
 
int main(void)
{
	srand(time(NULL));//先种种子 
	int i,j;
	FILE *fp = NULL;
    fp = fopen("C:\\Users\\Lenovo\\Desktop\\c\\dataset1.txt","w");//在指定目录下创建.txt文件
	for(i = 0 ; i < 1000000 ; i ++) //产生10个100以内的随机数 
	{
		j = rand()%100 ;
		printf("j:%d\n",j);
        fprintf(fp,"%d\n",j); //把随机数写进文件
    }
    fclose(fp); //关闭文件
    return 0;
}
