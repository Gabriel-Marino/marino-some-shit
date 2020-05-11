// criado em		:	2020.03.29;
// utl. atualização	:	2020.03.31;
// autor			:	Gabriel Marino de Oliveira <gcmarino404@gmail.com>, <ra115114@uem.br>;
// notas			:	Gera pontos aletórios igualmete distrubuidos sobre uma esfera, função de saída.

#include "../head.h"

void op(int i, double x, double y, double z, char *name){
	char nome[100];
	sprintf(nome, name, i);
	FILE *file= fopen(nome, "a");
	fprintf(file, "%d %e %e %e\n", i, x, y, z);
	fclose(file);
};