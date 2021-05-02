#include <stdio.h>
#include <string.h>

typedef struct pessoa {
	char nome[20];
	int idade;
} Pessoa;

void copia(Pessoa *p1, Pessoa *p2) {
	strcpy(p2->nome, p1->nome);
	p2->idade = p1->idade;
}

int main() {
	Pessoa p1, p2;

	strcpy(p1.nome, "Jose Anildo");
	p1.idade = 59;
	copia(&p1, &p2);

	printf("p2_nome: %s, p2_idade: %d\n", p2.nome, p2.idade);

	return 0;
}


// Pois em C, variáveis são passadas por referência, ou seja, são feitas cópias na memória durante a chamada da função e essas cópias que na verdade são utilizadas dentro dela, se não fossem passados os enderecos de memória de p1 e p2 a mudança dentro da função copia não seria persistente.
