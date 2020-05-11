# Hello World!
```C
#include <stdio.h>
int main(){
    printf("Hello World!\n");
    return 0;
};
```
```Python
def main():
    print("Hello World!")

if __name__ == "__main__":
    main()
```
```JavaScript
function main() {
    console.log("Hello World!")
}

main()
```

![](https://github.com/Gabriel-Marino/testgit/blob/master/safe_image.gif)

```C
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
  int i, S= argc;
  double *f= calloc(S, sizeof(double));
  for(i= 1; i< argc; i++){
    f[i-1]= atof(argv[i]);
  };
  free(f);
  return 0;
};
```
```Python
from sys import argv

def main():
f= []
for i in argv:
    f.appende(float(argv[i]))
```

![y=\frac{4}{\pi}\cdot\sum_{n=0}^{\infty}\frac{\sin(f\cdot(2\cdot n+1)\cdot x\cdot\pi)}{2\cdot n+1}](https://render.githubusercontent.com/render/math?math=y%3D%5Cfrac%7B4%7D%7B%5Cpi%7D%5Ccdot%5Csum_%7Bn%3D0%7D%5E%7B%5Cinfty%7D%5Cfrac%7B%5Csin(f%5Ccdot(2%5Ccdot%20n%2B1)%5Ccdot%20x%5Ccdot%5Cpi)%7D%7B2%5Ccdot%20n%2B1%7D)

![Result of the serie above w/ f=2](https://github.com/Gabriel-Marino/testgit/blob/master/square-wave/square.gif)
