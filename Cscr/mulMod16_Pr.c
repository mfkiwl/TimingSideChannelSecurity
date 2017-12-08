#include<math.h>
#include<time.h>
#include<stdint.h>
#include<stdio.h>
#include"Cilib/cusint.h"

static inline uint64_t rdcyc() {
  uint64_t val;
  asm volatile ("rdcycle %0 ;\n":"=r" (val) ::);
  return val;
}

int mulMask 	= 0x0ffff;
int mulModulus	= 0x10001;
long int mulMod16(long int a, long int b) {
	long int p;
	int volatile aa, bb;
	a &= mulMask;
	b &= mulMask;
	if (a == 0) {
		aa= a;
		bb= b;
		a = mulModulus - a;
		//p = a * b;
		CiMult(p, a, b);
		b = p & mulMask;
		a = p >> 16;
		a = b - a + (b < a ? 1 : 0);
		a = aa;
		b = bb;
		a = mulModulus - b;
		//CiAddi(a, mulModulus, -b);
	} else if (b == 0) {
		aa= a;
		bb= b;
		a = mulModulus - b;
		//p = a * b;
		CiMult(p, a, b);
		b = p & mulMask;
		a = p >> 16;
		a = b - a + (b < a ? 1 : 0);
		a = aa;
		b = bb;
		a = mulModulus - a;
		//CiAddi(a, mulModulus, -a);
	} else {	
		aa= a;
		bb= b;
		a = mulModulus - b;
		//CiAddi(b, mulModulus, -a);
		a = aa;
		b = bb;
		//p = a * b;
		CiMult(p, a, b);
		b = p & mulMask;
		a = p >> 16;
		a = b - a + (b < a ? 1 : 0);
	}
	return a & mulMask;
}

int main(int argc, char *argv[]) {
	long int a= atoi(argv[1]);
	int num= atoi(argv[2]);

	uint64_t t_beg,t_end;

	int r;
	long int b =0x0a0a0a0a;

//	int a1=0xcafe0000; 	
//	int a2=0xbeefcafe;	

	t_beg 	= rdcyc();
	r 		= mulMod16(a, b);
	t_end 	= rdcyc();
	
	if (num==2) {
		printf("mulMod16(%d, %d) = %d\n", a, b, r);
	}
	printf("(%d, %d)\n", num, t_end-t_beg);

	return 0;
}
