#include<omp.h>
#include<stdio.h>
main(){
	int sum=0;
#pragma omp parallel num_threads(10)
{
#pragma omp atomic
		sum=sum+20;
		
}
	printf("SUM=%d\n", sum);
}

