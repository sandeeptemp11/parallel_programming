#include <stdio.h>
#include "time.h"

int main(){
	int n = 10000;
	int arr[n];
	#pragma omp parallel for num_threads(5)
		for(int i = 0; i < n; i++) arr[i] = (i + 50)%n;
	double t1=rtclock();
	int max_ele = -1;
	for(int i = 0; i < n; i++){
		if(max_ele < arr[i]) max_ele = arr[i];
	}
	double t2=rtclock();
	printf("init TIME=%f\n", (t2-t1)*1000);
	
	printf("Max ele: %d\n", max_ele);
	return 0;	
}
	
