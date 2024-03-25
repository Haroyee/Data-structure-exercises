//FCA##DB###EH##GM###
#include<iostream> 
#include<queue>
#include<stack>
using namespace std;
int m,n;

/*����������ڵ�����*/
typedef struct BiTNode{
	char data;
	struct BiTNode *l,*r; 
}Node,*BiTree;
queue <BiTree> Q;
stack <BiTree> S;
/*���򴴽�������*/
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

/*�ݹ����*/ 
/*�������*/
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
 
 /*�������*/
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
 
/*�������*/ 
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
/*�ǵݹ����*/
/*�������*/
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

/*�������*/
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

/*�������*/
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

/*��α���*/
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

/*�����������ҽڵ㻥��*/
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

int EExchangevisit(BiTree T)//�����ǵݹ� 
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
/*�����*/
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

/*�������*/ 
int meus(BiTree T)
{
	char choice;
	while(1)
	{
		getchar();
		system("cls");
		printf("======================================\n"); 
		printf("1.�������(�ݹ�)    5.�������(�ǵݹ�)\n");
		printf("2.�������(�ݹ�)    6.�������(�ǵݹ�)\n");
		printf("3.�������(�ݹ�)    7.��α���\n");
		printf("4.�������(�ǵݹ�)  8.���ҽ���\n");
		printf("0.�˳�              9.�����\n") ;
		printf("======================================\n");
		printf("��ѡ����Ҫִ�еĲ�����");
		scanf("%c",&choice);
		getchar();
		system("cls");
		switch(choice)
		{
			case '0':return 0;break; 
			case '1':printf("�������(�ݹ�)��");Frontvisit(T);break;
			case '2':printf("�������(�ݹ�)��");Middlevisit(T);break;
			case '3':printf("�������(�ݹ�)��");Rearvisit(T);break;
			case '4':printf("�������(�ǵݹ�)��");FFrontvisit(T);break;
			case '5':printf("�������(�ǵݹ�)��");Middlevisit(T);break;
			case '6':printf("�������(�ǵݹ�)��");RRearvisit(T);break;
			case '7':printf("��α�����");Levelvisit(T);break;
			case '8':if(EExchangevisit(T)) printf("�����ɹ���");break;
			case '9':printf("���Ϊ%d",GetDeepth(T));break;
		}
		cout<<endl<<"�س�������"<<endl;
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
