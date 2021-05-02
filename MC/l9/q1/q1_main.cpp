#include <iostream>
#include "Pilha.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

#define N 20
using namespace std;

string randomString() {
	int i, rsize = rand()%25 + 1, rc;
	string s;

	for(i = 0; i < rsize; ++i) {
		rc = rand()%('Z'-'A') + 'A';
		s.insert(s.end(), 1, rc);
	}

	return s;
}

int main() {
	Pilha p(N); 
	srand(time(NULL));
	string rs;
	int i;

	cout << "String Max Size: " << N << endl;
	for(i = 0; i < 20; ++i) {
		rs = randomString();
		if( !p.insere(rs) ) cout << "Not added string of size: " << rs.size() << endl;
	}

	cout << "Stack Size: " << p.tamanho() << endl;
	p.imprime();
	cout << endl;

	cout << "Pop: ";
	for(i = 0; i < 6; ++i)
		cout  << " <- " << p.retira();

	cout << endl << "Stack Size: " << p.tamanho() << endl;
	p.imprime();

	return 0;
}
