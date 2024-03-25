/*
        Project: single linkeed list (���ݽṹ ������)
        Date:    2021-10-7 09:26:57
        Author:  Frank Wang
        InitList(LinkList &L) ������������L ���ܣ���ʼ�� ʱ�临�Ӷ� O(1)
        ListLength(LinkList L) ������������L ���ܣ���õ������� ʱ�临�Ӷ�O(n)
        ListInsert(LinkList &L,int i,ElemType e) 
        ListDelete(LinkList &L,int i) ������������L��λ��i ���ܣ�ɾ��λ��iԪ�� ʱ�临�Ӷ�O(n)[�����˲���]
                                      ����֪pָ��ָ���ɾ�� �����O(1),��Ϊ�������̽�㽻��������Ȼ��ɾ����̽�㡣
                                      ���O(n),����ͷ����p֮ǰ�Ľ��,Ȼ��ɾ��p��ָ���
         ��e��Ԫ�أ�����ָ�� ʱ�临�Ӷ�O(n)
    */
    #include<cstdio>
    #include<cstdlib>
    #include<cstring>
    #include<cmath>
    #include<iostream>
    using namespace std;
    #define Status int
    #define ElemType int
    //�����������ݽṹ
    typedef struct LNode
    {
    	struct LNode *prior;//ǰָ�� 
        ElemType data;//������
        struct LNode *next;//��ָ�� 
    }LNode,*LinkList;
    //**************************������������***************************//
    //��ʼ������
    Status InitList(LinkList &L)
    {
     L = new LNode;//����ͷ��� ����ɾ���Ȳ����Ͳ��طֵ�һ������������
     L->next = NULL;
     L->prior = NULL;
     return 1;
    }
    //��ȡ�������� ͷ��������ݣ�����
    int ListLength(LinkList L)
    {
        LinkList p=L;int sum=0;
        while(p)
        {
         sum++;
         p=p->next;
        }
        return sum-1;//ȥ��ͷ���
    }
    
    //��巨
    bool ListbInsert(LinkList &L,int i,ElemType e)
    {
        LNode* s;LinkList p=L;int j=0;
        while(p&&(j<i-1))//jָ��i-1λ�û���p�Ѿ������ʱ����
        {
         p=p->next;
         ++j;
        }
        if(!p||j>i-1)//i<1����i>ListLength(L)+1ʱ,����λ����Ч ������ListLength,���Ч��
        {
            printf("����λ����Ч������\n");
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
	 
    //ǰ�巨
    bool ListfInsert(LinkList &L,int i,ElemType e)
    {
        LNode* s;LinkList p=L;int j=0;
        while(p&&(j<i-1))//jָ��i-1λ�û���p�Ѿ������ʱ����
        {
         p=p->next;
         ++j;
        }
        LinkList n=p->next;
        if(!p||j>i-1)//i<1����i>ListLength(L)+1ʱ,����λ����Ч ������ListLength,���Ч��
        {
            printf("����λ����Ч������\n");
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
    
    //ɾ������ ɾ��λ��i�Ľ�� ��ɾ��i-1֮��Ľ��
    bool ListDelete(LinkList &L,int i)
    {
         LNode* s;LinkList p=L;int j=0;
        LinkList q;
        while(p&&(j<i-1))//jָ��i-1λ��
        {
         p=p->next;
         ++j;
        }
        if(!(p->next)||j>i-1)//i<1����i>ListLength(L)ʱ,ɾ��λ����Ч
        {
            printf("ɾ��λ����Ч������\n");
            return false;
        }
        q=p->next;
        p->next=q->next;
        free(q);//�ͷſռ�
        return true;
    }
    //���Һ��� ��ֵ���� ���ҵ�һ������e�Ľ�� �ɹ����ظý��ָ�룬���򷵻�NULL
    LNode *LocateElem(LinkList L,ElemType e)
    {
        LNode *p=L;
        while(p&&(p->data!=e))
        {
            p=p->next;
        }
        return p;
    }
    //**************************����ʵ�ֺ���**************************//
    //�����������
    //������� 
    void PrintPList(LinkList L)
    {
        LinkList p=L->next;//����ͷ���
        if(ListLength(L))
        {
            printf("��ǰ����������Ԫ��:");
            while(p)
            {
                printf("%d ",p->data);
                p=p->next;
            }
            printf("\n");
        }
        else
        {
            printf("��ǰ�������ѿգ�\n");
        }
    }
    //�������
    void printRList(LinkList L)
	{
		LinkList p;
		p=L;
		while(p->next)
		p=p->next;
		
		if(ListLength(L))
        {
            printf("��ǰ����������Ԫ��:");
            while(p->prior)
            {
                printf("%d ",p->data);
                p=p->prior;
            }
            printf("\n");
        }
        else
        {
            printf("��ǰ�������ѿգ�\n");
        }
			
	} 
	 
    //���빦�ܺ��� ����ListInsert���� 
    void Insert(LinkList &L)
    {
      int place;ElemType e;bool flag;
      int c;
      printf("��ѡ����뷽ʽ��\n1.ǰ��\n2.���\n");
      scanf("%d",&c);
      
      if(c==1)
      {
      	printf("������Ҫ�����λ��(��1��ʼ)��Ԫ��:\n");
      scanf("%d%d",&place,&e);
      flag=ListfInsert(L,place,e);
      if(flag)
      {
        printf("����ɹ�������\n");
        PrintPList(L);
      }
      else printf("�������\n");
	  }
      
      else if(c==2)
      {
	  printf("������Ҫ�����λ��(��1��ʼ)��Ԫ��:\n");
      scanf("%d%d",&place,&e);
      flag=ListbInsert(L,place,e);
      if(flag)
      {
        printf("����ɹ�������\n");
        PrintPList(L);
      }
  		}
  		else printf("�������\n");
    }
    //ɾ�����ܺ��� ����ListDeleteɾ��
    void Delete(LinkList L)
    {
      int place;bool flag;
      printf("������Ҫɾ����λ��(��1��ʼ):\n");
      scanf("%d",&place);
      flag=ListDelete(L,place);
      if(flag)
      {
        printf("ɾ���ɹ�������\n");
        PrintPList(L);
      }
    }
    //���ҹ��ܺ��� ����LocateElem����
    void Search(LinkList L)
    {
      ElemType e;LNode *q;
      printf("������Ҫ���ҵ�ֵ:\n");
      scanf("%d",&e);
      q=LocateElem(L,e);
      if(q)
      {
        printf("�ҵ���Ԫ�أ�\n");
      }
      else
        printf("δ�ҵ���Ԫ�أ�\n");
    }
    //������
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
		printf("������ɣ�\n"); 
		return; 
	}
	//ͷ�ڵ��β�ڵ�
	void Ftl(LinkList L)
	{
		LinkList p=L,q=L->next,y=L;
		
		while(p->next!=NULL)//ָ���ƶ���β�ڵ� 
		p=p->next;
		if(p=y)
		{
		printf("��ǰ����ֻ��ͷ�ڵ�!\n");
		return ; 
		}
		q->prior=y->prior;
		y->next=p->next;
		p->next=y;
		y->prior=p;
		printf("�ƶ��ɹ���\n");
	 } 
	
    //�˵�
    void menu()
    {
       printf("********1.����     2.ɾ��************\n");
       printf("********3.����     4.�������********\n");
       printf("********5.������� 6.����************\n");
       printf("********7.ͷ�ڵ��β�ڵ�     8.�˳�**\n");
    }
    
    //������
    int main()
    {
     LinkList L;int choice;
     InitList(L);
     while(1)
     {
      menu();
      printf("������˵���ţ�\n");
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
      default:printf("������󣡣���\n");
      }
     }
     return 0;
    }
