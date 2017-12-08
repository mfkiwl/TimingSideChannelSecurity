#include<math.h>
#include<time.h>
#include<stdint.h>
#include<stdio.h>

static inline uint64_t rdcyc() {
  uint64_t val;
  asm volatile ("rdcycle %0 ;\n":"=r" (val) ::);
  return val;
}

long long int modExp(long long int y, long long int k) {
	long long int n=1065023;
	long long int r = 1;

	for (int i = 0; i < 64; i++) {
		if (k % 2 == 1) {
			r = r * y;
			r = r % n;
		}
		y = y * y;
		y = y % n;
		k >>= 1;
	}
	return r % n;
}

int main(int argc, char *argv[]) {
	long long int key= atoi(argv[1]);
	int num= atoi(argv[2]);

	uint64_t t_beg,t_end;

	long long int r;
	long long int y =99;

	//printf(" arg (%d, %d)\n", key, test);
// 	long long int k1=1029199; 	//Oxfb44f Hamming weight = 13
//	long long int k2=361241;	//Ox58319 Hamming weight = 8

	t_beg 	= rdcyc();
	r 		= modExp(y, key);
	t_end 	= rdcyc();

	if (num==2) {
		printf("modExp(%d, %d) = %d\n", y, key, r);
	}
	printf("(%d, %d)\n", num, t_end-t_beg);
	
	return 0;
}
