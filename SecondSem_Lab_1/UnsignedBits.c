#include <stdio.h>
#include <stdlib.h>

struct number {
	unsigned int variable : 8;
};

union code {
	struct number i;
	struct {
		unsigned a0 : 1;
		unsigned a1 : 1;
		unsigned a2 : 1;
		unsigned a3 : 1;
		unsigned a4 : 1;
		unsigned a5 : 1;
		unsigned a6 : 1;
		unsigned a7 : 1;
	}byte;
};


int main(void) {
	struct number var_s = { 100 };
	union code var_u;
	var_u.i = var_s;
	printf("Bits\n");
	printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 7, 6, 5, 4, 3, 2, 1, 0, var_u.byte.a7, var_u.byte.a6, var_u.byte.a5, var_u.byte.a4, var_u.byte.a3, var_u.byte.a2, var_u.byte.a1, var_u.byte.a0);
	printf("\nMost significant 2 bits: %d\t%d", var_u.byte.a7, var_u.byte.a6);
}