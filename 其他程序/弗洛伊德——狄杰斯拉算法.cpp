#include<iostream>
#define MVNum 100       //最大顶点数 
#define MaxInt 32767   //极大值，即无限 
#define PrintLine printf("\n")//换行 
using namespace std;
int S[MVNum],D[MVNum],Path[MVNum];
int Arc[MVNum][MVNum];

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
void Dijestra(AMGraph &G,int v0)
{
	int i,v,w,min;
	int n = G.vexnum; //获取节点个数
	for(i = 0; i < n; i ++ )
	{
		S[i] = false;
		D[i] = G.arcs[v0][i];
		if(D[i] < MaxInt) Path[i] = i;
		else Path[i] = 0;
	} 
	S[v0] = true;
	D[v0] = 0;
	for(i = 0; i < n; i++)
	{
		min = MaxInt;
		for(w = 0; w < n; w++)
		{
			if(!S[w] && D[w] < min)
			{
				v = w; 
				min = D[w];
			}
			S[v] = true;
			for(w = 0; w < n; w++)
				if(!S[w] && (D[v] + G.arcs[v][w] < D[w]))
				{
					D[w] = D[v] + G.arcs[v][w];
					Path[w] = G.vexs[v];
				}
		}
		
	}
}



int LoadFile(AMGraph &G)
{
	int count = 0;
	char Filename[] = "PublicTransportNetwork.txt";
	int n = 5;
	FILE *File =fopen(Filename,"r");
	return 0;
}

int main()
{
	int i,j;
	AMGraph G;
	CreateUDM(G);
	Dijestra(G,0);
	for(int i =0; i<G.vexnum;i++)
	{
		j = i;
		printf("v%d:",i);
		printf("minDistance=%d",D[i]);
		printf("minPath:v%d",i);
		while(Path[j]!=0&&Path[j]!=-1)
		{
			printf("-v%d",Path[j]);
			j = Path[j];
		}
		if (Path[j]==-1||Path[j]==0) printf("-v0\n");
		
	}
	return 0;

}
/*
5 7
1
2
3
4
5
1 2 10
1 3 3
1 4 20
2 4 5
3 2 2
3 5 15
4 5 11
*/

		
		
	
