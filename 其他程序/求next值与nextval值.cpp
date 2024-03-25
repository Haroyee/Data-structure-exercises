#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Getnext(char *str,int *next)
{
	int i=1;
	next[1]=0;
	int j=0;
	while(i<strlen(str))
	{
		if(j==0||str[i]==str[j])
		next[++i]=++j;
		else 
		j=next[j];
	}
}
void Getnextval(char *str,int *next,int *nextval)
{
	int i=1;
	nextval[1]=0;
	int j=next[2];
	while(i<strlen(str))
	{
		if(str[i]==str[j])
		j=next[j];
		else
		{
			nextval[i]=next[j];
			i++;
		}
	}
}

int main()
{
	char str[1000];
	printf("ÇëÊäÈë×Ö·û´®£º");
	str[0]='0';
	scanf("%s",&str[1]);
	int longth = strlen(str);
	int next[1000],nextval[1000];
	Getnext(str,next);
	Getnextval(str,next,nextval);
	printf("next=");
	for(int i=1;i<longth;i++)	printf("%d ",next[i]);
	printf("\nnextval=");
	for(int j=1;j<longth;j++)	printf("%d ",nextval[j]);
	
	
	
	
	
	
	
	
	
 } 
