#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define M 255
int i,j; 
int next[M+1];
typedef struct{
	int ch[M+1];
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
	int s[M],t[M];
	int m,n;
	
	printf("��������������"); 
	scanf("%d",&n);
	printf("������ÿ�������е��ǣ�");
	for(i=0;i<n;i++) 
	scanf("%d",&s[i]);
	
	printf("������ҪѰ�ҵ�������");
	scanf("%d",&m);
	if(m>n) {printf("�������");return 0; 
	}
	printf("��������ÿ�������е��ǣ�");
	for(i=0;i<m;i++) 
	scanf("%d",&t[i]);
	
	S.length=n;
	for(i=1;i<=S.length;i++) S.ch[i]=s[i-1];
	T.length=m;
	for(j=1;j<=T.length;j++) T.ch[j]=t[j-1];
	get_next(T);

	if((n =Index_KMP(S,T,1))>0) printf("ȷ��������ֵΪ��%d %d",n,n-1+T.length);
	else printf("�����ڣ�\n");
	
	
	
	return 0;
}
