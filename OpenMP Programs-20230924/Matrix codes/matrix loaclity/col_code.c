#include <stdio.h>
#define n 4096
int A[n][n];
int B[n][n];
int C[n][n];

int main(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) C[j][i] = A[j][i] + B[j][i];
	}
	return 0;
}
