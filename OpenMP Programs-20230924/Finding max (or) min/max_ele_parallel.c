#include <stdio.h>
#include "time.h"
#include <stdlib.h>
#include <omp.h>

int main(){
	omp_lock_t writelock;
	omp_init_lock(&writelock);
	int n = 10000;
	int arr[n];
	#pragma omp parallel for num_threads(5) shared(arr)
		for(int i = 0; i < n; i++) arr[i] = (i + 50)%n;
	
	arr[n-1] = 10 * 99 * 100;
	double t1=rtclock();
	int max_ele = -1;

	#pragma omp parallel for num_threads(5) shared(arr)
	for(int i = 0; i < n; i++){
		omp_set_lock(&writelock);
		if(max_ele < arr[i]) max_ele = arr[i];
		omp_unset_lock(&writelock);
	}
	double t2=rtclock();
	printf("init TIME=%f\n", (t2-t1)*1000);
	
	printf("Max ele: %d\n", max_ele);
	return 0;	
}
	
