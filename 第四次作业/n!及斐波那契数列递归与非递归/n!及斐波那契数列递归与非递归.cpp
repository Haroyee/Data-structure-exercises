#include<stdio.h>
#include<sys/time.h>
/*n的阶乘递归*/ 
//用时：0.000000 s
int func1(int n)
{
	
	if(n)
	return n*(func1(n-1));
	else 
	return 1;
	
}

/*n的阶乘非递归*/
//用时：0.000000 s
int func2(int n)
{
	int sum=1;
	for(int i=n;i>=1;i--)
	sum*=i;
	return sum;
} 
/*斐波那契数列递归*/
//用时： 8859.5685 s 
int func3(int n)
{
	if(n==1) return 0;
	
	else if(n==1||n==2) return 1;
	
	else return func3(n-2)+func3(n-1);
}

/*斐波那契数列非递归*/
//用时：0.016113 s 
int func4(int n)
{
	int i,j=0,k=1,count=0;
	for(i=0;i<n/2-1;i++)
	{
		printf("\n%d:%d\n%d:%d ",count+1,j,count+2,k);
		j=j+k;k=j+k;
		count+=2;
	}
	j=j+k;k=j+k;
	if(n%2==1) printf("\n%d:%d ",count+1,j);
	else printf("\n%d:%d\n%d:%d ",count+1,j,count+2,k);
	
	
}

int main()
{
	struct timeval start,end;
	int choice,i,n;
	printf("\n1.n的阶乘递归\n2.n的阶乘非递归\n3.斐波那契数列递归\n4.斐波那契数列非递归\n");
	printf("\n请选择要执行的程序：");
	scanf("%d",&choice);
	printf("\n请输入n的值：") ;
	scanf("%d",&n);
	
	gettimeofday(&start,NULL);
	switch(choice)
	{
	case 1:
		for(i=1;i<=n;i++)
		printf("%d ",func1(i));break;
	case 2:
		for(i=1;i<=n;i++)
		printf("%d",func2(i));break;
	case 3:
		for(i=1;i<=n;i++)
		printf("%d ",func3(i));
		break;
	case 4:
		func4(n);break;
		
	 
	 } 
	 gettimeofday(&end,NULL);
	 
	printf("\n用时：%lf s",(end.tv_sec-start.tv_sec)+(double)(end.tv_usec-start.tv_usec)/1000000.0);
	
	
	
}
