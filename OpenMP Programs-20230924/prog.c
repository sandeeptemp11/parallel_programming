#include <stdio.h>
#include <omp.h>

int main(){
	int sum = 0;
	int arr[] = {1, 2, 3};
	
	#pragma omp parallel for // private(sum)
	for(int i = 0; i < 3; i++){
		sum = sum + arr[i];
	}
	printf("%d ", sum);
}
