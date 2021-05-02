#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100
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

int find_min(int *v, int p, int s) {
	int i, m = p;

	for(i = p; i < s; ++i) {
		if(v[m] > v[i]) m = i;
		++cs;
	}

	return m;
}

void ord_sel(int *v, int r) {
	int i, j, m;

	for(i = 0; i < r; ++i) {
		m = find_min(v, i, r);
		swapi (&v[i], &v[m]);
		++ts;
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

void init_vector(int *v) {
	int i;

	for(i = 0; i < N; ++i) v[i] = rand() % (10*N);
}

int main() {
	int i;
	int v[N], v2[N];

	srand(time(NULL));

	init_vector(v);
	init_vector(v2);

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
