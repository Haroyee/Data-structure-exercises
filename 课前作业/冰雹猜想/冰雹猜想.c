//冰雹猜想
#include<stdio.h>

int main()
{
	int N,count; 

	while(scanf("%d",&N),N)
	{
	count=0;

	while(N!=1)
	{
		if(N%2==1)
		N=3*N+1;
		else
		N=N/2;
		count++;
	}
	printf("所需次数为%d\n",count);
	}
	return 0;
 } 
