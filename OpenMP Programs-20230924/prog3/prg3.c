#include<omp.h>
#include<stdio.h>
main(){
	int sum=0;
	omp_set_num_threads(10);//total threads in parallel region is 10
	#pragma omp parallel
	{
		#pragma omp atomic
			sum=sum+20;
		#pragma omp barrier
			// all threads executed sum=sum+20
		
		// sum becomes 200
		#pragma omp master
		{
			// only executed by master thread
			sum += 20;
			printf("SUM=%d total threads=%d thread-id=%d\n", sum,omp_get_num_threads(), omp_get_thread_num());
		}
		// sum = 220
	}//end omp parallel
	// sum = 220
}

