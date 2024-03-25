#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

/*����λ*/
int Init(int n,int a[][100])
{
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++) 
	a[j][i]=0;
	return 1;
} 
 
/*��������1������������ */
int Snake1(int n,int a[][100])
{
	int num=1; 
	a[0][0]=1;//��һλ��ֵ 
	
	int i=0,j=0;
	while(num<n*n)
	{
		while(i+1<n&&!a[j][i+1]) a[j][++i]=++num;//���� 
		while(j+1<n&&!a[j+1][i]) a[++j][i]=++num;//���� 
		while(i-1>=0&&!a[j][i-1]) a[j][--i]=++num;//���� 
		while(j-1>=0&&!a[j-1][i]) a[--j][i]=++num;//���� 
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%-5d",a[i][j]);
		printf("\n");
	}
	
	return 1;
}

/*��������2�����ǻ���������*/ 
int Snake2(int n,int a[][100])
{
	int num=1;
	a[0][0]=1;//��һλ��ֵ
	
	int sum=0;
	for(int k=1;k<=n;k++)//���������ĸ��� 
	sum+=k;
	
	int i=0,j=0;
	while(num < sum)
	{
		while(i+1<n&&!a[j][i+1]) a[j][++i]=++num;//���� 
		while(i-1>=0&&j+1<=n&&!a[j+1][i-1]) a[++j][--i]=++num;//б���� 
		while(j-1>=0&&!a[j-1][i]) a[--j][i]=++num;//���� 
	}
	
	int count = n;
	for(i=0;i<n;i++)//��� 
	{
		for(j=0;j<count;j++)
		printf("%-5d",a[i][j]);
		count--;
		printf("\n");
	}
	
	return 1;
}

/*��������3*/
int Snake3(int n,int a[][100])
{
	int num=1;
	a[0][0]=1;
	int i=0,j=0,k=i,l=j+1,count=1;
	
	while(num<n*n)
	{
		if(count<n)//���Գ���ʱ��֮ǰǰ 
		{
			j=++l;
			i=-1;//��λ 
			
			count++;
			while(i+1<n&&j-1>=0&&!a[j-1][i+1]) a[--j][++i]=++num;//���� 
			
		}
		else //���Գ���� 
		{
			i=k++;
			j=n;//��λ 
			
			while(i+1<n&&j-1>=0&&!a[j-1][i+1]) a[--j][++i]=++num;//���� 
		}	
	}
	
	for(i=0;i<n;i++)//��� 
	{
		for(j=0;j<n;j++)
		printf("%-5d",a[i][j]);
		printf("\n");
	}
	return 1;
} 

/*������*/ 
int main()
{
	int n;
	int a[100][100];
	printf("������n:");
	scanf("%d",&n);
	
	printf("��������1��\n");
	Init(n,a); 
	Snake1(n,a);
	printf("\n");
	
	printf("��������2��\n");
	Init(n,a);
	Snake2(n,a); 
	printf("\n");
	
	printf("��������3��\n");
	Init(n,a);
	Snake3(n,a); 
	printf("\n");
	while(1)
	{
		int i,j;
		printf("������i,j(i������ݣ���������)��");
		scanf("%d %d",&i,&j);
		printf("a[%d][%d] = %d\n",j,i,a[j-1][i-1]);
		int choice;
		printf("1.��\n2.��\n�Ƿ������:");
		scanf("%d",&choice);
		if(choice==1) continue;
		else break; 
	}
	

	return 1;
	
 } 

