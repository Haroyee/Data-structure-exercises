。、、、、#include<stdio.h> 
#include<stdlib.h>
#define Maxsize 100


typedef int SElemType;
/*定义双栈类型*/ 
typedef struct{
	int top[2],bot[2];
	SElemType *V;
	int m;
}DblStack; 

/*双栈初始化*/ 
int re_creatStack(DblStack &S)
{
	S.V= new int[Maxsize];
	if(S.V==NULL){
		printf("初始化失败！\n"); 
		return 0;
	}//判断是否空间分配成功 
	S.top[0]=S.bot[0];
	S.top[1]=S.bot[1];
	S.m=Maxsize;//设定大小 
	return 1;
}

/*入栈*/
int in_stack(DblStack &S,int a,int n)
{
	
	return 1;
} 
/*出栈*/
int out_stack(DblStack &S,int &a,int n)
{
	
} 
int main(){
	return 1;
}
