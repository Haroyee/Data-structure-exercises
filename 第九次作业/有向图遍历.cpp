#include <iostream>
#define MVNum 100       //最大顶点数 
#define MaxInt 32767   //极大值，即无限 
#define PrintLine printf("\n")//换行 
using namespace std;
//定义辅助结构体类型
typedef struct Vexs{
	char vex;
	int flag;
}Vex[MVNum];

//判断是否遍历完
int IsAllPrint(Vex V,int n)
{
	int flag = 1;
	for(int i = 0;i<n;i++)
	{
		if(V[i].flag==1) return 0;
	}
	return 1;
} 

// 邻接矩阵储存图
typedef struct{
	char vexs[MVNum];    //顶点表 
	int arcs[MVNum][MVNum];  //邻接矩阵 
	int vexnum,arcnum; //图的当前点数和边数 
}AMGraph;

//返回顶点v在图中顶点表的位置 (邻接矩阵)
int LocateVex1(AMGraph &G,char v)
{
	for(int i=0;i<G.vexnum;++i)
		if(G.vexs[i]==v)
			return i;
	 
}

//创建邻接矩阵 
void CreateUDM(AMGraph &G)  
{
	char v1,v2;
	int w,i,j,k;
	cout<<"请输入总定点数与总边数："<<endl;
	cin>>G.vexnum>>G.arcnum;
	for(i=0;i<G.vexnum;++i)
	{
		cout<<"请输入第"<<i+1<<"个点"<<endl; 
		cin>>G.vexs[i];
	}
	
	for(i=0;i<G.vexnum;++i)//初始化矩阵，使权值全为最大值 
		for(int j=0;j<G.vexnum;++j)
			G.arcs[i][j]=MaxInt;
			
	for(k=0;k<G.arcnum;++k)
	{
		cout<<"请输入两个顶点以及它们连成边的权值："<<endl;
		cin>>v1>>v2>>w;
		i = LocateVex1(G,v1);j=LocateVex1(G,v2); //返回顶点的位置 
		G.arcs[i][j]=w;    //赋予权值 
		 
	}
}

//输出矩阵 
void PrintUDM(AMGraph &G)
{
	for(int i=0;i<G.vexnum;i++)
		{
			for(int j=0;j<G.vexnum;j++)
			{
				if(G.arcs[i][j]==MaxInt)
				printf("  ∞");
				else
				printf("%3d ",G.arcs[i][j]);
			}
			cout<<endl;
		}
}

//遍历图（邻接矩阵）
void BFS(AMGraph &G)
{
	Vex V;
	
	for(int i=0;i<G.vexnum;i++)//初始化辅助结构体 
	{
		V[i].vex=G.vexs[i];
		V[i].flag=1;//将每个节点的flag置为0 
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
