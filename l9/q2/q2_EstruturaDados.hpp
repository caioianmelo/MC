#ifndef _ESTRUTURADADOS_HPP
#define _ESTRUTURADADOS_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class EstruturaDados {
	protected:
		int max_chars;
		vector<string> dados;
	
	public:
		EstruturaDados(int max_chars);
		void imprime();
		int tamanho();
		virtual string retira();
		int insere(string s);
		int getMax_chars();
};

#endif
