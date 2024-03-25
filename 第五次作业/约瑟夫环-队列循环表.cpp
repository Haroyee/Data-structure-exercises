#include <stdio.h>
#include <stdlib.h>
#define size 101 //�������Ϊsize-1 


/*����ṹ��*/
typedef struct Q{
	int *data;
	int fornt;//��ͷ 
	int rear;//��β 
}LinkQueue; 

/*��ʼ��*/

int re_creat(LinkQueue &Q)
{
	Q.data=new int[size];
	if(!Q.data) {
		printf("��ʼ��ʧ�ܣ�\n");
		exit(0);
	}
	Q.fornt=Q.rear=0;//��ͷβ��ָ��0 
	return 1;
} 

/*�ж��Ƿ�Ϊ��*/
int EmptyQ(LinkQueue &Q)
{
	return Q.fornt==Q.rear;
}
/*�ж��Ƿ���*/
int MaxQ(LinkQueue &Q) 
{
	return (Q.rear+1)%size==Q.fornt;
 } 

/*��ȡ����*/
int GetLongth(LinkQueue &Q)
{
	return (Q.rear-Q.fornt+size)%size;//��size��Ϊ�˷�ֹQ.rear<Q.front 
}

/*����*/
int InQ(LinkQueue &Q,int e)
{
	if(MaxQ(Q))
	{
		printf("��ǰ������\n");
		return 0;
	}
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%size;//��βָ��+1 
	return 1;	
}

/*����*/
int OutQ(LinkQueue &Q,int &e)
{
	if(EmptyQ(Q))
	{
		printf("��ǰ�ӿգ�\n");
		return 0;
	}
	e = Q.data[Q.fornt];
	Q.fornt=(Q.fornt+1)%size;//��ͷָ��+1 
	return 1;
}

/*����*/ 
int PrintfQ(LinkQueue &Q)
{
		if(EmptyQ(Q))
	{
		printf("��ǰ�ӿգ�\n");
		return 0;
	}
	int i=Q.fornt;
	printf("�Ҵ����У�");
	while(1)
	{
		if(((i+1-Q.fornt+size)%size)%GetLongth(Q)==0) break; 
		printf("%d ",Q.data[i]);
		i=(i+1)%size;
	}
	if(!MaxQ(Q))
	printf("%d ",Q.data[i]);
	printf("\n");
	return 1;
}

/*���ֺ���*/
int GoOut(LinkQueue &Q,int i,int j)//QΪ�����Ա�Ķӣ�iΪ��Ա������jΪ�������� 
{
	int count = 1,data,l=1; 
	while(GetLongth(Q)>15)
	{
			if(count%j!=0)
			{
				OutQ(Q,data);
				InQ(Q,data);
				count++;
			}
			else 
			{
				OutQ(Q,data);
				printf("��%2d�γ��ֵ�Ϊ��%d\n",l,data); 
				count++;
				l++;
			}
	}
	return 1;
} 
/*������*/ 
int main()
{
	int i;//������
     int N;//���������
     int k;//��������
     printf("���������������");
     scanf("%d",&N);
     printf("������������룺");
     scanf("%d",&k);
     
     LinkQueue Q;
     re_creat(Q);
    
     
     for(i=1;i<=N;i++)
     InQ(Q,i);
     
     GoOut(Q,N,k);
     
     PrintfQ(Q);  
}
