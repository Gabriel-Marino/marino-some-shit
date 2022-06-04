//criado em				:	2020.03.03
//ult. atualização			:	2021.02.17
//autor					:	Marino <ra115114@uem.br>
//notas					:	Calcula o valor estimado de pi pelo metodo de Monte Carlo

#include "../head.h"

int main(int argc, char **argv){
	double pi, x, y;
	double c_pt, t_pt;
	int t, n= atoi(argv[1]);
	FILE *file= fopen("dat/pi.dat", "w");
	gsl_rng_default_seed= (argc == 3) ? atoi(argv[2]) : time(NULL);
	gsl_rng *w= gsl_rng_alloc(gsl_rng_taus);

// 	time_t tempo= time(NULL);
// 	struct tm tm= *localtime(&tempo);
// 	FILE *arq= fopen("seed.dat", "a");
// 	fprintf(arq, "%d.%02d.%02d_%02d:%02d:%02d_seed= %lu%c\n", tm.tm_year +1900, tm.tm_mon +1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, gsl_rng_default_seed, 59);
// 	fclose(arq);

	for(t= 0; t< n; t++){
		x= gsl_rng_uniform(w)*1;
		y= gsl_rng_uniform(w)*1;
		fprintf(file, "%lf	%lf\n", x, y);
		t_pt+= 1;
		if(sqrt(x*x+y*y)<= 1){
			c_pt+= 1;
		};
		if(n%(n/100)==0){
			printf("%d%%\n", t/(n/100));
		};
	};
	pi= 4*(c_pt/t_pt);
	printf("The estimate valeu of pi is %lf\n", pi);

	gsl_rng_free(w);
	fclose(file);
	return 0;
}
