#include <stdio.h>
#include <stdlib.h>
#define size 100

/*����ṹ��*/
typedef struct Q{
	int *data;
	int fornt;
	int rear;
}LinkQueue; 

/*��ʼ��*/

int re_creat(LinkQueue &Q)
{
	Q.data=new int[size];
	if(!Q.data) {
		printf("��ʼ��ʧ�ܣ�\n");
		exit(0);
	}
	Q.fornt=Q.rear=0;
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
	return (Q.rear-Q.fornt+size)%size;
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
	Q.rear=(Q.rear+1)%size;
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
	Q.fornt=(Q.fornt+1)%size;
	return 1;
}
/*��ȡ��ͷԪ��*/
int GetHead(LinkQueue &Q,int &e)
{
		if(EmptyQ(Q))
	{
		printf("��ǰ�ӿգ�\n");
		return 0;
	}
	e = Q.fornt;
	return 1;
}

/*���*/
int DestoryQ(LinkQueue &Q)
{
	free(Q.data);
	Q.fornt=Q.rear=0;
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
	printf("����Ԫ���У�");
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

int main()
{
	LinkQueue Q;
	re_creat(Q);
int choice;
        int data,i,n;
        while(1)
        {
        	printf("=============================\n");
        	printf("******1.���     2.����******\n"); 
        	printf("******3.��ͷ     4.��β******\n"); 
        	printf("******5.�ӳ�     6.����******\n"); 
        	printf("******7.���     8.�˳�******\n");
			printf("=============================\n"); 
        	printf("������Ҫִ�в�����");
        	scanf("%d",&choice);
        	if(choice==8)
			return 0; 
        	switch(choice)
        	{
        		case 1:
        			printf("������Ԫ�ظ�����");
        			scanf("%d",&n);
        			for(i=0;i<n;i++)
        			{
						printf("�������%d��Ԫ�أ�",i+1);
        				scanf("%d",&data);
        				InQ(Q,data);
        			};
					break;
				case 2:
					printf("������Ԫ�ظ�����");
        			scanf("%d",&n);
        			printf("����Ԫ���У�") ;
					for(i=0;i<n;i++)
        			{
        				OutQ(Q,data);
        				printf("%d ",data);
        			};
        			break;
				case 3:
					GetHead(Q,data);
					printf("��ͷԪ��Ϊ��%d\n",data);
					break;
				case 4:break;
				case 5:
					int longth;
					longth = GetLongth(Q);
					printf("�ӳ���Ϊ��%d",longth);
					break;
				case 6:
					PrintfQ(Q);
					break;
				case 7:
					DestoryQ(Q);
					break;		
			}
		}
        
 
        printf("\n");
	
	return 1;
}
