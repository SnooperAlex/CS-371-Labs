#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constituency.h"



void constructConstituency(struct Constituency * const obj, char const *name,
    unsigned int* const neighbours,unsigned int numNeighbours){

        obj->name = NULL;
        obj->neighbours = NULL;
        obj->numNeighbours = 0;

        obj->name = (char*) malloc((strlen(name)+1) * sizeof(char));
        memcpy(obj->name, name, (strlen(name)+1) * sizeof(char));

        obj->neighbours = (unsigned int*) malloc(numNeighbours * sizeof(unsigned int));
        memcpy(obj->neighbours, neighbours, numNeighbours * sizeof(unsigned int));

        obj->numNeighbours = numNeighbours;

    };

void destructConstituency(struct Constituency * const obj){
    free(obj->name);
    obj->name = NULL;
    
    free(obj->neighbours);
    obj->neighbours = NULL;
    obj->numNeighbours = 0;
};

void printConstituency(struct Constituency * const obj){
    printf("%s |", obj->name);
    printf(" %u neighbours | ", obj->numNeighbours);
    printf("[ ");
    for (unsigned int i = 0; i < obj->numNeighbours; i++) {
        printf(" %u ", obj->neighbours[i]);
    }
    printf("]");
    printf("\n");
};