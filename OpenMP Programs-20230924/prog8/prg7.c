#include <stdio.h>
#include <omp.h>

int main (void)
{
    int i = 10,j=10;

    #pragma omp parallel private(i) firstprivate(j) num_threads(5)
    {
        printf("thread %d: i = %d j=%d\n", omp_get_thread_num(), i,j); // i - unintialized, j - initialized
        i =i+ omp_get_thread_num();
        j += 100;
    }
    
    printf("i = %d, j = %d\n", i, j);

   #pragma omp parallel for lastprivate(i) 
      for (i=0; i<20; i++);
        
    printf("i = %d\n", i);
    return 0;
}
