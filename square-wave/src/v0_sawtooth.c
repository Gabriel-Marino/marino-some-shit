//	Created		:	2020.04.13
//	Last update	:	2020.04.19
//	Author		:	Marino
//	Notes		:	Calucates a series of a sawtooth wave, main fuction
//	Compilation	:	make
//	Execution	:	time ./serie.out <number> <frequency>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void op(int t, double x, double y);

int main(int argc, char **argv){
//	Program execution codition
	if (argc != 2 && (argc < 2 || argc > 3)){
		printf("\nTo execute the programa %s is need to write:\n\n	time %s <number> <frequency>\n#by default frequency is 1\n", argv[0], argv[0]);
		exit(1);
	};

	int t, tf= atoi(argv[1]);
	int f= (argc == 3) ? atoi(argv[2]) : 1;
	double x, y, pi= M_PI;
	// FILE *file= fopen("dat/serie-0.dat", "w");

	for(x= -5; x< 5; x+= 0.01){
		y= 0.0;
		for(t= 0; t< tf; t++){
			y+= (sin(f*(t+1)*pi*x))/(t+1);
			if (t == t){
				y*= 4/pi;
				op(t, x, y);
				y/= 4/pi;
			};
		};
		// y*= 4/pi;
		// fprintf(file, "%e %e\n", x, y);
	};

	// fclose(file);
	return 0;
};