#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include"time.h"
int A[8092][8092],B[8092][8092], C[8092][8092];

int main(int argc, char *argv[]){
	srand(atoi(argv[1]));
        //initialize matrices A and B
	double t1=rtclock();
     //#pragma omp parallel for num_threads(8) schedule(static, 1024) shared(A,B,C) 
     #pragma omp parallel for 
	for(int i=0;i<8092;i++){
            for(int j=0;j<8092;j++){
		     A[i][j]=i+j;
		     B[i][j]=i+j;
	    }//end loop j
	}//end loop i
	double t2=rtclock();
	printf("init TIME=%f\n", (t2-t1)*1000);

	//add matrices A and B and store it in matrix C
	double t3=rtclock();
//#pragma omp parallel for num_threads(12) schedule(static,512) shared(A,B,C) 
     #pragma omp parallel for 
	for(int i=0;i<8092;i++){
            for(int j=0;j<8092;j++){
		     C[i][j]=A[i][j]+B[i][j];
	    }
	}
	double t4=rtclock();
	printf("compute TIME=%f\n", (t3-t4)*1000);
	return 0;
}

