//C:\\Users\\CXQ\\Desktop\\�����ĵ�\\C����\\���ݽṹ\\��һ����ҵ\\��������\\1000.txt
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<sys/time.h>

//������ 
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
{   //*����ʱ�亯��*//
	struct timeval start,end;
	
	//*��ȡ�ļ�*// 
	int n,i;
	FILE *fp;
	char filename[200];
	printf("�������ļ�·����"); 
	scanf("%s",filename); 
	
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("�ļ��޷��򿪣�");
		return 0; 
	}
	 
	printf("�������ļ����ݸ�����");
	scanf("%d",&n);
	int *a;
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d ",&a[i]);
	}

	//*��ʼ����*// 
	gettimeofday(&start,NULL);
	qsort(a,0,n-1);
	gettimeofday(&end,NULL);
	printf("���������ʱ��%lf s",(end.tv_sec-start.tv_sec)+(double)(end.tv_usec-start.tv_usec)/1000000.0);
	
	FILE *fp1;
	int longth=strlen(filename)-4;
	filename[longth++]='s';filename[longth++]='o';filename[longth++]='r';filename[longth++]='t';
	filename[longth++]='.';filename[longth++]='t';filename[longth++]='x';filename[longth]='t';
	if((fp1=fopen(filename,"w"))==NULL) {
	printf("���ļ�ʧ�ܣ�"); 
	return 0;}
	for(i=0;i<n;i++)
		fprintf(fp1,"%d ",a[i]);
	fclose(fp);
	fclose(fp1); 
	return 0;
} 
