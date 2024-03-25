#include<iostream>
#include<stack>
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
		G.arcs[j][i]=G.arcs[i][j];  //����ԳƵ㸳����ͬ��Ȩֵ 
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
void DFS(AMGraph &G)
{
	Vex V;
	stack<struct Vexs> S;
	int i,j;
	for(int i=0;i<G.vexnum;i++)//��ʼ�������ṹ�� 
	{
		V[i].vex=G.vexs[i];
		V[i].flag=1;//��ÿ���ڵ��flag��Ϊ1
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
 

//�ڽӱ���ͼ
typedef struct Arcnode{ //�߽�� 
	int adjvex;   //�ñ���ָ����λ�� 
	struct Arcnode *nextarc;  //ָ����һ���ߵ�ָ�� 
	int longth; //�ߵ�Ȩֵ 
}ArcNode;

typedef struct Vnode{  //������Ϣ 
	char data;         //���� 
	ArcNode *firstarc;   //ָ���һ�������ö���ıߵ�ָ�� 
}VNode,AdjList[MVNum]; //AdjList��ʾ�ڽӱ�����

typedef struct{
	AdjList vertices;//�����ڽӱ� 
	int vexnum,arcnum; //ͼ�Ķ���������� 
}ALGraph; 
//���ض���v��ͼ�Ķ�����λ�� 
int LocateVex2(ALGraph &G,char v)
{
	for(int i =0;i<G.vexnum;++i)
		if(G.vertices[i].data==v)
			return i;
} 
//�����ڽӱ�
void CreateUDG(ALGraph &G)
{
	int i,j,k,w;
	char v1,v2;
	ArcNode *p1,*p2;
	cout<<"�����붥�����������"<<endl;
	cin>>G.vexnum>>G.arcnum;
	for(i=0;i<G.vexnum;++i)
	{
		cout<<"�������"<<i+1<<"������"<<endl;
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;  //��ʼ����ͷ����ָ���� 
	 } 
	 for(k=0;k<G.arcnum;++k)
	 {
	 	cout<<"���������������������ɱߵ�Ȩֵ"<<endl;
		cin>>v1>>v2>>w; 
		i=LocateVex2(G,v1);j=LocateVex2(G,v2);
		
		p1 = new ArcNode;
		p1->adjvex=j;
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;
		G.vertices[i].firstarc->longth=w;
		
		//���жԳƴ��� 
		p2 = new ArcNode;
		p2->adjvex=i;
		p2->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;
		G.vertices[j].firstarc->longth=w;
	} 
 }
//����ڽӱ� 
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
//�ڽӱ����
void BFS(ALGraph &G,Vex V,int i)//iΪ�ڵ�λ�� 
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
	cout<<"1.�ڽӾ��󴴽�ͼ\n"<<"2.�ڽӱ���ͼ\n";
	cout<<"================================"<<endl;
	cout<<"��������Ҫ���еĲ�����" <<endl;
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
		for(int i=0;i<G.vexnum;i++)//��ʼ�������ṹ�� 
		{
			V[i].vex=G.vertices[i].data;
			V[i].flag=1;//��ÿ���ڵ��flag��Ϊ0 
		}
			BFS(G,V,0);
		}
	else
	cout<<"�������";
	 
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
