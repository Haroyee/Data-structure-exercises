#include<stdio.h>
/*
01 ��������
02 ��ʼ������  ע��ͷ�ڵ� ֱ�Ӹ�ֵ
03 ������� 
*/
 
struct stu{
        int num;
        float score;
        struct stu *next;
};
 
void insert(struct stu *head,struct stu *a)
{
	a->next=head->next;
	head->next=a;
		
 } 
 
  
 

int main(){
 
struct stu a,b,c,*head,*p;
head=new struct stu;
head->next=NULL;
p=head;
a.num=1;
a.score=89;

b.num=2;
b.score=98;

c.num=3;
c.score=99;

insert(head,&a);
insert(head,&b);
insert(head,&c);

head=p->next;
 
do{
        printf("student number: %d score:%f\n",head->num, head->score);
           head =        head->next; //head->next = head
}while(head);
 
return 0;
} 
