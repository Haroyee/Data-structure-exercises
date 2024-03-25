#include<iostream>
#define Maxsize 100
using namespace std;

typedef struct{
	int key;
	int otherinfo;
}Redtype;

typedef struct {
	Redtype r[Maxsize+1];
	int length;
}SqList;

//直接插入法 
void Insert(SqList &L)
{//对顺序表L直接做直接插入排序 
	int i,j;
	for(i=2;i<=L.length;++i)
		if(L.r[i].key<L.r[i-1].key)              	 //"<"，需将r[i]插入有序子表 
		{
			L.r[0]=L.r[i];						  	//将待插入的记录存到监视哨中 
			L.r[i]=L.r[i-1];						//r[i-1]后移 
			for(j=i-2;L.r[0].key<L.r[j].key;--j)
				L.r[j+i]=L.r[j];
			L.r[j+1]=L.r[0];
		}
}
//折半插入法 
void BInsertSort(SqList &L)
{
	int low,high,m,i,j;
	for(i=2;i<=L.length;++i)
	{
		L.r[0]=L.r[i];
		low = 1;high= i -1;
		while(low<=high)
		{
			m=(low + high)/2;
			if(L.r[0].key<L.r[m].key) high = m-1;
			else low = m+1;
		}
		for(j=i-1;j<=high+1;--j) L.r[j+1]=L.r[j];
		L.r[high+1]=L.r[0];
	 } 
}

//希尔排序 
void ShellInsert(SqList &L,int dk)
{//对顺序表L做一趟增量是dk的希尔插入排序
	int i,j;
	for(i=dk+1;i<=L.length;++i)
		if(L.r[i].key<L.r[i-dk].key)
		{
			L.r[0]=L.r[i];
			for(j=i-dk;j>0&&L.r[0].key;j-=dk) 
				L.r[j+dk]=L.r[j];
			L.r[j+dk]=L.r[0];
		}
}

void ShellSort(SqList &L,int dt[],int t)
{//按增量序列dt[0...t-1]对顺序表L作t趟希尔排序
	int k;
	 for(k=0;k<t;++k)
	  ShellInsert(L,dt[k]) ;	
}

int main()
{
	
	return 0;
 } 
