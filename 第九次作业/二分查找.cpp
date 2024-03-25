#include<iostream>
#define Maxsize 100
using namespace std;

int BinarySearch(int List[],int e)
{
	int length = sizeof(List)/sizeof(int);
	int low = 0, high = length - 1;
	int mid;
	
	while(high >= low)
	{
		mid = (high + low) / 2;
		if (List[mid] > e) high = mid -1;
		else if (List[mid] < e) low = mid +1;
		else return mid; 
	}
	return 0;
}

int main(){
	int list[Maxsize];
	int n,e;
	cout<<"请输入数据个数：";
	cin>>n;
	for(int i = 0;i < n;++i)
		cin>>list[i];
	
	cout<<"请输入要查找的数：";
	cin>>e;
	printf("%d",BinarySearch(list,e));
	
	return 0;
}
/*
20
1 2 3 4 5 6  7 8 9 10 11 12 13 14 15 16 17 18 19 20
2 
*/

