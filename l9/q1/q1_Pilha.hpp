#ifndef _PILHA_CPP
#define _PILHA_CPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pilha {
	private:
		int max_chars;
		vector<string> dados;
	
	public:
		Pilha(int max_chars);
		void imprime();
		int tamanho();
		string retira();
		int insere(string s);
		int getMax_chars();
};

#endif
