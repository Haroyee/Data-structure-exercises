����������#include<stdio.h> 
#include<stdlib.h>
#define Maxsize 100


typedef int SElemType;
/*����˫ջ����*/ 
typedef struct{
	int top[2],bot[2];
	SElemType *V;
	int m;
}DblStack; 

/*˫ջ��ʼ��*/ 
int re_creatStack(DblStack &S)
{
	S.V= new int[Maxsize];
	if(S.V==NULL){
		printf("��ʼ��ʧ�ܣ�\n"); 
		return 0;
	}//�ж��Ƿ�ռ����ɹ� 
	S.top[0]=S.bot[0];
	S.top[1]=S.bot[1];
	S.m=Maxsize;//�趨��С 
	return 1;
}

/*��ջ*/
int in_stack(DblStack &S,int a,int n)
{
	
	return 1;
} 
/*��ջ*/
int out_stack(DblStack &S,int &a,int n)
{
	
} 
int main(){
	return 1;
}
