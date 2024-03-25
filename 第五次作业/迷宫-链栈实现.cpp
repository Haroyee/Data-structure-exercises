#include<stdio.h>
#include<stdlib.h>

/*定义迷宫及起点、终点*/
int min=100;
int m[10][10]={{1,1,1,1,1,1,1,1,1,1},
			   {1,0,0,1,0,0,0,1,0,1},
			   {1,0,0,1,0,0,0,1,0,1},
			   {1,0,0,0,0,1,1,0,0,1},
			   {1,0,1,1,1,0,0,0,0,1},
			   {1,0,0,0,1,0,0,0,0,1},
			   {1,0,1,0,0,0,1,0,0,1},
			   {1,0,1,1,1,0,1,1,0,1},
			   {1,1,0,0,0,0,0,0,0,1},
			   {1,1,1,1,1,1,1,1,1,1}};
int c[10][10];
struct s{
	int x,y;
}start,end;
/*重置迷宫*/
int reM()
{
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
	m[i][j]=c[i][j];
	return 1;
} 


/*定义栈的节点*/ 
typedef struct StackNode
{
	int x,y;
	struct StackNode *next;
 }StackNode,*LinkStack;
		   
//*链栈的初始化*//
int re_stack(LinkStack &S)
{
	S=NULL;
	return 1;
}

//*链栈的栈空判断*//
int if_empty(LinkStack &S)
{
	if(S==NULL) return 1;
	else return 0;
} 

//*链栈的入栈*//
int in_stack(LinkStack &S,int a,int b)
{
	LinkStack p; 
	p=new StackNode;
	p->x=a;p->y=b;
	p->next=S;
	S=p;
	return 1;
} 

//*链栈的出栈*//
int out_stack(LinkStack &S,int &x,int &y)
{
	LinkStack p;
	if(if_empty(S))	
		return 0;
	p=S;
	x=p->x;y=p->y;
	S=S->next;
	free(p);
	return 1;	
} 
/*输出迷宫*/
int printfM(int m[10][10])
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(m[i][j]==1) printf("■");
			else if(m[i][j]==-1) printf("* ");
			else printf("  ");
	
		}
		printf("\n");
 	}
	 return 1;	 
}

/*走迷宫函数*/
int GO(LinkStack &S)
{
	int i,x=start.x,y=start.y,k,longth=0;//k用于判断是否进了死胡同 
	m[1][1]=-1;
	while(1)
	{
		int k=0;
		for(int i=0;i<4;i++)
		{
			int c =(int)rand()%4;
			switch(c)
			{
				case 0:x=x-1;break;
				case 1:y=y+1;break;
				case 2:x=x+1;break;
				case 3:y=y-1;break;
			}
			if(x>=0&&y>=0&&x<=9&&y<=9&&m[y][x]==0)
			{
				in_stack(S,x,y);
				m[y][x]=-1;//标记走过的路 
				k=1;
				longth++;
			}
			else
			{
				switch(c)
				{
					case 0:x=x+1;break;
					case 1:y=y-1;break;
					case 2:x=x-1;break;
					case 3:y=y+1;break;
				}
			}
		}
	
		if(x==end.x&&y==end.y) 
		{
			if(min>longth)
			{
				min=longth;
				printfM(m);
				reM();
				x=start.x;
				y=start.y;
			}
			longth=0;
			continue;
		}
		else if(!k)
		{
			m[y][x]=-2;//走到死胡同把胡同路堵死，不再走这条路 
			out_stack(S,x,y);
			longth--;
		}
	}
}


int main()
{
	LinkStack S;
	re_stack(S);
	
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
	c[i][j]=m[i][j];
	
	printf("解迷宫前：\n") ;
	printfM(m);
	start.x=1;
	start.y=1;
	in_stack(S,start.x,start.y);
	end.x=8;
	end.y=8;
	GO(S);
	printf("解迷宫后：\n"); 
	printfM(m);
	return 1;
}

