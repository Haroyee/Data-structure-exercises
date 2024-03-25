#include<stdio.h>
#include<stdlib.h>

/*�����Թ�����㡢�յ�*/
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
			  
int a[10][10];//���������ڼ�¼�����˶����� 
struct s{
	int x,y;
}start,end;

// ���еĽڵ� 
struct Node
{
        int x,y;
        struct Node* next;
};
// ���׶�βָ�� 
struct Queue
{
        struct Node* front;
        struct Node* rear;
        int size;
};
// ���ӳ�ʼ�� 
void QueueInit(struct Queue* queue)
{
        queue->front = NULL;
        queue->rear = NULL;
        queue->size = 0;
}
 // �ж��Ƿ�Ϊ�� 
int QueueEmpty(struct Queue* queue)
{
        return (queue->size == 0);
}
// ��� 
void QueuePush(struct Queue* queue, int x,int y)
{
        struct Node* node;
        node = (struct Node*)malloc(sizeof(struct Node));
        
        
        node->x = x;
        node->y = y;
        node->next = NULL;
        
        if(QueueEmpty(queue))
        {
            queue->front = node;
            queue->rear = node;
        }
        else
        {            
            queue->rear->next = node;
            queue->rear = node;
        }
        ++queue->size;
}
 //���� 
int QueuePop(struct Queue* queue, int *x,int *y)
{
        if (QueueEmpty(queue))
        {
                return 0;
        }
        struct Node* tmp = queue->front;
        *x= queue->front->x;
        *y= queue->front->y;
        queue->front = queue->front->next;
        free(tmp);
        --queue->size;
 
        return 1;
}
/*���Թ�����*/
int GO(struct Queue* Q)
{
	int x,y,k,l;
	while(!QueueEmpty(Q))
	{
		QueuePop(Q,&k,&l);
		for(int i=0;i<=3;i++)
		{
			 
			x=k;
			y=l;
			switch(i)
			{
				case 0:x=x+1;break;
				case 1:y=y-1;break;
				case 2:x=x-1;break;
				case 3:y=y+1;break;
			}
			if(x>=0&&y>=0&&x<=9&&y<=9&&m[y][x]==0)
			{
				QueuePush(Q,x,y);
				a[y][x]=i;
				m[y][x]=-2;
			}
			if(x==8&&y==8) return 1;
		}	
	}
	return 0;
}
/*���»����Թ�*/ 
int ans()
{
	int x=8,y=8;
	while(1)
	{
		m[y][x]=-1;
		switch(a[y][x])//���յ㿪ʼ������� 
		{
			case 0:x=x-1;break;
			case 1:y=y+1;break;
			case 2:x=x+1;break;
			case 3:y=y-1;break;
		}
		if(x==1&&y==1)
		{
			m[y][x]=-1;
			return 1;
		}
	
	}
}

/*����Թ�*/
int printfM(int m[10][10])
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(m[i][j]==1) printf("��");
			else if(m[i][j]==-1) printf("* ");
			else printf("  ");
	
		}
		printf("\n");
 	}
	 return 1;	 
} 
int main()
{
	struct Queue Q;
	QueueInit(&Q);
	printf("���Թ�ǰ��\n");
	printfM(m);
	QueuePush(&Q,1,1);
	GO(&Q);
	ans();
	printf("���Թ���\n"); 
	printfM(m);
	return 1;
}

