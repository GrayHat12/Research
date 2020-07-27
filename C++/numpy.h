#include <time.h>
#include <stdlib.h>

double randn()
{
    srand(time(NULL));
    double sign = (double)rand()/(double)(RAND_MAX);
    double value = ((double)rand()) / ((double)(RAND_MAX)) * 2;
    return value - 1;
}