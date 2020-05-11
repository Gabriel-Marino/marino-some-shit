// criado em		:	2020.03.28;
// utl. atualização	:	2020.04.01;
// autor			:	Gabriel Marino de Oliveira <gcmarino404@gmail.com>, <ra115114@uem.br>;
// notas			:	Gera pontos aletórios igualmete distrubuidos sobre uma esfera, função principal.

#include "../head.h"

void op(int i, double x, double y, double z, char *name);

int main(int argc, char **argv){
//	condição de execução do programa;
	if(argc != 2){
		printf("Para executar o programa %s é necessário digitar:\n\n	time %s <número de pontos>\n", argv[0], argv[0]);
		exit(1);	//função para cancelar a execução do programa caso a condição necessária não for cumprida;
	};

	int n= atoi(argv[1]), i, r;
	double u, v, x, y, z, phi, theta, X, Y, Z, x_cm, y_cm, z_cm;
//	gerador de números pseudo-aleatórios;
	gsl_rng_default_seed= (argc == 3) ? atoi(argv[2]) : time(NULL);	//sememnte do gerador, diz "se argc for igual a 3 então utiliza argv na posição 2 como um inteiro, se não utilize o tempo NULL"
	gsl_rng *w= gsl_rng_alloc(gsl_rng_taus);						//inicializador do gerador

	r= 1;									//raio da esfera;
	for(i= 0; i< n; i++){					//i é o indice e n é o número total de pontos;
		u= gsl_rng_uniform(w);				//função para gerar números reais psudo-aleatórios no intervalo de [0, 1)
		v= gsl_rng_uniform(w);
		phi= acos(2*v-1);					//condição para gerar pontos uniformimente distribuidos sobre a superfíci da esfera para phi;
		theta= 2*M_PI*u;					//condição para gerar pontos uniformimente distribuidos sobre a superfíci da esfera para theta;
		x= r*sin(theta)*cos(phi);			//coordenada esférica para x;
		y= r*sin(theta)*sin(phi);			//coordenada esférica para y;
		z= r*cos(theta);					//coordenada esférica para z;
		op(0, x, y, z, "dat/pontos.dat");	//função output recebe x, y e z e retorna um arquivo com as coordenadas de todos os pontos;
		X+= x;								//soma de todas coordenadas de x;
		Y+= y;								//soma de todas coordenadas de y;
		Z+= z;								//soma de todas coordenadas de z;
		x_cm= X/(i+1);						//coordenada x do centro de massa;
		y_cm= Y/(i+1);						//coordenada y do centro de massa;
		z_cm= Z/(i+1);						//coordenada z do centro de massa;
		op((i+1), x_cm, y_cm, z_cm, "dat/cm.dat");
		if(i%(n/100)==0){					//condição de progressão da execução do programa;
				printf("%d%%\n", i/(n/100));
		};
	};
	printf("The shit is done.");			//condição para informar que o programa foi executado em sua totalidade;
	gsl_rng_free(w);						//função para liberar a memória alocada para o vetor w que armazena o gerador de números psudo-aleatórios;
	return 0;
};