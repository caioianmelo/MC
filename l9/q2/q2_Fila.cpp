#include "Fila.hpp"

Fila::Fila(int max_chars) : EstruturaDados(max_chars) {}

string Fila::retira() {
	string b;

	if(!dados.empty()) {
		b = dados.front();
		dados.erase(dados.begin());
		return b;
	}
	else b = "Empty!";

	return b;
}
