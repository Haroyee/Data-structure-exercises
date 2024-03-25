/*
        Project: single linkeed list (数据结构 单链表)
        Date:    2021-10-7 09:26:57
        Author:  Frank Wang
        InitList(LinkList &L) 参数：单链表L 功能：初始化 时间复杂度 O(1)
        ListLength(LinkList L) 参数：单链表L 功能：获得单链表长度 时间复杂度O(n)
        ListInsert(LinkList &L,int i,ElemType e) 
        ListDelete(LinkList &L,int i) 参数：单链表L，位置i 功能：删除位置i元素 时间复杂度O(n)[加入了查找]
                                      若已知p指针指向的删除 最好是O(1),因为可以与后继结点交换数据域，然后删除后继结点。
                                      最坏是O(n),即从头查找p之前的结点,然后删除p所指结点
         于e的元素，返回指针 时间复杂度O(n)
    */
    #include<cstdio>
    #include<cstdlib>
    #include<cstring>
    #include<cmath>
    #include<iostream>
    using namespace std;
    #define Status int
    #define ElemType int
    //单链表结点数据结构
    typedef struct LNode
    {
    	struct LNode *prior;//前指针 
        ElemType data;//数据域
        struct LNode *next;//后指针 
    }LNode,*LinkList;
    //**************************基本操作函数***************************//
    //初始化函数
    Status InitList(LinkList &L)
    {
     L = new LNode;//生成头结点 这样删除等操作就不必分第一个结点和其他了
     L->next = NULL;
     L->prior = NULL;
     return 1;
    }
    //获取单链表长度 头结点无数据，不算
    int ListLength(LinkList L)
    {
        LinkList p=L;int sum=0;
        while(p)
        {
         sum++;
         p=p->next;
        }
        return sum-1;//去除头结点
    }
    
    //后插法
    bool ListbInsert(LinkList &L,int i,ElemType e)
    {
        LNode* s;LinkList p=L;int j=0;
        while(p&&(j<i-1))//j指到i-1位置或者p已经到最后时跳出
        {
         p=p->next;
         ++j;
        }
        if(!p||j>i-1)//i<1或者i>ListLength(L)+1时,插入位置无效 不调用ListLength,提高效率
        {
            printf("插入位置无效！！！\n");
            return false;
        }
        s=new LNode;
        
        s->data=e;
        
        s->next=p->next;
        p->next=s;
        
        s->prior=p;
        if(s->next!=NULL)
		s->next->prior=s;
        return true;
    }
	 
    //前插法
    bool ListfInsert(LinkList &L,int i,ElemType e)
    {
        LNode* s;LinkList p=L;int j=0;
        while(p&&(j<i-1))//j指到i-1位置或者p已经到最后时跳出
        {
         p=p->next;
         ++j;
        }
        LinkList n=p->next;
        if(!p||j>i-1)//i<1或者i>ListLength(L)+1时,插入位置无效 不调用ListLength,提高效率
        {
            printf("插入位置无效！！！\n");
            return false;
        }
        s=new LNode;
        
        s->data=e;
        
		s->next=n;
		s->prior=p;
		p->next=s;
		if(s->next!=NULL)
		n->prior=s;
		
        return true;
    }
    
    //删除函数 删除位置i的结点 即删除i-1之后的结点
    bool ListDelete(LinkList &L,int i)
    {
         LNode* s;LinkList p=L;int j=0;
        LinkList q;
        while(p&&(j<i-1))//j指到i-1位置
        {
         p=p->next;
         ++j;
        }
        if(!(p->next)||j>i-1)//i<1或者i>ListLength(L)时,删除位置无效
        {
            printf("删除位置无效！！！\n");
            return false;
        }
        q=p->next;
        p->next=q->next;
        free(q);//释放空间
        return true;
    }
    //查找函数 按值查找 查找第一个等于e的结点 成功返回该结点指针，否则返回NULL
    LNode *LocateElem(LinkList L,ElemType e)
    {
        LNode *p=L;
        while(p&&(p->data!=e))
        {
            p=p->next;
        }
        return p;
    }
    //**************************功能实现函数**************************//
    //遍历输出函数
    //正序输出 
    void PrintPList(LinkList L)
    {
        LinkList p=L->next;//跳过头结点
        if(ListLength(L))
        {
            printf("当前单链表所有元素:");
            while(p)
            {
                printf("%d ",p->data);
                p=p->next;
            }
            printf("\n");
        }
        else
        {
            printf("当前单链表已空！\n");
        }
    }
    //逆序输出
    void printRList(LinkList L)
	{
		LinkList p;
		p=L;
		while(p->next)
		p=p->next;
		
		if(ListLength(L))
        {
            printf("当前单链表所有元素:");
            while(p->prior)
            {
                printf("%d ",p->data);
                p=p->prior;
            }
            printf("\n");
        }
        else
        {
            printf("当前单链表已空！\n");
        }
			
	} 
	 
    //插入功能函数 调用ListInsert插入 
    void Insert(LinkList &L)
    {
      int place;ElemType e;bool flag;
      int c;
      printf("请选择插入方式：\n1.前插\n2.后插\n");
      scanf("%d",&c);
      
      if(c==1)
      {
      	printf("请输入要插入的位置(从1开始)及元素:\n");
      scanf("%d%d",&place,&e);
      flag=ListfInsert(L,place,e);
      if(flag)
      {
        printf("插入成功！！！\n");
        PrintPList(L);
      }
      else printf("输入错误！\n");
	  }
      
      else if(c==2)
      {
	  printf("请输入要插入的位置(从1开始)及元素:\n");
      scanf("%d%d",&place,&e);
      flag=ListbInsert(L,place,e);
      if(flag)
      {
        printf("插入成功！！！\n");
        PrintPList(L);
      }
  		}
  		else printf("输入错误！\n");
    }
    //删除功能函数 调用ListDelete删除
    void Delete(LinkList L)
    {
      int place;bool flag;
      printf("请输入要删除的位置(从1开始):\n");
      scanf("%d",&place);
      flag=ListDelete(L,place);
      if(flag)
      {
        printf("删除成功！！！\n");
        PrintPList(L);
      }
    }
    //查找功能函数 调用LocateElem查找
    void Search(LinkList L)
    {
      ElemType e;LNode *q;
      printf("请输入要查找的值:\n");
      scanf("%d",&e);
      q=LocateElem(L,e);
      if(q)
      {
        printf("找到该元素！\n");
      }
      else
        printf("未找到该元素！\n");
    }
    //排序函数
	void Sort(LinkList L) 
	{
		LNode *n;
		int m=ListLength(L);
		n=L->next;
		
		int t;
		while(m)
		{
			while(n->next!=NULL)
			{
				if((n->data)>(n->next->data))
				{
					t=n->data;n->data=n->next->data;n->next->data=t;
				}
				n=n->next;
				
			}
			n=L->next;
			m--;
		}
		printf("排序完成！\n"); 
		return; 
	}
	//头节点变尾节点
	void Ftl(LinkList L)
	{
		LinkList p=L,q=L->next,y=L;
		
		while(p->next!=NULL)//指针移动到尾节点 
		p=p->next;
		if(p=y)
		{
		printf("当前链表只有头节点!\n");
		return ; 
		}
		q->prior=y->prior;
		y->next=p->next;
		p->next=y;
		y->prior=p;
		printf("移动成功！\n");
	 } 
	
    //菜单
    void menu()
    {
       printf("********1.插入     2.删除************\n");
       printf("********3.查找     4.正序输出********\n");
       printf("********5.逆序输出 6.排序************\n");
       printf("********7.头节点变尾节点     8.退出**\n");
    }
    
    //主函数
    int main()
    {
     LinkList L;int choice;
     InitList(L);
     while(1)
     {
      menu();
      printf("请输入菜单序号：\n");
      scanf("%d",&choice);
      if(choice==8) break;
      switch(choice)
      {
      case 1:Insert(L);break;
      case 2:Delete(L);break;
      case 3:Search(L);break;
      case 4:PrintPList(L);break;
      case 5:printRList(L);break; 
      case 6:Sort(L);break;
	  case 7:Ftl(L);break; 
      default:printf("输入错误！！！\n");
      }
     }
     return 0;
    }
