#include <stdio.h>
#include <stdlib.h>

int c = 0, t = 0;

void pv(int *v) { 
	int i;

	for(i = 0; i < 8; ++i) printf("%d -> ", v[i]);
	printf("\n");
}

void ord_ins(int *v, int r, int max, int b) {
	int s;

	if( (r - 1) >= 0 && (v[r-1] > v[r]) ) {
		s = v[r];
		v[r] = v[r-1];
		v[r-1] = s;
		++t;
		if(r+1 < max) ord_ins(v, r+1, max, 1);
	}
	if(b == 0 && r > 0) ord_ins(v, r-1, max, b);
	++c;
}

int main() {
	int v[] = {2, 3, 5, 7, 13, 11, 19, 17};
	int i;

	pv(v);
	ord_ins(v, 7, 8, 0);

	pv(v);
	printf("c: %d, t: %d\n", c, t);
	return 0;
}
