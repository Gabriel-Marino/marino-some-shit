#include <stdio.h>
#include <stdlib.h>

#define S 10e15

int main(int argc, char **argv){
    printf("Hello World!\n");
    double *f= calloc(S, sizeof(double));
    int i;

    for (i= 0; i< argc; i++){
        f[i]= atof(argv[i+1]);
    };

    for (i= 0; i< argc; i++){
        printf("%e\n", f[i]);
    };

    free(f);
    return 0;
};