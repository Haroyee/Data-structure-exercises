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
/*���*/ 
void binsert(struct stu *head,struct stu *a)
{
	head->next=a;
	head->next->next=NULL;
	head=head->next;	
 } 

/*ǰ��*/ 
void finsert(struct stu *head,struct stu *a)
{
	a->next=head->next;
	head->next=a;
		
 }  
 

int main(){
 
struct stu a,b,c,*head,*p;
int choice;
head=new struct stu;//��ʼ��ͷ�ڵ� 
head->next=NULL;
p=head;
a.num=1;
a.score=89;

b.num=2;
b.score=98;

c.num=3;
c.score=99;

printf("1.ǰ��\n2.���\n��ѡ����Ҫִ�еĲ�����");
scanf("%d",&choice);
printf("\n"); 

if(choice==2) {
binsert(head,&a);
binsert(head,&b);
binsert(head,&c);
}

else if(choice==1){
finsert(head,&a);
finsert(head,&b);
finsert(head,&c);
}
else{
	printf("�������");
	return 0;
}

head=p->next;//����ͷ�ڵ� 
 
do{
        printf("student number: %d score:%f\n",head->num, head->score);
           head =        head->next; //head->next = head
}while(head);
 
return 1;
} 
