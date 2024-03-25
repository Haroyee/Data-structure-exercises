#include <stdio.h>
#include <stdlib.h>
#define size 101 //最大容量为size-1 


/*定义结构体*/
typedef struct Q{
	int *data;
	int fornt;//队头 
	int rear;//队尾 
}LinkQueue; 

/*初始化*/

int re_creat(LinkQueue &Q)
{
	Q.data=new int[size];
	if(!Q.data) {
		printf("初始化失败！\n");
		exit(0);
	}
	Q.fornt=Q.rear=0;//队头尾均指向0 
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
	return (Q.rear-Q.fornt+size)%size;//加size是为了防止Q.rear<Q.front 
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
	Q.rear=(Q.rear+1)%size;//队尾指针+1 
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
	Q.fornt=(Q.fornt+1)%size;//队头指针+1 
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
	printf("幸存者有：");
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

/*出局函数*/
int GoOut(LinkQueue &Q,int i,int j)//Q为储存队员的队，i为队员人数，j为出局密码 
{
	int count = 1,data,l=1; 
	while(GetLongth(Q)>15)
	{
			if(count%j!=0)
			{
				OutQ(Q,data);
				InQ(Q,data);
				count++;
			}
			else 
			{
				OutQ(Q,data);
				printf("第%2d次出局的为：%d\n",l,data); 
				count++;
				l++;
			}
	}
	return 1;
} 
/*主函数*/ 
int main()
{
	int i;//计数器
     int N;//参与的人数
     int k;//报数密码
     printf("请输入参与人数：");
     scanf("%d",&N);
     printf("请输入出局密码：");
     scanf("%d",&k);
     
     LinkQueue Q;
     re_creat(Q);
    
     
     for(i=1;i<=N;i++)
     InQ(Q,i);
     
     GoOut(Q,N,k);
     
     PrintfQ(Q);  
}
