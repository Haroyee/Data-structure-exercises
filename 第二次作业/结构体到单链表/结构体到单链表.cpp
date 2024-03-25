#include<stdio.h>
/*
01 构建链表
02 初始化链表  注意头节点 直接赋值
03 输出链表 
*/
 
struct stu{
        int num;
        float score;
        struct stu *next;
};
 //主程序 
int main(){
 
 int num,score;
struct stu a, b, c, *head;
struct stu *binsert(struct stu *head,int n,int s);
struct stu *finsert(struct stu *head,int n,int s);
head=binsert(head,num,score);


 

return 0;
} 
//后插法 
struct stu *binsert(struct stu *head,int n,int s)
{
	struct stu *a;
	a->num=n;
	a->score=s;
	
	head->next=a;
	a->next=NULL;
	return head->next;
} 
//前插法 
struct stu *finsert(struct stu *head,int n,int s)
{
	struct stu *a;
	
	a->num=n;
	a->score=s;
	
	a->next=head->next;
	head->next=a;
	
}

