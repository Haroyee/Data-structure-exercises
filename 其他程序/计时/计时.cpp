#include<stdio.h>
#include<sys/time.h>

int main()
{
	struct timeval start,end;
	
	gettimeofday(&start,NULL);
	
	printf("\n");
	
	gettimeofday(&end,NULL);
	
	printf("%0.8lf",(start.tv_sec-end.tv_sec)+(double)(start.tv_usec-end.tv_usec)/1000000.0);
	return 0;
}
