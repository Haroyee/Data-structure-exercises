#include<stdio.h>
#include<string.h>
#include<malloc.h> 

typedef struct StackNode{
	char c;
	struct StackNode *next;
}StackNode,*LinkStack;
/*��ʼ��*/ 
int re_stack(LinkStack &S)
{
	S=NULL;
	return 1;
}
/*��ջ */
int in_stack(LinkStack &S,char e)
{
	LinkStack p;
	p=new StackNode;/*�����½ڵ�*/ 
	
	p->c=e;
	p->next=S;
	S=p;
	return 1;
} 
/*��ջ*/ 
int out_stack(LinkStack &S,char *e)
{
	LinkStack p;
	
	p=S;
	* e=S->c;
	S=S->next;
	free(p);//�ͷſռ� 
	return 1;	
}
/*������*/ 
int main(){
	char c[100],a[100],e;
	int i,longth;
	LinkStack top;
	re_stack(top);
	printf("�������ַ�����");
	scanf("%s",c);
	
	longth=strlen(c);
	for(i=0;i<longth;i++)//�������ַ���ջ
	in_stack(top,c[i]); 
	i=0;
	while(top!=NULL){//���ַ�ȫ����ջ 
		out_stack(top,&e);
		a[i]=e;
		i++;
	}
	if(strcmp(c,a)) printf("�ǻ��Ľṹ��\n");//����ջ����ջ��ͬ��Ϊ���Ľṹ 
	else printf("�ǻ��Ľṹ��\n");
	
	return 0;
	
} 
 
