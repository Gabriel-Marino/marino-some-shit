/**
 *  Creadted    :   2021.03.05;
 *  Last Update :   2021.03.07;
 *  Author      :   Gabriel Marino <gcmarino404@gamil.com>;
 *  Notes       :   Based on material of Professor Breno Ferraz, PhD <breno@dfi.uem.br>;
 *              :   This program solve numerically Lotka-Volterra equations with fourth order Runge-Kutta method.
 * Compilation  :   gcc -O3 lotka-volterra.c -o lotka-volterra.out
 * Execution    :   ./lotka-volterra.out <x0> <y0> <a> <b> <d> <g> <tf> <dt> <np>
 *              :   is possible to execute without specify any parameter, once i alredy have state some parameters;
 */

#include <stdio.h>
#include <stdlib.h>

//  first equation of the par from Lotka-Volterra equations;
double fx(double x, double y, double a, double b) {
	//  dx/dt= a*x-b*x*y
	return (a*x - b*x*y);
};
//  second equation of the par from Lotka-Volterra equations;
double fy(double x, double y, double d, double g) {
	//  dx/dt= -d*x+g*x*y
	return (-g*y + d*x*y);
};

int main(int argc, char **argv) {

	double  x  = 1.0,				//  represent the density of preys;
		y  = 2.0,				//  represent the density of predators;
		a  = 1.0,				//  equivalent to alpha in Lotka-Volterra eq.;
		b  = 1.0,				//  equivalent to beta  in Lotka-Volterra eq.;
		d  = 1.0,				//  equivalent to delta in Lotka-Volterra eq.;
		g  = 1.0,				//  equivalent to gamma in Lotka-Volterra eq.;
		t  = 0.0,				//  time;
		tf = 1e2,				//  final time;
		dt = 1e-1,				//  difeential of time between steps;
		np = 1e3,				//  total number of point;
		px0, px1, px2, px3,			//  intermediary step of Runge-Kutta technique for x;
		py0, py1, py2, py3;			//  intermediary step of Runge-Kutta technique for y;
	int i, j, extcode;

	FILE *file = fopen("lv.dat", "w");

	x  = (argc == 2)  ? atof(argv[1]) : x;
	y  = (argc == 3)  ? atof(argv[2]) : y;
	a  = (argc == 4)  ? atof(argv[3]) : a;
	b  = (argc == 5)  ? atof(argv[4]) : b;
	d  = (argc == 6)  ? atof(argv[5]) : d;
	g  = (argc == 7)  ? atof(argv[6]) : g;
	tf = (argc == 8)  ? atof(argv[7]) : tf;
	dt = (argc == 9)  ? atof(argv[8]) : dt;
	np = (argc == 10) ? atof(argv[9]) : np;

	//	Warning of the parameters that the program receive and the standard parameters hardcoded;
	argc < 10 ? printf("\nThis program receive the following parameters:\n\n %s <x0> <y0> <a> <b> <d> <g> <tf> <dt> <np>\n\n, if you choose to not especify them so the program will run with the standard parameters:\n\n %s 1.0 2.0 1.0 1.0 1.0 1.0 10000 0.1 1000\n\n", argv[0], argv[0]) : printf("Good you have especified every parameter! :)");
	//	Just a precaution to confirm that user will read the last warning, and giving an oportunity to stop the program and change the parameters;
	printf("Type 1 to proceed or type 0 to end the program: ");
	scanf("%d", &extcode);
	if (!extcode) exit(extcode);

	const int n = (tf-t)/(np*dt);	//  space between each point which will be plotted;
	for (i = 0; i < np; i++) {
		fprintf(file, "%e %e %e\n", t, x, y);
		for (j = 0; j < n; j++) {
			px0 = fx(x, y, a, b);
			py0 = fy(x, y, d, g);
			px1 = fx(x + 0.5*dt*px0, y + 0.5*dt*py0, a, b);
			py1 = fy(x + 0.5*dt*px0, y + 0.5*dt*py0, d, g);
			px2 = fx(x + 0.5*dt*px1, y + 0.5*dt*py1, a, b);
			py2 = fy(x + 0.5*dt*px1, y + 0.5*dt*py1, d, g);
			px3 = fx(x + dt*px2, y + dt*py2, a, b);
			py3 = fy(x + dt*px2, y + dt*py2, d, g);
			x += dt*(px0+2.0*px1+2.0*px2+px3)/6.0;
			y += dt*(py0+2.0*py1+2.0*py2+py3)/6.0;
			t += dt;
		};
		if (i%((int)np/100) == 0) {
			printf("%.2f%%\n", i/(np/100));
		};
	};

	fclose(file);
	return 0;
};
