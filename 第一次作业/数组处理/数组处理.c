#include<stdio.h>
#define MAX 100

int insert(int a[],int n,int i,int x)
{
    int j;
    if(n+1>MAX)
        printf("无插入空间\n");      //数组只能存MAX个数
    else if(i<1||i>n+1)
        printf("插入位置非法\n"); //插入位置的范围为1..n+1
    else
    {
        for(j=n-1;j>i-2;j--)
            a[j+1]=a[j];    //将数组中i位置及其后面的数，依次向后移动一格
        a[i-1]=x;           //在i位置插入x
        n++;

    }
    return n;         //返回当前数组大小
}
int del(int a[],int n,int i)
{
    int j;
    if(i<1||i>n)
        printf("删除位置非法\n");
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
    printf("输入数组中的元素个数\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("请输入要插入的位置和插入的数\n");
    scanf("%d %d",&index,&x);

    n = insert(a,n,index,x);
    printArray(a,n);
    printf("请输入要删除元素的位置\n");
    scanf("%d",&index);
    n = del(a,n,index);
    printArray(a,n);
    printf("请输入要查询的元素\n");
    scanf("%d",&x);
    i = search(a,n,x);
    if(i!=-1)
        printf("%d的位置：%d\n",x,i);
    else
        printf("未找到%d\n",x);
        
    return 0;
} 
