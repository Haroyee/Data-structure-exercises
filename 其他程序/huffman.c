/*ʾ�� 
****����������****
�������������8
������8��Ԫ�ص�Ȩֵ����Ϊ���Σ���
1:27
2:4
3:87
4:21
5:2
6:21
7:1
8:25

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  unsigned int weight;  //�����洢��������Ȩֵ 
  unsigned int parent,LChild,RChild;  //ָ��˫�ס����ӽ���ָ�� 
} HTNode, *HuffmanTree;  //��̬�������飬�洢�������� 

struct string{
		char e;
		int count;
	}Str[100];

typedef char *HuffmanCode;  //��̬�������飬�洢��������

///ѡ������parentΪ0,��weight��С�Ľ��s1��s2 
void Select(HuffmanTree *ht,int n,int *s1,int *s2)
{
 int i,min;
 for(i=1; i<=n; i++)
 {
   if((*ht)[i].parent==0)
   {
       min=i;
       break;
   }
 }
 for(i=1; i<=n; i++)
 {
    if((*ht)[i].parent==0)
	{
      if((*ht)[i].weight<(*ht)[min].weight)
      min=i;
	}
 }
 *s1=min;

 for(i=1; i<=n; i++)
 {
    if((*ht)[i].parent==0 && i!=(*s1))
	{
      min=i;
      break;
	}
 }
 for(i=1; i<=n; i++)
 {
    if((*ht)[i].parent==0 && i!=(*s1))
	{
      if((*ht)[i].weight<(*ht)[min].weight) 
		  min=i;
	}
 }
 *s2=min;
}

///�����������ht,w�����֪n��Ȩֵ 
void CrtHuffmanTree(HuffmanTree *ht,int *w,int n)
{
 int m,i,s1,s2;
 m=2*n-1;    //�ܹ��Ľ���� 
 *ht=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
 for(i=1; i<=n; i++)  //1-n�Ŵ��Ҷ�ӽ�㣬��ʼ�� 
 {
  (*ht)[i].weight=w[i];
  (*ht)[i].LChild=0;
  (*ht)[i].parent=0;
  (*ht)[i].RChild=0;
 }
 for(i=n+1; i<=m; i++)   //��Ҷ�ӽ��ĳ�ʼ��
 {
  (*ht)[i].weight=0;
  (*ht)[i].LChild=0;
  (*ht)[i].parent=0;
  (*ht)[i].RChild=0;
 } 

 printf("��������Ϊ: \n");

 for(i=n+1; i<=m; i++)   //������Ҷ�ӽ�㣬����������
 { /*��(*ht)[1]~(*ht)[i-1]�ķ�Χ��ѡ������parentΪ0��weight��С�Ľ�㣬����ŷֱ�ֵ��s1��s2*/
   Select(ht,i-1,&s1,&s2);
  (*ht)[s1].parent=i;
  (*ht)[s2].parent=i;
  (*ht)[i].LChild=s1;
  (*ht)[i].RChild=s2;
  (*ht)[i].weight=(*ht)[s1].weight+(*ht)[s2].weight;
  printf("%d (%d, %d)\n",(*ht)[i].weight,(*ht)[s1].weight,(*ht)[s2].weight);
 }
 printf("\n");
} 


//��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ���Ӧ�Ĺ���������
void CrtHuffmanCode(HuffmanTree *ht, HuffmanCode *hc, int n)
{
 char *cd;   //����Ĵ�ű���Ŀռ�
 int a[100];
 int i,start,p,w=0;
 unsigned int c;
 hc=(HuffmanCode *)malloc((n+1)*sizeof(char *));  //����n�������ͷָ��
 cd=(char *)malloc(n*sizeof(char));  //������ǰ����Ĺ����ռ�
 cd[n-1]='\0';  //����������λ��ű��룬���ȴ�ű��������

 for(i=1; i<=n; i++)  //��n��Ҷ�ӽ���Ӧ�Ĺ���������
 {
  a[i]=0;
  start=n-1;  //��ʼָ��λ�������ұ�
  for(c=i,p=(*ht)[i].parent; p!=0; c=p,p=(*ht)[p].parent)  //��Ҷ�ӵ�����������
  {
	
    if( (*ht)[p].LChild==c)
	{
		cd[--start]='1';  //���֧��1
		a[i]++;
	}
    else 
	{
		cd[--start]='0';  //�ҷ�֧��0
		a[i]++;
	}
  }
  hc[i]=(char *)malloc((n-start)*sizeof(char));  //Ϊ��i���������ռ�
  strcpy(hc[i],&cd[start]);    //��cd���Ʊ��뵽hc
 }
 free(cd);
 for(i=1; i<=n; i++)
  printf(" ȨֵΪ%d�Ĺ���������Ϊ��%s\n",(*ht)[i].weight,hc[i]);
 for(i=1; i<=n; i++)
    w+=(*ht)[i].weight*a[i];
 printf(" ��Ȩ·��Ϊ��%d\n",w);

}

int check(struct string *str,char )
void meus(int n,)
{
	HuffmanTree HT;
 	HuffmanCode HC;
 	int *w,i,n,wei;
 	printf("**����������**\n" );
 	printf("�������������" );
 	scanf("%d",&n);
	 w=(int *)malloc((n+1)*sizeof(int)); 
	 printf("\n������%d��Ԫ�ص�Ȩֵ:\n",n); 

 	for(i=1; i<=n; i++)
 	{ 
  		printf("%d: ",i); 
  		fflush(stdin);
  		scanf("%d",&wei);
 	 	w[i]=wei;
 	}
 	CrtHuffmanTree(&HT,w,n);
 	CrtHuffmanCode(&HT,&HC,n);
 
 	system("pause");
}

int intput()
{
	
	char s[100]
 	int c[100]
 	int a,longth;
 	scanf("%d",&a);
 	for(i=0;i<a;i++)
 	{
 		scanf("%s",s);
 		longth = strlen(s);
 		Str[0].e = s[0];
 		for(j=1;j<longth;j++)
 		{
 			if()
		}
 	}
}
int main()
{
 
 


 
 return 0;
}

