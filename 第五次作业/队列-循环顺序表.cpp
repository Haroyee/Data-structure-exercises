#include <stdio.h>
#include <stdlib.h>
#define size 100

/*定义结构体*/
typedef struct Q{
	int *data;
	int fornt;
	int rear;
}LinkQueue; 

/*初始化*/

int re_creat(LinkQueue &Q)
{
	Q.data=new int[size];
	if(!Q.data) {
		printf("初始化失败！\n");
		exit(0);
	}
	Q.fornt=Q.rear=0;
	return 1;
} 
/*判断是否为空*/
int EmptyQ(LinkQueue &Q)
{
	return Q.fornt==Q.rear;
}
/*判断是否满*/
int MaxQ(LinkQueue &Q) 
{
	return (Q.rear+1)%size==Q.fornt;
 } 
/*获取长度*/
int GetLongth(LinkQueue &Q)
{
	return (Q.rear-Q.fornt+size)%size;
}

/*进队*/
int InQ(LinkQueue &Q,int e)
{
	if(MaxQ(Q))
	{
		printf("当前队满！\n");
		return 0;
	}
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%size;
	return 1;
	
}
/*出队*/
int OutQ(LinkQueue &Q,int &e)
{
	if(EmptyQ(Q))
	{
		printf("当前队空！\n");
		return 0;
	}
	e = Q.data[Q.fornt];
	Q.fornt=(Q.fornt+1)%size;
	return 1;
}
/*获取队头元素*/
int GetHead(LinkQueue &Q,int &e)
{
		if(EmptyQ(Q))
	{
		printf("当前队空！\n");
		return 0;
	}
	e = Q.fornt;
	return 1;
}

/*清空*/
int DestoryQ(LinkQueue &Q)
{
	free(Q.data);
	Q.fornt=Q.rear=0;
	return 1;
}

/*遍历*/ 
int PrintfQ(LinkQueue &Q)
{
		if(EmptyQ(Q))
	{
		printf("当前队空！\n");
		return 0;
	}
	int i=Q.fornt;
	printf("队列元素有：");
	while(1)
	{
		if(((i+1-Q.fornt+size)%size)%GetLongth(Q)==0) break;
		printf("%d ",Q.data[i]);
		i=(i+1)%size;
	}
	if(!MaxQ(Q))
	printf("%d ",Q.data[i]);
	printf("\n");
	return 1;
}

int main()
{
	LinkQueue Q;
	re_creat(Q);
int choice;
        int data,i,n;
        while(1)
        {
        	printf("=============================\n");
        	printf("******1.入队     2.出队******\n"); 
        	printf("******3.队头     4.队尾******\n"); 
        	printf("******5.队长     6.遍历******\n"); 
        	printf("******7.清空     8.退出******\n");
			printf("=============================\n"); 
        	printf("请输入要执行操作：");
        	scanf("%d",&choice);
        	if(choice==8)
			return 0; 
        	switch(choice)
        	{
        		case 1:
        			printf("请输入元素个数：");
        			scanf("%d",&n);
        			for(i=0;i<n;i++)
        			{
						printf("请输入第%d个元素：",i+1);
        				scanf("%d",&data);
        				InQ(Q,data);
        			};
					break;
				case 2:
					printf("请输入元素个数：");
        			scanf("%d",&n);
        			printf("出队元素有：") ;
					for(i=0;i<n;i++)
        			{
        				OutQ(Q,data);
        				printf("%d ",data);
        			};
        			break;
				case 3:
					GetHead(Q,data);
					printf("队头元素为：%d\n",data);
					break;
				case 4:break;
				case 5:
					int longth;
					longth = GetLongth(Q);
					printf("队长度为：%d",longth);
					break;
				case 6:
					PrintfQ(Q);
					break;
				case 7:
					DestoryQ(Q);
					break;		
			}
		}
        
 
        printf("\n");
	
	return 1;
}
