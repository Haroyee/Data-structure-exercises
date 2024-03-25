#include<stdio.h>
#include<malloc.h>

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

//*链栈的清空*//
int clear_stack(LinkStack &S)
{
	while(S!=NULL)
	{
		LinkStack p;
		p=S;
		S=S->next;
		free(p);	
	}
	return 1;
} 

//*链栈的销毁*//
int destory_stack(LinkStack &S)
{
	clear_stack(S);
	free(S);
	return 1;
 } 
 
//*链栈的栈空判断*//
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

//*得到栈顶元素*//

int gettop(LinkStack &S,int *e)
{
	if(if_empty(S))
	{
		printf("当前栈空！！\n");
		return 0;
	}
	* e=S->data;
	return 1;
 } 
 
//*栈的遍历*//
int print_stack(LinkStack &S)
{
	if(if_empty(S))
	{
		printf("当前栈空！！\n");
		return 0;
	}
	LinkStack p=S;
	printf("当前栈中元素：");
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
	return 1;	
} 
int main()
{
	LinkStack top;
	int chioce,e;
    while(1)	

	{
		printf("1.初始化\n2.销毁\n3.清空\n4.判断栈空\n5.入栈\n6.出栈\n7.获取栈顶元素\n8.输出栈\n9.退出\n==========================\n");
		printf("请输入要执行的操作：");
		scanf("%d",&chioce);
		if(chioce==9) return 0;
		switch(chioce)
		{
			case 1:if(re_stack(top)) printf("初始化成功!\n");break;
			case 2:if(destory_stack(top)) printf("销毁成功！\n");break;
			case 3:if(clear_stack(top)) printf("清空成功!\n");break;
			case 4:if(if_empty(top)) printf("当前栈空！\n");else printf("当前栈非空！\n");break;
			case 5:printf("输入数据：");scanf("%d",&e);if(in_stack(top,e)) printf("入栈成功！\n");break;
			case 6:if(out_stack(top,&e)) printf("出栈元素为：%d\n",e);break;
			case 7:if(gettop(top,&e)) printf("栈顶元素为：%d\n",e);break;
			case 8:print_stack(top);break;
	 	}
	}
	 return 1;
}
