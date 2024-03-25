/*示例
****哈夫曼编码****
8
27
4
87
21
2
21
1
25
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	unsigned int weight; //用来存储各个结点的权值
	unsigned int parent,LChild,RChild; //指向双亲、孩子结点的指针
}HTNode, *HuffmanTree; //动态分配数组，存储哈夫曼树
typedef char *HuffmanCode; //动态分配数组，存储哈夫曼树
///选择两个 parent 为 0,且 weight 最小的结点 s1 和 s2
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
			if((*ht)[i].weight < (*ht)[min].weight)
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
///构造哈夫曼树 ht,w 存放已知 n 个权值
void CrtHuffmanTree(HuffmanTree *ht,int *w,int n)
{
	int m,i,s1,s2;
	m=2*n-1; //总共的结点数
	*ht=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(i=1; i<=n; i++) //1-n 号存放叶子结点，初始化
	{
		(*ht)[i].weight=w[i];
		(*ht)[i].LChild=0;
		(*ht)[i].parent=0;
		(*ht)[i].RChild=0;
	}
	for(i=n+1; i<=m; i++) //非叶子结点的初始化
	{
		(*ht)[i].weight=0;
		(*ht)[i].LChild=0;
		(*ht)[i].parent=0;
		(*ht)[i].RChild=0;
	}
	printf("\n哈夫曼树为: \n");
	for(i=n+1; i<=m; i++) //创建非叶子结点，建哈夫曼树
	{ /*在(*ht)[1]~(*ht)[i-1]的范围内选择两个 parent 为 0 且 weight 最小的结点，其序号分别赋
	值给 s1、s2*/
		Select(ht,i-1,&s1,&s2);
		(*ht)[s1].parent = i;
		(*ht)[s2].parent = i;
		(*ht)[i].LChild = s1;
		(*ht)[i].RChild = s2;
		(*ht)[i].weight = (*ht)[s1].weight + (*ht)[s2].weight;
		printf("%d (%d, %d)\n",(*ht)[i].weight,(*ht)[s1].weight,(*ht)[s2].weight);
	}
	printf("\n");
	}
//从叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码
void CrtHuffmanCode(HuffmanTree *ht, HuffmanCode *hc, int n)
{
	char *cd; //定义的存放编码的空间
	int a[100];
	int i,start,p,w=0;
	unsigned int c;
	hc=(HuffmanCode *)malloc((n+1)*sizeof(char *)); //分配 n 个编码的头指针
	cd=(char *)malloc(n*sizeof(char)); //分配求当前编码的工作空间
	cd[n-1]='\0'; //从右向左逐位存放编码，首先存放编码结束符
	for(i=1; i<=n; i++) //求 n 个叶子结点对应的哈夫曼编码
	{
		a[i]=0;
		start=n-1; //起始指针位置在最右边
		for(c=i,p=(*ht)[i].parent; p!=0; c=p,p=(*ht)[p].parent) //从叶子到根结点求编码
		{
			if( (*ht)[p].LChild==c)
			{
				cd[--start]='1'; //左分支标 1
				a[i]++;
			}
			else
			{
				cd[--start]='0'; //右分支标 0
				a[i]++;
			}
		}
		hc[i]=(char *)malloc((n-start)*sizeof(char)); //为第 i 个编码分配空间
		strcpy(hc[i],&cd[start]); //将 cd 复制编码到 hc
	}
	free(cd);
	for(i=1; i<=n; i++)
	printf(" 权值为%d 的哈夫曼编码为：%s\n",(*ht)[i].weight,hc[i]);
	for(i=1; i<=n; i++)
		w+=(*ht)[i].weight*a[i];
	printf(" 带权路径为：%d\n",w);
}
int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *w,i,n,wei;
	printf("**哈夫曼编码**\n" );
	printf("请输入结点个数：" );
	scanf("%d",&n);
	w=(int *)malloc((n+1)*sizeof(int));
	printf("\n 输入这%d 个元素的权值:\n",n);
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
	return 0;
}

