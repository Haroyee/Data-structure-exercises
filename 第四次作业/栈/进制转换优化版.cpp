#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
#define Max 1000

typedef struct StackNode{
	int data;
	struct StackNode *next;
}StackNode,*LinkStack;

//*��ջ�ĳ�ʼ��*//
int re_stack(LinkStack &S)
{
	S=NULL;
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
	p=new StackNode;// ����ռ� 
	
	p->data=e;
	p->next=S;
	S=p;
	return 1;
} 

//*��ջ�ĳ�ջ*//
int out_stack(LinkStack &S)
{
	LinkStack p;
	int e;
	if(if_empty(S))
	{
		printf("��ǰջ�գ���\n");
		return 0;
	}
	p=S;
	e=S->data;
	S=S->next;
	free(p);
	return e;	
}

/*�ַ������ֵ�ת��*/ 
int char_int(char c)
{
	int n;
	if(c<=57) n=(int)c-48;//c�ַ���'0'~'9'��Χʱת��������0~9 
	else n=(int)c-55;//c�ַ���'A'~...��Χʱת��Ϊ10~... 
	return n;
}

/*���ֵ��ַ���ת��*/
char int_char(int n)
{
	char c;
	if(n<9) c=(char)(n+48);//nС��9ʱת�����ַ� 
	else c=(char)(n+55);//n����10ʱת��Ϊ��ĸ 
	return c;
 } 
 

 
/*�������ת10����*/
int in10(char c[],int f)
{
	int sum=0,i=0,j;
	
	while(c[i]!='\0')
	{
		j=char_int(c[i]);
		if(j>=f) 
		{
			printf("�������\n");
			return 0;
		}
		sum=sum*f+j;
		i++;
	}
	return sum;
		
} 

/*ʮ����ת�������*/

int out10(LinkStack &S,int sum,int h)
{
	while(sum)
	{
		in_stack(S,sum%h);//��ջת��ΪĿ����� 
		sum=sum/h;
	}	
} 

/*���*/ 
int printstack(LinkStack &S,char c[],int f,int h)
{
	printf("%s(%d)��%d������Ϊ��",c,f,h);
	while(S!=NULL)
	printf("%c",int_char(out_stack(S)));
	printf("(%d)\n",h);
}
/*������*/ 
int main()
{
	LinkStack top;
	re_stack(top);//��ʼ�� 
	char str[Max];
	int sum,f,h;//fΪ������ֵ�Ľ��ƣ�hΪҪת���Ľ��� 
	while(1)
	{ 
	printf("�����������������");
	scanf("%s",str);
	printf("========================\n1.�˳�\n2.������\n3.������\n4.�Ľ���\n....\nn.n����\n");
	printf("��ѡ�����������Ľ��ƣ�");
	scanf("%d",&f);
	if(f==1) return 0;
	else if(f<1)
	{
		printf("�������\n");
		continue;
	}
	
	sum=in10(str,f);//��ȡʮ������ 
	
	printf("========================\n1.�˳�\n2.������\n3.������\n4.�Ľ���\n....\nn.n����\n");
	printf("��ѡ��Ҫת���Ľ��ƣ�");
	scanf("%d",&h);
	
	if(h==1) return 0;
	else if(h<1)
	{
		printf("�������\n");
		continue;
	}
	
	out10(top,sum,h);
	printf("========================\n");
	printstack(top,str,f,h);//������ 
	}
	return 1;
}
