#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
#define Max 1000

typedef struct StackNode{
	int data;
	struct StackNode *next;
}StackNode,*LinkStack;

//*链栈的初始化*//
int re_stack(LinkStack &S)
{
	S=NULL;
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
	p=new StackNode;// 分配空间 
	
	p->data=e;
	p->next=S;
	S=p;
	return 1;
} 

//*链栈的出栈*//
int out_stack(LinkStack &S)
{
	LinkStack p;
	int e;
	if(if_empty(S))
	{
		printf("当前栈空！！\n");
		return 0;
	}
	p=S;
	e=S->data;
	S=S->next;
	free(p);
	return e;	
}

/*字符到数字的转换*/ 
int char_int(char c)
{
	int n;
	if(c<=57) n=(int)c-48;//c字符在'0'~'9'范围时转换成数字0~9 
	else n=(int)c-55;//c字符在'A'~...范围时转换为10~... 
	return n;
}

/*数字到字符的转换*/
char int_char(int n)
{
	char c;
	if(n<9) c=(char)(n+48);//n小于9时转换成字符 
	else c=(char)(n+55);//n大于10时转化为字母 
	return c;
 } 
 

 
/*任意进制转10进制*/
int in10(char c[],int f)
{
	int sum=0,i=0,j;
	
	while(c[i]!='\0')
	{
		j=char_int(c[i]);
		if(j>=f) 
		{
			printf("输入错误！\n");
			return 0;
		}
		sum=sum*f+j;
		i++;
	}
	return sum;
		
} 

/*十进制转任意进制*/

int out10(LinkStack &S,int sum,int h)
{
	while(sum)
	{
		in_stack(S,sum%h);//入栈转换为目标进制 
		sum=sum/h;
	}	
} 

/*输出*/ 
int printstack(LinkStack &S,char c[],int f,int h)
{
	printf("%s(%d)的%d进制数为：",c,f,h);
	while(S!=NULL)
	printf("%c",int_char(out_stack(S)));
	printf("(%d)\n",h);
}
/*主函数*/ 
int main()
{
	LinkStack top;
	re_stack(top);//初始化 
	char str[Max];
	int sum,f,h;//f为输入数值的进制，h为要转换的进制 
	while(1)
	{ 
	printf("请输入任意进制数：");
	scanf("%s",str);
	printf("========================\n1.退出\n2.二进制\n3.三进制\n4.四进制\n....\nn.n进制\n");
	printf("请选择已输入数的进制：");
	scanf("%d",&f);
	if(f==1) return 0;
	else if(f<1)
	{
		printf("输入错误！\n");
		continue;
	}
	
	sum=in10(str,f);//获取十进制数 
	
	printf("========================\n1.退出\n2.二进制\n3.三进制\n4.四进制\n....\nn.n进制\n");
	printf("请选择要转换的进制：");
	scanf("%d",&h);
	
	if(h==1) return 0;
	else if(h<1)
	{
		printf("输入错误！\n");
		continue;
	}
	
	out10(top,sum,h);
	printf("========================\n");
	printstack(top,str,f,h);//输出结果 
	}
	return 1;
}
