#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// 队列的节点 
struct Node
{
        int data;
        struct Node* next;
};
// 队首队尾指针 
struct Queue
{
        struct Node* front;
        struct Node* rear;
        int size;
};
// 链队初始化 
void QueueInit(struct Queue* queue)
{
        queue->front = NULL;
        queue->rear = NULL;
        queue->size = 0;
}
 // 判断是否为空 
int QueueEmpty(struct Queue* queue)
{
        return (queue->size == 0);
}
// 入队 
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
 //出队 
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

//获取队头元素
void GetHead(struct Queue* queue)
{
	if(!QueueEmpty(queue))
	{
		printf("当前队列为空！\n");
		return ;
	}
	printf("队头元素为：%d \n",queue->front->data);
	return ;
	
} 

// 获取队尾元素
 
//获取队列长度
int GetLongth(struct Queue* queue)
{
	return queue->size;
} 
 //链队的销毁 
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
//链队输出//
void printfQueue(struct Queue Q)
{
	struct Queue q;
	q=Q;
	 printf("队列元素有：") ;
	while(q.front!=NULL)
	{
		printf("%d ",q.front->data);
		q.front=q.front->next;
	}
	printf("\n"); 
} 
//主函数 
int main(void)
{
        struct Queue queue;
        QueueInit(&queue);
        int choice;
        int data,i,n;
        while(1)
        {
        	printf("=============================\n");
        	printf("******1.入队     2.出队******\n"); 
        	printf("******3.队头     4.队尾******\n"); 
        	printf("******5.队长     6.遍历******\n"); 
        	printf("******7.销毁     8.退出******\n");
			printf("=============================\n"); 
        	printf("请输入要执行操作：");
        	scanf("%d",&choice);
        	if(choice==8)
			return 0; 
        	switch(choice)
        	{
        		case 1:
        			printf("请输入元素个数：");
        			scanf("%d",&n);
        			for(i=0;i<n;i++)
        			{
						printf("请输入第%d个元素：",i+1);
        				scanf("%d",&data);
        				QueuePush(&queue,data);
        			};
					break;
				case 2:
					printf("请输入元素个数：");
        			scanf("%d",&n);
        			printf("出队元素有：") ;
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
					printf("队长度为：%d",longth);
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
