#include "Pilha.hpp"

using namespace std;

Pilha::Pilha(int max_chars) {
	this->max_chars = max_chars;
}

void Pilha::imprime() {
	int i;

	cout << "Print: ";
	if(!dados.empty()) {
		for(i = 0; i < dados.size(); ++i) 
			cout << ' ' << dados[i] << "->";

		cout << endl;
	}
	else cout << "Empty Stack!\n";
}
int Pilha::tamanho() {
	return dados.size();
}

string Pilha::retira() {
	string b;

	if(!dados.empty()) {
		b = dados.back();
		dados.pop_back();
	}
	else b = "Empty Stack!";

	return b;
}

int Pilha::insere(string s) {
	bool i;
	
	i = s.length() <= getMax_chars();
	if(i) dados.push_back(s);

	return i;
}

int Pilha::getMax_chars() { return max_chars; }
