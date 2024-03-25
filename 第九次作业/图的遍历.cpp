#include<iostream>
#include<stack>
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
		G.arcs[j][i]=G.arcs[i][j];  //将其对称点赋予相同的权值 
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
void DFS(AMGraph &G)
{
	Vex V;
	stack<struct Vexs> S;
	int i,j;
	for(int i=0;i<G.vexnum;i++)//初始化辅助结构体 
	{
		V[i].vex=G.vexs[i];
		V[i].flag=1;//将每个节点的flag置为1
	}
	S.push(V[0]);
	cout<<V[0].vex<<" ";
	V[0].flag=0;
	for(i=0;i<G.vexnum;i++)
	{
		int tag = 1;
		for(j=0;j<G.vexnum;j++)
		{
			if(G.arcs[i][j]!=MaxInt&&V[j].flag==1)
			{
				cout<<V[j].vex<<" ";
				S.push(V[j]);
				V[j].flag = 0;
				i = j - 1;
				tag = 0;
				break;
			}
		}
		if(tag==1) 
		{
			i = LocateVex1(G,S.top().vex)-1;
			S.pop();
		}
		if(IsAllPrint(V,G.vexnum)) break;
	}
		
}
 

//邻接表储存图
typedef struct Arcnode{ //边结点 
	int adjvex;   //该边所指顶点位置 
	struct Arcnode *nextarc;  //指向下一条边的指针 
	int longth; //边的权值 
}ArcNode;

typedef struct Vnode{  //顶点信息 
	char data;         //顶点 
	ArcNode *firstarc;   //指向第一条依附该顶点的边的指针 
}VNode,AdjList[MVNum]; //AdjList表示邻接表类型

typedef struct{
	AdjList vertices;//定义邻接表 
	int vexnum,arcnum; //图的顶点数与边数 
}ALGraph; 
//返回顶点v在图的顶点表的位置 
int LocateVex2(ALGraph &G,char v)
{
	for(int i =0;i<G.vexnum;++i)
		if(G.vertices[i].data==v)
			return i;
} 
//创建邻接表
void CreateUDG(ALGraph &G)
{
	int i,j,k,w;
	char v1,v2;
	ArcNode *p1,*p2;
	cout<<"请输入顶点数与边数："<<endl;
	cin>>G.vexnum>>G.arcnum;
	for(i=0;i<G.vexnum;++i)
	{
		cout<<"请输入第"<<i+1<<"个顶点"<<endl;
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;  //初始化表头结点的指针域 
	 } 
	 for(k=0;k<G.arcnum;++k)
	 {
	 	cout<<"请输入两个顶点与所连成边的权值"<<endl;
		cin>>v1>>v2>>w; 
		i=LocateVex2(G,v1);j=LocateVex2(G,v2);
		
		p1 = new ArcNode;
		p1->adjvex=j;
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;
		G.vertices[i].firstarc->longth=w;
		
		//进行对称处理 
		p2 = new ArcNode;
		p2->adjvex=i;
		p2->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;
		G.vertices[j].firstarc->longth=w;
	} 
 }
//输出邻接表 
void PrintUDG(ALGraph &G)
{
	ArcNode *p;
	VNode *q;
	for(int i=0;i<G.vexnum;i++)
	{
		printf("%2c",G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while(p!=NULL)
		{
			printf("%2c",G.vertices[p->adjvex].data);
			p=p->nextarc;
		}
		printf("\n");	
	}
}
//邻接表遍历
void BFS(ALGraph &G,Vex V,int i)//i为节点位置 
{
	if(IsAllPrint(V,G.vexnum))return; 
	ArcNode *p=G.vertices[i].firstarc;
	if(V[i].flag==1)
	{
		cout<<G.vertices[i].data<<" ";
		V[i].flag=0;
	}
	while(p!=NULL)
	{
		if(V[p->adjvex].flag==1)
		{
			cout<<G.vertices[p->adjvex].data<<" ";
			V[p->adjvex].flag=0;
			BFS(G,V,p->adjvex);
		}
		p=p->nextarc;
		if(IsAllPrint(V,G.vexnum)) return;
		
	}
} 
void Menu()
{
	int choice;
	cout<<"================================"<<endl;
	cout<<"1.邻接矩阵创建图\n"<<"2.邻接表创建图\n";
	cout<<"================================"<<endl;
	cout<<"请输入你要进行的操作：" <<endl;
	cin>>choice;
	if(choice==1)
	{
		AMGraph G;
		CreateUDM(G);
		PrintLine;
		PrintUDM(G);
		PrintLine;
		DFS(G);
		
	}
	else if(choice==2)
	{
		ALGraph G;
		CreateUDG(G);
		PrintLine;
		PrintUDG(G);
		PrintLine;
		Vex V;
		for(int i=0;i<G.vexnum;i++)//初始化辅助结构体 
		{
			V[i].vex=G.vertices[i].data;
			V[i].flag=1;//将每个节点的flag置为0 
		}
			BFS(G,V,0);
		}
	else
	cout<<"输入错误！";
	 
}

int main()
{
 	Menu();
 	return 1;
	
}
/*
6 10
1
2
3
4
5
6
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6
*/
