#include<stdio.h>
#include<math.h>
#include<string.h>
#define Max 100

typedef struct jzzh{
	int top;
	int arr[Max];
}J;	
int arr[Max];
void _10_(int A,int B)//��10���Ƶ���Aת��ΪB���Ƶ��� 
{
	J j;
	j.top=0;
	int temp;
	while(A)
	{
		j.arr[j.top]=A%B;
		j.top++;
		A=A/B; 
	}
	int len=j.top;
	printf("��Ӧ%d����Ϊ:",B);
	for(int i=0;i<len;i++)
	{   int temp = j.arr[--j.top];
		arr[i]=temp;
		if(temp<=9&&temp>=0) printf("%d",temp);
		if(temp==10)printf("A");
		if(temp==11)printf("B");
		if(temp==12)printf("C");
		if(temp==13)printf("D");
		if(temp==14)printf("E");
		if(temp==15)printf("F");
	} printf("(%d)\n",B);
}
int _10(char str[],int A)//����ΪA���� 
{
	int len,sum=0,a[Max];
	char c;
	len = strlen(str);
	
	for(int i=0;i<len;i++){
		c=str[i];
		if(c>='0'&&c<='9') a[i]=c-'0';
		if('A'<=c&&c<='F') a[i]=c-'0'-7;
	}
	int j=0;
	
	for(int i=len-1;i>=0;i--){
		sum += a[i]*(pow(A,j));
		j++;
	}
	
	return sum;//���ض�Ӧʮ�������� 
}
int main(){
	int A,B;
	printf("��������:");
	char str[Max];
	gets(str);
	printf("========================\n1.�˳�\n2.������\n3.������\n4.�Ľ���\n....\nn.n����\n");
	printf("��ѡ�������:"); 
	scanf("%d",&A);
	if(A==1)
	return 0;
	printf("========================\n1.�˳�\n2.������\n3.������\n4.�Ľ���\n....\nn.n����"); 
	printf("��ѡ��Ҫ���ĵĽ���:");
	scanf("%d",&B);
	if(B==1)
	return 0;
	int sum = _10(str,A);
	printf("��Ӧʮ����Ϊ��%d(10)\n",sum);
	_10_(sum,B);
} 
