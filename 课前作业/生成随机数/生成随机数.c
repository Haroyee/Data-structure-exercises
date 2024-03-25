#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j,n,t;
    int a[100];
    srand((int)time(NULL));
    FILE *fp1,*fp2;
    char name1[500],name2[500];
    printf("请输入sorting1文件路径(分级需用双斜杠隔开)：");
	scanf("%s",name1); 
    
    fp1=fopen(name1,"w+");
    
    i =0;
    while(i<100)
    {
        fprintf(fp1,"%d\n",rand());
        i++;
    }
    rewind(fp1);
    i=0;
    while(i<100)
    {
        fscanf(fp1,"%d\n",&a[i]);
        i++;
    }
    fclose(fp1);

    for(i=0;i<100;i++)
    for(j=0;j<99-i;j++)
    {
    	if(a[j]>a[j+1])
    	{
    		t=a[j];a[j]=a[j+1];a[j+1]=t;
		}
	}
	printf("请输入sorting2文件路径(分级需用双斜杠隔开)：");
	scanf("%s",name2); 
	fp2=fopen(name2,"w");
	i=0;
	while(i<100)
    {
        fprintf(fp2,"%d\n",a[i]);
        i++;
    }
    fclose(fp2);
    
    return 0;
}

