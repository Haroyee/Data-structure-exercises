#include<stdio.h>
#include<stdlib.h>

typedef struct StackNode
{
	int data;
	struct StackNode *next;
 }StackNode,*LinkStack;

//*链栈的初始化*//
int re_stack(LinkStack &S)
{
	S=NULL;
	return 1;
}

/*链栈的栈空判断*/
int if_empty(LinkStack &S)
{
	if(S==NULL) return 1;
	else return 0;
} 

//*链栈的入栈*//
int in_stack(LinkStack &S,int e)
{
	LinkStack p;
	p=new StackNode;
	
	p->data=e;
	p->next=S;
	S=p;
	return 1;
} 

//*链栈的出栈*//
int out_stack(LinkStack &S,int *e)
{
	LinkStack p;
	if(if_empty(S))
	{
		printf("当前栈空！！\n");
		return 0;
	}
	p=S;
	* e=S->data;
	S=S->next;
	free(p);
	return 1;	
} 

 

/*栈的遍历*/
int print_stack(LinkStack &S)
{
	if(if_empty(S))
	{
		printf("当前栈空！！\n");
		return 0;
	}
	LinkStack p=S;
	printf("幸存者有：");
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
	return 1;	
} 

/*出局函数*/
int GoOut(LinkStack &A,LinkStack &B,int i,int j)//A为储存队员的栈，B为空栈,i为队员人数，j为出局密码 
{
	int num = i,count = 1,data,l=1; 
	while(num>15)
	{
		while(A)
		{
			if(count%j!=0)
			{
				out_stack(A,&data);
				in_stack(B,data);
				count++;
			}
			else 
			{
				out_stack(A,&data);
				printf("第%2d次出局的为：%d\n",l,data); 
				num--;
				count++;
				l++;
			}
		}
		
		while(B)
		{
			out_stack(B,&data);
			in_stack(A,data);
		}
	}
	return 1;
} 

int main()
{
	int i;//计数器
     int N;//参与的人数
     int k;//报数密码
     printf("请输入参与人数：");
     scanf("%d",&N);
     printf("请输入出局密码：");
     scanf("%d",&k);
     
     LinkStack A,B;
     re_stack(A);
     re_stack(B);
     
     for(i=N;i>=1;i--)
     in_stack(A,i);
     
     GoOut(A,B,N,k);
     
     print_stack(A);  
}
