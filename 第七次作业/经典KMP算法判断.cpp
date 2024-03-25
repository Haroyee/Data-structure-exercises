#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define M 255
int i,j; 
int next[M+1];
typedef struct{
	char ch[M+1];
	int length;
}SString;

/* KMP�㷨*/ 

int Index_KMP(SString S,SString T,int pos)
{
	i=pos;j=1;
	while(i<=S.length&&j<=T.length)
	{
		if(j==0||S.ch[i]==T.ch[j]) {++i;++j;}
		else {j= next[j];}
	}
	if(j>T.length) return i-T.length;
	else return -1;
}


/*��ȡnextֵ*/ 

void get_next(SString T)
{
	i=1;next[1]=0;j=0;
	while(i<T.length)
	{
		if(j==0||T.ch[i]==T.ch[j]) next[++i]=++j;
		else j=next[j];
	}
}

int main()
{
	SString S,T;
	char s[M],t[M];
	printf("������������");
	scanf("%s",&s);
	printf("�������Ӵ���");
	scanf("%s",&t);
	S.length=strlen(s);
	for(i=1;i<=S.length;i++) S.ch[i]=s[i-1];
	T.length=strlen(t);
	for(j=1;j<=T.length;j++) T.ch[j]=t[j-1];
	get_next(T);
	
	if(int n =Index_KMP(S,T,1)) printf("KMP������ɣ�λ��Ϊ%d-%d\n",n,n+T.length-1);
	else printf("KMP�����������\n");
	
	
	
	return 0;
}
