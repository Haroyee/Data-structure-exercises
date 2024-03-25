//FCA##DB###EH##GM###
#include<iostream> 
#include<queue>
#include<stack>
using namespace std;
int m,n;

/*定义二叉树节点类型*/
typedef struct BiTNode{
	char data;
	struct BiTNode *l,*r; 
}Node,*BiTree;
queue <BiTree> Q;
stack <BiTree> S;
/*先序创建二叉树*/
int InitBiT(BiTree &T)
{
	char e;
	cin >> e;
	if(e=='#') 
		T=NULL;
	else
	{
		T=new Node;
		T->data=e;
		InitBiT(T->l);
 		InitBiT(T->r);
	}
	return 1;
 } 

/*递归遍历*/ 
/*先序遍历*/
int Frontvisit(BiTree T)
{
	if(T)
	{
		cout <<T->data<<" ";
		Frontvisit(T->l);
		Frontvisit(T->r);
	}
	return 1;
 } 
 
 /*中序遍历*/
int Middlevisit(BiTree T)
{
	if(T)
	{
	Middlevisit(T->l);
	cout<<T->data<<" ";
	Middlevisit(T->r);
	}
	return 1;
 } 
 
/*后序遍历*/ 
int Rearvisit(BiTree T)
{
	if(T)
	{
		Rearvisit(T->l);
		Rearvisit(T->r);
		printf("%c ",T->data);
		
	}
	return 1;
} 
/*非递归遍历*/
/*先序遍历*/
int FFrontvisit(BiTree T)
{
	BiTree p=T;
	while(!S.empty()||p)
	{
		while(p)
		{
			cout<<p->data<<" ";
			S.push(p);
			p=p->l;
		}
		if(!S.empty())
		{
			p=S.top();
			S.pop();
			p=p->r;
		}
	}
	return 1;
 
}

/*中序遍历*/
int  MMiddlevisit(BiTree T)
{
	BiTree p=T;
	while(!S.empty()||p)
	{
		while(p)
		{
			S.push(p);
			p=p->l;
		}
		if(!S.empty())
		{
			p=S.top();
			cout<<p->data<<" ";
			S.pop();
			p=p->r;
		}
	}
	return 1;
} 

/*后序遍历*/
int RRearvisit(BiTree T)
{

	BiTree p=T,lp;
	while(!S.empty()||p)
	{
		while(p)
		{
			S.push(p);
			p=p->l;
		}
		if(!S.empty())
		{
			p=S.top();
			S.pop();
		    if(!p->r||p->r==lp)
		    {
		    	cout<<p->data<<" ";
		    	lp=p;
		    	p=NULL;
		    }
		    else
		    {
		    	S.push(p);
		    	p=p->r;
			}
		}	
	}
	return 1;
} 

/*层次遍历*/
int Levelvisit(BiTree T)
{
	BiTree q;
	Q.push(T);
	while(!Q.empty())
	{
		q =Q.front();
		Q.pop();
		cout<<q->data<<" ";
		if(q->l)
		Q.push(q->l);
		if(q->r)
		Q.push(q->r);	
	}
	return 1;
} 

/*二叉树的左右节点互换*/
int ExchangeTNode(BiTree T)
{
	BiTree p;
	if(T)
	{
		p=T->l;
		T->l=T->r;
		T->r=p;
		ExchangeTNode(T->l);
		ExchangeTNode(T->r);
	}
	return 0;
} 

int EExchangevisit(BiTree T)//交换非递归 
{
	BiTree temp,q;
	Q.push(T);	
	while(!Q.empty())
	{
		q=Q.front();
		temp=q->r;
		q->r=q->l;
		q->l=temp;
		Q.pop();
		if(q->l) 
		Q.push(q->l);
		if(q->r)
		Q.push(q->r);
	}
	return 1;
}
/*求深度*/
int GetDeepth(BiTree T)
{
	if(!T) return 0;
	else
	{
		m=GetDeepth(T->l);
		n=GetDeepth(T->r);
		if(m>=n) return (m+1);
		else return (n+1);
	}
}

/*程序界面*/ 
int meus(BiTree T)
{
	char choice;
	while(1)
	{
		getchar();
		system("cls");
		printf("======================================\n"); 
		printf("1.先序遍历(递归)    5.中序遍历(非递归)\n");
		printf("2.中序遍历(递归)    6.后序遍历(非递归)\n");
		printf("3.后序遍历(递归)    7.层次遍历\n");
		printf("4.先序遍历(非递归)  8.左右交换\n");
		printf("0.退出              9.求深度\n") ;
		printf("======================================\n");
		printf("请选择你要执行的操作：");
		scanf("%c",&choice);
		getchar();
		system("cls");
		switch(choice)
		{
			case '0':return 0;break; 
			case '1':printf("先序遍历(递归)：");Frontvisit(T);break;
			case '2':printf("中序遍历(递归)：");Middlevisit(T);break;
			case '3':printf("后序遍历(递归)：");Rearvisit(T);break;
			case '4':printf("先序遍历(非递归)：");FFrontvisit(T);break;
			case '5':printf("中序遍历(非递归)：");Middlevisit(T);break;
			case '6':printf("后序遍历(非递归)：");RRearvisit(T);break;
			case '7':printf("层次遍历：");Levelvisit(T);break;
			case '8':if(EExchangevisit(T)) printf("交换成功！");break;
			case '9':printf("深度为%d",GetDeepth(T));break;
		}
		cout<<endl<<"回车键继续"<<endl;
	 } 
	 return 1;
}

int main()
{
	BiTree T;
	InitBiT(T);
	meus(T);
	
	return 1;
 } 
