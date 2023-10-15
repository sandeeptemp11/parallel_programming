#include <stdio.h>
#include <sys/time.h>

int main(){
	struct tms buf;
	times(&buf);
	
	printf("%d ", buf.tms_utime);
	printf("%d ", buf.tms_stime);
	
	return 0;
}
