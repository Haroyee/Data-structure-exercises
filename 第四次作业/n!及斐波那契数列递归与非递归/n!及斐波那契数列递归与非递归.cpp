#include<stdio.h>
#include<sys/time.h>
/*n�Ľ׳˵ݹ�*/ 
//��ʱ��0.000000 s
int func1(int n)
{
	
	if(n)
	return n*(func1(n-1));
	else 
	return 1;
	
}

/*n�Ľ׳˷ǵݹ�*/
//��ʱ��0.000000 s
int func2(int n)
{
	int sum=1;
	for(int i=n;i>=1;i--)
	sum*=i;
	return sum;
} 
/*쳲��������еݹ�*/
//��ʱ�� 8859.5685 s 
int func3(int n)
{
	if(n==1) return 0;
	
	else if(n==1||n==2) return 1;
	
	else return func3(n-2)+func3(n-1);
}

/*쳲��������зǵݹ�*/
//��ʱ��0.016113 s 
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
	printf("\n1.n�Ľ׳˵ݹ�\n2.n�Ľ׳˷ǵݹ�\n3.쳲��������еݹ�\n4.쳲��������зǵݹ�\n");
	printf("\n��ѡ��Ҫִ�еĳ���");
	scanf("%d",&choice);
	printf("\n������n��ֵ��") ;
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
	 
	printf("\n��ʱ��%lf s",(end.tv_sec-start.tv_sec)+(double)(end.tv_usec-start.tv_usec)/1000000.0);
	
	
	
}
