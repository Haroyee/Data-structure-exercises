#include<stdio.h>
#include<string.h>
#include<malloc.h> 

typedef struct StackNode{
	char c;
	struct StackNode *next;
}StackNode,*LinkStack;
/*初始化*/ 
int re_stack(LinkStack &S)
{
	S=NULL;
	return 1;
}
/*进栈 */
int in_stack(LinkStack &S,char e)
{
	LinkStack p;
	p=new StackNode;/*建立新节点*/ 
	
	p->c=e;
	p->next=S;
	S=p;
	return 1;
} 
/*出栈*/ 
int out_stack(LinkStack &S,char *e)
{
	LinkStack p;
	
	p=S;
	* e=S->c;
	S=S->next;
	free(p);//释放空间 
	return 1;	
}
/*主函数*/ 
int main(){
	char c[100],a[100],e;
	int i,longth;
	LinkStack top;
	re_stack(top);
	printf("请输入字符串：");
	scanf("%s",c);
	
	longth=strlen(c);
	for(i=0;i<longth;i++)//将输入字符入栈
	in_stack(top,c[i]); 
	i=0;
	while(top!=NULL){//将字符全部出栈 
		out_stack(top,&e);
		a[i]=e;
		i++;
	}
	if(strcmp(c,a)) printf("非回文结构！\n");//若出栈与入栈相同则为回文结构 
	else printf("是回文结构！\n");
	
	return 0;
	
} 
 
