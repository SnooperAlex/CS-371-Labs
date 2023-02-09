#include <stdio.h>
#include "arrays.h"

int i, sum, mean_v;


double mean(int length, int *arr){
    for(i = 0; i < length; i++){
        sum = arr[i] + sum;
    }
    mean_v = sum / length;
    return mean_v;
}