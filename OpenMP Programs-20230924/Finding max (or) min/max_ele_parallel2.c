#include <stdio.h>
#include "time.h"
#include <stdlib.h>
#include <omp.h>
#include <stdbool.h>

int main(){
	int n = 10000;
	int arr[n];
	bool flag[n];
	#pragma omp parallel for num_threads(5) shared(arr)
		for(int i = 0; i < n; i++){
			arr[i] = (i + 50)%n;
			flag[i] = true;
		}
	arr[n-1] = 10 * 99 * 100;
	int max_ele; 
	double t1=rtclock();
	
	#pragma omp parallel for num_threads(5) shared(arr)
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(arr[j] < arr[i]) flag[j] = false;
		}
	}
	#pragma omp parallel for num_threads(5) shared(arr)
	for(int i = 0; i < n; i++){
		if(flag[i]){
			max_ele = arr[i];
		}
	}
	
	double t2=rtclock();
	printf("TIME=%f\n", (t2-t1)*1000);
	
	printf("Max ele: %d\n", max_ele);
	return 0;	
}
	
