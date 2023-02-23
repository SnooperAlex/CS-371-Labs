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

struct Constituency* copyConstituencies(struct Constituency constituencies[], unsigned int const numConstituencies) {
  struct Constituency* copy = malloc(sizeof(struct Constituency) * numConstituencies);

  for (int i = 0; i < numConstituencies; i++) {
    copy[i].name = malloc(strlen(constituencies[i].name) + 1);
    strcpy(copy[i].name, constituencies[i].name);
    copy[i].numNeighbours = constituencies[i].numNeighbours;
    copy[i].neighbours = malloc(sizeof(unsigned int) * copy[i].numNeighbours);
    memcpy(copy[i].neighbours, constituencies[i].neighbours, sizeof(unsigned int) * copy[i].numNeighbours);
  }

  return copy;
}
