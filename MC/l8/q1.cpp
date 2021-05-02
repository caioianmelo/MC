#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void
is_prog(vector<float> v) {
	bool a = 1, g = 1;	
	int i, j, r;

	j = v[1] - v[0];
	r = v[1] / v[0];
	for(i = 2; i < v.size() && (a || g); ++i) {
		a = a && v[i] == v[0] + j*i;
		g = g && v[i] == v[0]*pow(r, i);
	}

	if(a) cout << "É progressão aritmética!" << endl;
	if(g) cout << "É progressão geométrica!" << endl;
	if(!(a || g)) cout << "Não é progressão" << endl;
}

int main() {
	int i, n;
	vector<float> v;

	cin >> n;
	v.resize(n);

	for(i = 0; i < n; ++i)
		cin >> v[i];

	is_prog(v);

	return 0;
}
