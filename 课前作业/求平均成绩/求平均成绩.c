#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int *p,n,i,s,sum,avg;
	char name[500]; 
	printf("������ɼ��ĸ�����");
	scanf("%d",&n);
	p=(int *)malloc(n * sizeof(int));
	
	printf ("������ɼ����ļ�·��(�ּ�����˫б�ܸ���)��");
	scanf("%s",name);
	fp=fopen(name,"w+");
	i=0;
	while(i<n) 
	{
		printf("�������%d��ͬѧ����ѧ�ɼ���",i+1);
		scanf("%d",&s);
		fprintf(fp,"%d\n",s);
		i++;
	}
	rewind(fp);
	for(i=0;i<10;i++)
	{
		fscanf(fp,"%d",&s);
		*(p+i)=s;
	}
	for(i=0;i<10;i++)
	sum+=*(p+i);
	avg = sum/n;
	
	printf("avg=%d",avg); 
	
	return 0;
}
