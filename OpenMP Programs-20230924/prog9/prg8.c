#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int a = 12345;
#pragma omp threadprivate(a)
int main(int argc, char* argv[])
{
	// Turn off dynamic threads as required by threadprivate
	omp_set_dynamic(0);
	omp_set_num_threads(4);
	#pragma omp parallel copyin(a)
	{
		#pragma omp master
		{
			printf("master thread sets  a to 67890.\n");
			a = 67890;
		}
 
		#pragma omp barrier
 
		printf("parallel region one Thread %d: a = %d.\n", omp_get_thread_num(), a);
	}
 
	#pragma omp parallel copyin(a)
	{
		printf("parallel region two Thread %d: a = %d.\n", omp_get_thread_num(), a);
	}
 
	return EXIT_SUCCESS;
}
