/*
��n����Χ��һȦ����˳���ţ��ӵ�һ���˿�ʼ��������1����m��������m�����˳�Ȧ�ӣ�
Ȼ����ű��������������������ԭ���ĵڼ��ŵ���λ��

*/
//����
//�ó���Ϊn������洢�˵ı�ţ��˳����˱����Ϊ0����n-1���˶��˳���ʣ�µ��Ǹ���Ų�Ϊ0���˾���Ҫ�ҵ��ˡ�

#include <stdio.h>
#include <malloc.h>
 
void left_num(int* a,int n,int m) {
    int out = 0,count = 0,i = 0;    //outΪ��ȥ��������countΪ������iΪĿǰ�����ڼ�����
    int *p = a;
    int num = 0;
    for(num = 0;num < n;num++) {
        *(a+num) = num+1;
    }   //Ϊn���˱��1-n
    while (out < n-1) {
        if (*(p+i) != 0) {
            count ++;   //������0�ű���+��
        }
        if (count == m) {
            count = 0;
            *(p+i) = 0;
            out++;  //����m��ô����������out+1����������0��������0
             printf("%d\n",i+1);
        }
       
        i++;
        if (i == n) {
            i = 0;  //����β��ͷ��ʼ
        }
        if(out==15)
			break;
    }
    //���ʣ�µ���
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
    printf("leave sequence��\n"); 
    left_num(a,n,m);
    return 0;
}


