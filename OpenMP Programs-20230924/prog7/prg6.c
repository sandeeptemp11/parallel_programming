#include<stdio.h>
#include<omp.h>
int main()
{
	omp_set_num_threads(100);
#pragma omp parallel for schedule(guided,3) num_threads(4)
	for (int i = 0; i < 24; i++)
	{
		printf("Thread %d is running number %d\n", omp_get_thread_num(), i);
	}
	return 0;
}
