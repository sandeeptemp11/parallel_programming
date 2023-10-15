#include <stdio.h>
#include "time.h"
#define n 4096*4

int A[n][n];
int B[n][n];
int C[n][n];

int main(int argc, char* argv[]){
	srand(atoi(argv[0]));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			A[i][j] = rand();
			B[i][j] = rand();
			C[i][j] = 0;	
		}
	}
	
}
