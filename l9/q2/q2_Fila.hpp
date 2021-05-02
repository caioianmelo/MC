#ifndef _FILA_CPP
#define _FILA_CPP

#include <iostream>
#include <vector>
#include <string>
#include "EstruturaDados.hpp"

using namespace std;

class Fila : public EstruturaDados {
	public:
		Fila(int max_chars);
		string retira();
};

#endif
