#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    printf("Hello World!\n");
    int i, S= argc;
    double *f= calloc(S, sizeof(double));

    for (i= 1; i< argc; i++){
        f[i-1]= atof(argv[i]);
    };

    for (i= 0; i< argc-1; i++){
        printf("%e\n", f[i]);
    };

    free(f);
    return 0;
};