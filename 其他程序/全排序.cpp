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

//ֱ�Ӳ��뷨 
void Insert(SqList &L)
{//��˳���Lֱ����ֱ�Ӳ������� 
	int i,j;
	for(i=2;i<=L.length;++i)
		if(L.r[i].key<L.r[i-1].key)              	 //"<"���轫r[i]���������ӱ� 
		{
			L.r[0]=L.r[i];						  	//��������ļ�¼�浽�������� 
			L.r[i]=L.r[i-1];						//r[i-1]���� 
			for(j=i-2;L.r[0].key<L.r[j].key;--j)
				L.r[j+i]=L.r[j];
			L.r[j+1]=L.r[0];
		}
}
//�۰���뷨 
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

//ϣ������ 
void ShellInsert(SqList &L,int dk)
{//��˳���L��һ��������dk��ϣ����������
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
{//����������dt[0...t-1]��˳���L��t��ϣ������
	int k;
	 for(k=0;k<t;++k)
	  ShellInsert(L,dt[k]) ;	
}

int main()
{
	
	return 0;
 } 
