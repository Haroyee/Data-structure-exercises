#include<stdio.h>
#include<malloc.h>

typedef struct StackNode
{
	int data;
	struct StackNode *next;
 }StackNode,*LinkStack;

//*��ջ�ĳ�ʼ��*//
int re_stack(LinkStack &S)
{
	S=NULL;
	return 1;
}

//*��ջ�����*//
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

//*��ջ������*//
int destory_stack(LinkStack &S)
{
	clear_stack(S);
	free(S);
	return 1;
 } 
 
//*��ջ��ջ���ж�*//
int if_empty(LinkStack &S)
{
	if(S==NULL) return 1;
	else return 0;
} 

//*��ջ����ջ*//
int in_stack(LinkStack &S,int e)
{
	LinkStack p;
	p=new StackNode;
	
	p->data=e;
	p->next=S;
	S=p;
	return 1;
} 

//*��ջ�ĳ�ջ*//
int out_stack(LinkStack &S,int *e)
{
	LinkStack p;
	if(if_empty(S))
	{
		printf("��ǰջ�գ���\n");
		return 0;
	}
	p=S;
	* e=S->data;
	S=S->next;
	free(p);
	return 1;	
} 

//*�õ�ջ��Ԫ��*//

int gettop(LinkStack &S,int *e)
{
	if(if_empty(S))
	{
		printf("��ǰջ�գ���\n");
		return 0;
	}
	* e=S->data;
	return 1;
 } 
 
//*ջ�ı���*//
int print_stack(LinkStack &S)
{
	if(if_empty(S))
	{
		printf("��ǰջ�գ���\n");
		return 0;
	}
	LinkStack p=S;
	printf("��ǰջ��Ԫ�أ�");
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
		printf("1.��ʼ��\n2.����\n3.���\n4.�ж�ջ��\n5.��ջ\n6.��ջ\n7.��ȡջ��Ԫ��\n8.���ջ\n9.�˳�\n==========================\n");
		printf("������Ҫִ�еĲ�����");
		scanf("%d",&chioce);
		if(chioce==9) return 0;
		switch(chioce)
		{
			case 1:if(re_stack(top)) printf("��ʼ���ɹ�!\n");break;
			case 2:if(destory_stack(top)) printf("���ٳɹ���\n");break;
			case 3:if(clear_stack(top)) printf("��ճɹ�!\n");break;
			case 4:if(if_empty(top)) printf("��ǰջ�գ�\n");else printf("��ǰջ�ǿգ�\n");break;
			case 5:printf("�������ݣ�");scanf("%d",&e);if(in_stack(top,e)) printf("��ջ�ɹ���\n");break;
			case 6:if(out_stack(top,&e)) printf("��ջԪ��Ϊ��%d\n",e);break;
			case 7:if(gettop(top,&e)) printf("ջ��Ԫ��Ϊ��%d\n",e);break;
			case 8:print_stack(top);break;
	 	}
	}
	 return 1;
}
