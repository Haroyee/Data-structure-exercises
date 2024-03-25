#include <iostream>
#define MVNum 100       //��󶥵��� 
#define MaxInt 32767   //����ֵ�������� 
#define PrintLine printf("\n")//���� 
using namespace std;
//���帨���ṹ������
typedef struct Vexs{
	char vex;
	int flag;
}Vex[MVNum];

//�ж��Ƿ������
int IsAllPrint(Vex V,int n)
{
	int flag = 1;
	for(int i = 0;i<n;i++)
	{
		if(V[i].flag==1) return 0;
	}
	return 1;
} 

// �ڽӾ��󴢴�ͼ
typedef struct{
	char vexs[MVNum];    //����� 
	int arcs[MVNum][MVNum];  //�ڽӾ��� 
	int vexnum,arcnum; //ͼ�ĵ�ǰ�����ͱ��� 
}AMGraph;

//���ض���v��ͼ�ж�����λ�� (�ڽӾ���)
int LocateVex1(AMGraph &G,char v)
{
	for(int i=0;i<G.vexnum;++i)
		if(G.vexs[i]==v)
			return i;
	 
}

//�����ڽӾ��� 
void CreateUDM(AMGraph &G)  
{
	char v1,v2;
	int w,i,j,k;
	cout<<"�������ܶ��������ܱ�����"<<endl;
	cin>>G.vexnum>>G.arcnum;
	for(i=0;i<G.vexnum;++i)
	{
		cout<<"�������"<<i+1<<"����"<<endl; 
		cin>>G.vexs[i];
	}
	
	for(i=0;i<G.vexnum;++i)//��ʼ������ʹȨֵȫΪ���ֵ 
		for(int j=0;j<G.vexnum;++j)
			G.arcs[i][j]=MaxInt;
			
	for(k=0;k<G.arcnum;++k)
	{
		cout<<"���������������Լ��������ɱߵ�Ȩֵ��"<<endl;
		cin>>v1>>v2>>w;
		i = LocateVex1(G,v1);j=LocateVex1(G,v2); //���ض����λ�� 
		G.arcs[i][j]=w;    //����Ȩֵ 
		 
	}
}

//������� 
void PrintUDM(AMGraph &G)
{
	for(int i=0;i<G.vexnum;i++)
		{
			for(int j=0;j<G.vexnum;j++)
			{
				if(G.arcs[i][j]==MaxInt)
				printf("  ��");
				else
				printf("%3d ",G.arcs[i][j]);
			}
			cout<<endl;
		}
}

//����ͼ���ڽӾ���
void BFS(AMGraph &G)
{
	Vex V;
	
	for(int i=0;i<G.vexnum;i++)//��ʼ�������ṹ�� 
	{
		V[i].vex=G.vexs[i];
		V[i].flag=1;//��ÿ���ڵ��flag��Ϊ0 
	}
	for(int i=0;i<G.vexnum;i++)
	{
		if(V[i].flag==1) 
		{
			cout<<G.vexs[i]<<" ";
			V[i].flag=0;
		}
		for(int j=0;j<G.vexnum;j++)
		{
			if(G.arcs[i][j]!=MaxInt && V[j].flag==1)
			{
				cout<<G.vexs[j]<<" ";
				V[j].flag=0;
				i = j;
				break;
			}
		
		}
		if(IsAllPrint(V,G.vexnum)) break;
	}
} 


int main()
{
	AMGraph G;
	CreateUDM(G);
	PrintLine;
	PrintUDM(G);
	PrintLine;
	BFS(G);
	return 0;	
 } 
/*
1
10 22
1
2
3
4
5
6
7
8
9
0
1 7 1 
1 9 1
2 3 1
2 7 1
3 4 1 
3 8 1 
4 5 1 
4 9 1 
5 6 1 
5 0 1 
6 1 1 
6 2 1 
7 3 1 
7 0 1 
8 1 1 
8 4 1 
8 9 1 
9 5 1 
9 7 1 
9 0 1 
0 1 1 
0 6 1
*/
