/*
��n����Χ��һȦ����˳���ţ��ӵ�һ���˿�ʼ��������1����m��������m�����˳�Ȧ�ӣ�
Ȼ����ű��������������������ԭ���ĵڼ��ŵ���λ��

*/

//ѭ������ʵ��
//����һ��ѭ����������ڵ�����������˵ı�ţ�������������ÿ�α���m�����˳������ͷŸýڵ㣬ֱ������ֻʣһ���ڵ㡣
#include <stdio.h>
#include <malloc.h>
 
 /*�����ṹ��*/
 typedef struct Node{
     int Num;
     struct Node *next;
 }JoseNode, *PNode, *HNode;
 
 /**********��ʼ��ѭ��������*********/
 int JoseInit(HNode h)
 {
     if (!h)
     {
         printf("��ʼ���������\n");
         return 0;
     }
     (h)->next = (h);//ѭ��������
     return 1;
 
 }
 
 /*************������������**********/
 int JoseInsert(JoseNode *h, int pos, int x)
 {    
     PNode p=h,q;
     int i=1;
     if (pos == 1)/*β�巨*/
     {
         p->Num = x;
         p->next = p;
         return 1;
     }
     while(i<pos-1)
     {
         p=p->next;
         i++;
     }
     q=(PNode)malloc(sizeof(JoseNode));
     q->Num=x;
     q->next=p->next;
     p->next=q;
     return 1;
 }
 
 /*����*/
 void TraverseList(HNode h, int M)
 {
     int i = 0;
     PNode p = h;
     printf("������˵ı��Ϊ��\n");
     while (i<M)
     {
         printf("%d\t", p->Num);
         p = p->next;
         i++;
     }
     printf("\n");
 }
 /**************���ֺ���****************/
 
 int JoseDelete(HNode h, int M, int k)
 {    int i;
     PNode p=h,q;
     while(M>15)
     {
         for(i=1;i<k-1;i++)
         {
             p=p->next;
         }
         
         q=p->next;
         p->next=q->next;
         printf("���ֵ���Ϊ��%d��\n",q->Num);
         free(q);
 
         p=p->next;
         M--;
     }
     return 1;
 }
 //�����Ҵ���
void PrintfSurvivor(HNode h)
{
	HNode p=h;
	printf("�Ҵ����У�"); 
	printf("%d ",p->Num);
	p=p->next;
	while(p!=h)
	{
		printf("%d ",p->Num);
		p=p->next;
	}
}
 
 /***************************************/
 int main()
 {
     int i;//������
     int N;//���������
     int k;//��������
     printf("���������������");
     scanf("%d",&N);
     printf("������������룺");
     scanf("%d",&k);
 
 /**************�õ�ͷ���****************/
     HNode h = ((HNode)malloc(sizeof(JoseNode)));
 
 /***************��ʼ��������************/
     JoseInit(h);
 
 /******����Ų��뵽ѭ����������******/
     for (i = 1; i <=N; i++)
     {
         JoseInsert(h, i, i);
     }
 /**************����������***************/
     TraverseList(h,N);
 
 /***************���ֺ���************/
     if(k > 1)
     {
	 	JoseDelete(h, N, k);
     	PrintfSurvivor(h);
     }
     else
     {
         for(i = 1; i < N-15; i++)
             printf("���ֵ���Ϊ��%d��\n",i);
        PrintfSurvivor(h);
     }
 
     printf("\n");
     printf("\n");
     return 0;
 }


