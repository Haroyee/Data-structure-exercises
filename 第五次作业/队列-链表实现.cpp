#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// ���еĽڵ� 
struct Node
{
        int data;
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
void QueuePush(struct Queue* queue, const int data)
{
        struct Node* node;
        node = (struct Node*)malloc(sizeof(struct Node));
        assert(node != NULL);
        
        node->data = data;
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
int QueuePop(struct Queue* queue, int* data)
{
        if (QueueEmpty(queue))
        {
                return 0;
        }
        struct Node* tmp = queue->front;
        *data = queue->front->data;
        queue->front = queue->front->next;
        free(tmp);
        --queue->size;
 
        return 1;
}

//��ȡ��ͷԪ��
void GetHead(struct Queue* queue)
{
	if(!QueueEmpty(queue))
	{
		printf("��ǰ����Ϊ�գ�\n");
		return ;
	}
	printf("��ͷԪ��Ϊ��%d \n",queue->front->data);
	return ;
	
} 

// ��ȡ��βԪ��
 
//��ȡ���г���
int GetLongth(struct Queue* queue)
{
	return queue->size;
} 
 //���ӵ����� 
void QueueDestroy(struct Queue* queue)
{
     struct Node* tmp;
     while(queue->front)
     {
         tmp = queue->front;
         queue->front = queue->front->next;
         free(tmp);
     }
}
//�������//
void printfQueue(struct Queue Q)
{
	struct Queue q;
	q=Q;
	 printf("����Ԫ���У�") ;
	while(q.front!=NULL)
	{
		printf("%d ",q.front->data);
		q.front=q.front->next;
	}
	printf("\n"); 
} 
//������ 
int main(void)
{
        struct Queue queue;
        QueueInit(&queue);
        int choice;
        int data,i,n;
        while(1)
        {
        	printf("=============================\n");
        	printf("******1.���     2.����******\n"); 
        	printf("******3.��ͷ     4.��β******\n"); 
        	printf("******5.�ӳ�     6.����******\n"); 
        	printf("******7.����     8.�˳�******\n");
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
        				QueuePush(&queue,data);
        			};
					break;
				case 2:
					printf("������Ԫ�ظ�����");
        			scanf("%d",&n);
        			printf("����Ԫ���У�") ;
					for(i=0;i<n;i++)
        			{
        				QueuePop(&queue,&data);
        				printf("%d ",data);
        			};
        			break;
				case 3:
					GetHead(&queue);
					break;
				case 4:break;
				case 5:
					int longth;
					longth = GetLongth(&queue);
					printf("�ӳ���Ϊ��%d",longth);
					break;
				case 6:
					printfQueue(queue);
					break;
				case 7:
					QueueDestroy(&queue);
					break;		
			}
		}
        
 
        printf("\n");
 
        return 0;
}
