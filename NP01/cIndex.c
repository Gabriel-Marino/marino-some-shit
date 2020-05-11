#include <stdio.h>
#include <stdlib.h>

#define S 100000000

int main(int argc, char **argv){
    printf("Hello World!\n");
    double *f= calloc(S, sizeof(double));
    int i;

    for (i= 1; i< argc; i++){
        f[i-1]= atof(argv[i]);
    };

    for (i= 0; i< argc-1; i++){
        printf("%e\n", f[i]);
    };

    free(f);
    return 0;
};
