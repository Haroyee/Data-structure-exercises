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
 //������ 
int main(){
 
 int num,score;
struct stu a, b, c, *head;
struct stu *binsert(struct stu *head,int n,int s);
struct stu *finsert(struct stu *head,int n,int s);
head=binsert(head,num,score);


 

return 0;
} 
//��巨 
struct stu *binsert(struct stu *head,int n,int s)
{
	struct stu *a;
	a->num=n;
	a->score=s;
	
	head->next=a;
	a->next=NULL;
	return head->next;
} 
//ǰ�巨 
struct stu *finsert(struct stu *head,int n,int s)
{
	struct stu *a;
	
	a->num=n;
	a->score=s;
	
	a->next=head->next;
	head->next=a;
	
}

