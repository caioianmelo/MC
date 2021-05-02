#include <iostream>
#include "Pilha.hpp"
#include "Fila.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

#define N 20
using namespace std;

string randomString() {
	int i, rsize = rand()%25+1, rc;
	string s;

	for(i = 0; i < rsize; ++i) {
		rc = rand()%('Z'-'A') + 'A';
		s.insert(s.end(), 1, rc);
	}

	return s;
}

int main() {
	EstruturaDados *p = new Pilha(N); 
	EstruturaDados *f = new Fila(N); 
	srand(time(NULL));
	string rs;
	int i;

	cout << "Max String Size: " << N << endl;

	cout << string(50, '-') << "Pilha" << string(49, '-') << endl;
	for(i = 0; i < 20; ++i) {
		rs = randomString();
		if( !p->insere(rs) ) cout << "Not Added String of Size: " << rs.size() << endl;
	}

	cout << "Stack Size: " << p->tamanho() << endl;
	p->imprime();

	for(i = 0; i < 6; ++i)
		cout << "Pop: " << p->retira() << endl;
	cout << "Tamanho: " << p->tamanho() << endl;
	p->imprime();
	
	cout << string(50, '-') << "Fila" << string(49, '-') << endl;

	for(i = 0; i < 20; ++i) {
		rs = randomString();
		if( !f->insere(rs) ) cout << "Not Added String of Size: " << rs.size() << endl;
	}

	cout << "FIFO Size: " << f->tamanho() << endl;
	f->imprime();

	for(i = 0; i < 6; ++i)
		cout << "Pop: " << f->retira() << endl;
	cout << "Tamanho: " << f->tamanho() << endl;
	f->imprime();

	delete(f);
	delete(p);

	return 0;
}
