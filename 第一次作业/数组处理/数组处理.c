#include<stdio.h>
#define MAX 100

int insert(int a[],int n,int i,int x)
{
    int j;
    if(n+1>MAX)
        printf("�޲���ռ�\n");      //����ֻ�ܴ�MAX����
    else if(i<1||i>n+1)
        printf("����λ�÷Ƿ�\n"); //����λ�õķ�ΧΪ1..n+1
    else
    {
        for(j=n-1;j>i-2;j--)
            a[j+1]=a[j];    //��������iλ�ü�������������������ƶ�һ��
        a[i-1]=x;           //��iλ�ò���x
        n++;

    }
    return n;         //���ص�ǰ�����С
}
int del(int a[],int n,int i)
{
    int j;
    if(i<1||i>n)
        printf("ɾ��λ�÷Ƿ�\n");
    else
    {
        for(j=i-1;j<n-1;j++)
            a[j] = a[j+1];
        n--;
    }
    return n;
}
int search(int a[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
            return i+1;
    }
    return -1;
}
void printArray(int a[],int n)
{
    int i;
    for(i=0;;i++)
    {
        if(i==n-1)
        {
            printf("%d\n",a[i]);
            break;
        }
        printf("%d ",a[i]);
    }
}
int main()
{
    int n,i,a[MAX];
    int index,x;
    printf("���������е�Ԫ�ظ���\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("������Ҫ�����λ�úͲ������\n");
    scanf("%d %d",&index,&x);

    n = insert(a,n,index,x);
    printArray(a,n);
    printf("������Ҫɾ��Ԫ�ص�λ��\n");
    scanf("%d",&index);
    n = del(a,n,index);
    printArray(a,n);
    printf("������Ҫ��ѯ��Ԫ��\n");
    scanf("%d",&x);
    i = search(a,n,x);
    if(i!=-1)
        printf("%d��λ�ã�%d\n",x,i);
    else
        printf("δ�ҵ�%d\n",x);
        
    return 0;
} 
