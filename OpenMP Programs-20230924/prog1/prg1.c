#include<stdio.h>
#include<omp.h>
int lock; // this value is 0 as declared globally
int  main() {
int sum=20;
#pragma omp parallel
{
	while(__sync_val_compare_and_swap(&lock,0,1)); //loop until lock is got
	sum=sum+20;
	printf("SUM %d\n",sum);
	__sync_val_compare_and_swap(&lock,1,0);        //release lock
}
printf("Final SUM %d\n",sum);
}//end main


