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
/*后插*/ 
void binsert(struct stu *head,struct stu *a)
{
	head->next=a;
	head->next->next=NULL;
	head=head->next;	
 } 

/*前插*/ 
void finsert(struct stu *head,struct stu *a)
{
	a->next=head->next;
	head->next=a;
		
 }  
 

int main(){
 
struct stu a,b,c,*head,*p;
int choice;
head=new struct stu;//初始化头节点 
head->next=NULL;
p=head;
a.num=1;
a.score=89;

b.num=2;
b.score=98;

c.num=3;
c.score=99;

printf("1.前插\n2.后插\n请选择你要执行的操作：");
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
	printf("输入错误！");
	return 0;
}

head=p->next;//跳过头节点 
 
do{
        printf("student number: %d score:%f\n",head->num, head->score);
           head =        head->next; //head->next = head
}while(head);
 
return 1;
} 
