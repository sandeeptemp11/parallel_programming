#include<omp.h>
#include<stdio.h>
	int sum=0;
main(){
#pragma omp parallel
	{
		#pragma omp critical
	        {
			sum=sum+10;
			sum=sum+30;
		}
	#pragma omp barrier
	#pragma omp single
		printf("SUM=%d total threads=%d thread-id=%d\n", sum,omp_get_num_threads(), omp_get_thread_num());
	}
}

