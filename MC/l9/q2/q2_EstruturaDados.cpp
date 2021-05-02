#include "EstruturaDados.hpp"

using namespace std;

EstruturaDados::EstruturaDados(int max_chars) { this->max_chars = max_chars; }

void EstruturaDados::imprime() {
	int i;

	cout << "Print: ";
	if(!dados.empty()) {
		for(i = 0; i < dados.size(); ++i) cout << ' ' << dados[i] << "->";
		cout << endl;
	}
	else cout << "Empty Stack!\n";
}

int EstruturaDados::tamanho() { return dados.size(); }

string EstruturaDados::retira() {
	string b;

	if(!dados.empty()) {
		b = dados.back();
		dados.pop_back();
		return b;
	}
	else b = "Empty!";

	return b;
}

int EstruturaDados::insere(string s) {
	bool i;
	
	i = s.length() <= getMax_chars();
	if(i) dados.push_back(s);

	return i;
}

int EstruturaDados::getMax_chars() { return max_chars; }
