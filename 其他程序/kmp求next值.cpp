//abcaabbabcab
//011122312345
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int next(char *a,int *n)
{
	int i=1,j=0;
	n[1]=0;
	while(i<strlen(a))
	{
		if(j==0||a[i]==a[j])
		{
			
			n[++i]=++j;
		}
		else j=n[j];
		
	} 
	return 1;
}
int main()
{
	char s[100000];
	int n[100000];
	printf("ÇëÊäÈëÒ»¸ö×Ö·û´®£º");
	scanf("%s",&s);
	next(s,n);
	for(int i=1;i<=strlen(s);i++)
	{
		printf("%d ",n[i]);
	}
}
