/*
有n个人围城一圈，按顺序编号，从第一个人开始报数，从1报到m，凡报到m的人退出圈子，
然后接着报数，问最后留下来的是原来的第几号的那位？

*/
//数组
//用长度为n的数组存储人的编号，退出的人编号置为0，当n-1个人都退出后，剩下的那个编号不为0的人就是要找的人。

#include <stdio.h>
#include <malloc.h>
 
void left_num(int* a,int n,int m) {
    int out = 0,count = 0,i = 0;    //out为出去的人数，count为报数，i为目前报到第几个人
    int *p = a;
    int num = 0;
    for(num = 0;num < n;num++) {
        *(a+num) = num+1;
    }   //为n个人编号1-n
    while (out < n-1) {
        if (*(p+i) != 0) {
            count ++;   //不等于0才报数+！
        }
        if (count == m) {
            count = 0;
            *(p+i) = 0;
            out++;  //报道m那么，出列人数out+1，且内容置0，报数置0
             printf("%d\n",i+1);
        }
       
        i++;
        if (i == n) {
            i = 0;  //到队尾重头开始
        }
        if(out==15)
			break;
    }
    //输出剩下的人
    for (num = 0; num < n; num++) {
        if (*(a+num) != 0) {
            printf("left num:%d\n",*(a+num));
        }
    }
}
 
int main()
{
    int m,n;
    int a[50] = {0};
    printf("Please input total num:");
    scanf("%d",&n);
    printf("Please input out num:");
    scanf("%d",&m);   
    printf("leave sequence：\n"); 
    left_num(a,n,m);
    return 0;
}


