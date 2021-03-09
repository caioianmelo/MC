#include <stdio.h>
#include <stdlib.h>

#define N 8
int c = 0, t = 0, cs= 0, ts = 0;

void pv(int *v) { 
	int i;

	for(i = 0; i < N; ++i) printf("%d -> ", v[i]);
	printf("\n");
}

void swapi(int *a, int *b) {
	int c = (*a);
	(*a) = (*b);
	(*b) = c;
}

void ord_sel(int *v, int r) {
	int i, j;

	for(i = 0; i < r; ++i) {
		for(j = 0; j < r; ++j) {
			if(v[i] > v[j] && i < j) { 
				swapi(&v[j], &v[i]); 
				++ts;
			}
			++cs;
		}
	}
}

void ord_ins(int *v, int r, int max, int b) {
	int s;

	if( (r - 1) >= 0 && (v[r-1] > v[r]) ) {
		swapi(&v[r-1], &v[r]);
		++t;
		if(r+1 < max) ord_ins(v, r+1, max, 1);
	}
	if(b == 0 && r > 0) ord_ins(v, r-1, max, b); 
	++c;
}

int main() {
	int v[] = {2, 3, 5, 7, 13, 11, 19, 17};
	int v2[] = {2, 3, 5, 7, 13, 11, 19, 17};
	int i;

	ord_ins(v, N-1, N, 0);
	printf("Ord_Ins:\n");
	pv(v);
	printf("ci: %d, ti: %d\n", c, t);

	ord_sel(v2, N);
	printf("Ord_sel:\n");
	pv(v2);
	printf("cs: %d, ts: %d\n", cs, ts);
	
	return 0;
}
