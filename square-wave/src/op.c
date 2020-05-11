//	Created		:	2020.04.13
//	Last update	:	2020.04.13
//	Author		:	Marino
//	Notes		:	Calucates a series of a square wave, output fuction

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void op(int t, double x, double y){
	char name[100];
	sprintf(name, "dat/serie-%d.dat", t+1);
	FILE *file= fopen(name, "a");
	fprintf(file, "%e %e\n", x, y);
	fclose(file);
};