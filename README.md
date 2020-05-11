# testgit
![](https://github.com/Gabriel-Marino/testgit/blob/master/safe_image.gif)

![](https://github.com/Gabriel-Marino/testgit/blob/master/square.gif)

```C
#include <stdlib.h>
#include <stdio.h>

#define S 10e15

int main(int argc, char **argv){
  double *f= calloc(S, sizeof(double));
  for(int i= 0; i<= argc; i++){
    f[i]= atof(argv[i]);
  };
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
```JavaScript
fuction main(){
    console.log('Hello World!')
}
```
