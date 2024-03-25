#include<stdio.h>
#include<stdlib.h>

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

/*��ջ��ջ���ж�*/
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

 

/*ջ�ı���*/
int print_stack(LinkStack &S)
{
	if(if_empty(S))
	{
		printf("��ǰջ�գ���\n");
		return 0;
	}
	LinkStack p=S;
	printf("�Ҵ����У�");
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
	return 1;	
} 

/*���ֺ���*/
int GoOut(LinkStack &A,LinkStack &B,int i,int j)//AΪ�����Ա��ջ��BΪ��ջ,iΪ��Ա������jΪ�������� 
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
				printf("��%2d�γ��ֵ�Ϊ��%d\n",l,data); 
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
	int i;//������
     int N;//���������
     int k;//��������
     printf("���������������");
     scanf("%d",&N);
     printf("������������룺");
     scanf("%d",&k);
     
     LinkStack A,B;
     re_stack(A);
     re_stack(B);
     
     for(i=N;i>=1;i--)
     in_stack(A,i);
     
     GoOut(A,B,N,k);
     
     print_stack(A);  
}
