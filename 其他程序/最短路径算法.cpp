#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#define M 6

int connect[M][M]={{1,1,1,0,0,1},{1,1,1,1,0,0},{1,1,1,1,0,1},{0,1,1,1,1,0},{0,0,0,1,1,1},{1,0,1,1,1,1}};
int distance[M][M]={{0,7,9,0,0,14},{7,0,10,15,0,0},{9,10,0,11,0,14},{0,15,11,0,6,0},{0,0,0,6,0,9},{14,0,14,0,9,0}};

int minD(int a,int b)
{
	int longth;
	int i,j;
	for(i=a;i<M;i++)
	for(j=0;j<M;j++){
		if()
	}
}

int main(){
	int connect[M][M]={{1,1,1,0,0,1},{1,1,1,1,0,0},{1,1,1,1,0,1},{0,1,1,1,1,0},{0,0,0,1,1,1},{1,0,1,1,1,1}};
	int distance[M][M]={{0,7,9,0,0,14},{7,0,10,15,0,0},{9,10,0,11,0,14},{0,15,11,0,6,0},{0,0,0,6,0,9},{14,0,14,0,9,0}};
	
	return 1;
} 
