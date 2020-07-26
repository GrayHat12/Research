#include <stdio.h>
#include "numpy.h"

void main() {
    double value = randn();
    int i=0;
    while (value > (double)(0)){
        value = randn();
        i+=1;
    }
    printf("%lf : %d",value,i);
}