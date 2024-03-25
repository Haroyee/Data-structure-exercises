#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

/*方阵复位*/
int Init(int n,int a[][100])
{
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++) 
	a[j][i]=0;
	return 1;
} 
 
/*蛇形填数1（回形填数） */
int Snake1(int n,int a[][100])
{
	int num=1; 
	a[0][0]=1;//第一位赋值 
	
	int i=0,j=0;
	while(num<n*n)
	{
		while(i+1<n&&!a[j][i+1]) a[j][++i]=++num;//向右 
		while(j+1<n&&!a[j+1][i]) a[++j][i]=++num;//向下 
		while(i-1>=0&&!a[j][i-1]) a[j][--i]=++num;//向左 
		while(j-1>=0&&!a[j-1][i]) a[--j][i]=++num;//向上 
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%-5d",a[i][j]);
		printf("\n");
	}
	
	return 1;
}

/*蛇形填数2（三角回形填数）*/ 
int Snake2(int n,int a[][100])
{
	int num=1;
	a[0][0]=1;//第一位赋值
	
	int sum=0;
	for(int k=1;k<=n;k++)//求输入数的个数 
	sum+=k;
	
	int i=0,j=0;
	while(num < sum)
	{
		while(i+1<n&&!a[j][i+1]) a[j][++i]=++num;//向右 
		while(i-1>=0&&j+1<=n&&!a[j+1][i-1]) a[++j][--i]=++num;//斜向下 
		while(j-1>=0&&!a[j-1][i]) a[--j][i]=++num;//向上 
	}
	
	int count = n;
	for(i=0;i<n;i++)//输出 
	{
		for(j=0;j<count;j++)
		printf("%-5d",a[i][j]);
		count--;
		printf("\n");
	}
	
	return 1;
}

/*蛇形填数3*/
int Snake3(int n,int a[][100])
{
	int num=1;
	a[0][0]=1;
	int i=0,j=0,k=i,l=j+1,count=1;
	
	while(num<n*n)
	{
		if(count<n)//过对称轴时及之前前 
		{
			j=++l;
			i=-1;//归位 
			
			count++;
			while(i+1<n&&j-1>=0&&!a[j-1][i+1]) a[--j][++i]=++num;//填数 
			
		}
		else //过对称轴后 
		{
			i=k++;
			j=n;//归位 
			
			while(i+1<n&&j-1>=0&&!a[j-1][i+1]) a[--j][++i]=++num;//填数 
		}	
	}
	
	for(i=0;i<n;i++)//输出 
	{
		for(j=0;j<n;j++)
		printf("%-5d",a[i][j]);
		printf("\n");
	}
	return 1;
} 

/*主函数*/ 
int main()
{
	int n;
	int a[100][100];
	printf("请输入n:");
	scanf("%d",&n);
	
	printf("蛇形填数1：\n");
	Init(n,a); 
	Snake1(n,a);
	printf("\n");
	
	printf("蛇形填数2：\n");
	Init(n,a);
	Snake2(n,a); 
	printf("\n");
	
	printf("蛇形填数3：\n");
	Init(n,a);
	Snake3(n,a); 
	printf("\n");
	while(1)
	{
		int i,j;
		printf("请输入i,j(i代表横纵，代表纵轴)：");
		scanf("%d %d",&i,&j);
		printf("a[%d][%d] = %d\n",j,i,a[j-1][i-1]);
		int choice;
		printf("1.是\n2.否\n是否继续？:");
		scanf("%d",&choice);
		if(choice==1) continue;
		else break; 
	}
	

	return 1;
	
 } 

