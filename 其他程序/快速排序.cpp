//C:\\Users\\CXQ\\Desktop\\各种文档\\C语言\\数据结构\\第一次作业\\快速排序\\1000.txt
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<sys/time.h>

//排序函数 
int qsort(int arr[],int low,int high)
{
	if(high < low ) return 0;
	int l = low,r = high,t = arr[l];
	while(l < r)
	{
		while(t < arr[r] && l < r)	
		r--;
		if(l < r)	
		arr[l++] = arr[r];
		while(t > arr[l] && l < r)	
		l++;
		if(l < r)	
		arr[r--] = arr[l];
	}
	arr[l] = t;
	qsort(arr,low,l-1);
	qsort(arr,l+1,high);
}

int main()
{   //*定义时间函数*//
	struct timeval start,end;
	
	//*读取文件*// 
	int n,i;
	FILE *fp;
	char filename[200];
	printf("请输入文件路径："); 
	scanf("%s",filename); 
	
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("文件无法打开！");
		return 0; 
	}
	 
	printf("请输入文件数据个数：");
	scanf("%d",&n);
	int *a;
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d ",&a[i]);
	}

	//*开始排序*// 
	gettimeofday(&start,NULL);
	qsort(a,0,n-1);
	gettimeofday(&end,NULL);
	printf("排序完成用时：%lf s",(end.tv_sec-start.tv_sec)+(double)(end.tv_usec-start.tv_usec)/1000000.0);
	
	FILE *fp1;
	int longth=strlen(filename)-4;
	filename[longth++]='s';filename[longth++]='o';filename[longth++]='r';filename[longth++]='t';
	filename[longth++]='.';filename[longth++]='t';filename[longth++]='x';filename[longth]='t';
	if((fp1=fopen(filename,"w"))==NULL) {
	printf("打开文件失败！"); 
	return 0;}
	for(i=0;i<n;i++)
		fprintf(fp1,"%d ",a[i]);
	fclose(fp);
	fclose(fp1); 
	return 0;
} 
