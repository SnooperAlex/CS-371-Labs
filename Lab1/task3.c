#include <stdio.h>
#include<stdlib.h>
#include "fibonacci.h"


int main(int argc, char* argv[]) { 
    if(argc > 1){
        int num = atoi(argv[1]); 
        int result = fibonacci(num); 
        printf("Fibonacci of %d = %d\n", num, result); 
    }else if(argc == 1) {
        printf("Invalid");
    } 
    return 0;
} 
