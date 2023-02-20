#include <stdio.h>
#include <stdlib.h>
#include "constituency.h"

int main() {

  const int numConstituencies = 5;
  struct Constituency constituencies[numConstituencies];
  
  constructConstituency(&constituencies[0], "Swansea East", (unsigned int[]){1, 2, 3, 4}, 4);
  constructConstituency(&constituencies[1], "Swansea West", (unsigned int[]){0, 2}, 2);
  constructConstituency(&constituencies[2], "Gower", (unsigned int[]){0, 1, 3}, 3);
  constructConstituency(&constituencies[3], "Neath", (unsigned int[]){0, 2, 4}, 3);
  constructConstituency(&constituencies[4], "Aberavon", (unsigned int[]){0 , 3}, 2);

  struct Constituency * copy = copyConstituencies(constituencies, numConstituencies);

  int i;
  for (i = 0; i < numConstituencies; i++) {
    destructConstituency(&constituencies[i]);
  }

  struct Constituency lowest = copy[0];
  struct Constituency highest = copy[0];

  for (int i = 0; i < numConstituencies; i++) {
    printConstituency(&copy[i]);
  }

  printf("\n");

  for (int i = 0; i < numConstituencies; i++) {

    if (copy[i].numNeighbours < lowest.numNeighbours) {
      lowest = copy[i];
    }

    if (copy[i].numNeighbours > highest.numNeighbours) {
      highest = copy[i];
    }
  }

  printf("%s has the most bordering constituencies\n", highest.name);
  for (unsigned int i = 0; i < highest.numNeighbours; i++) {
    printf("%s\n", copy[highest.neighbours[i]].name);
  }

  printf("\n");

  printf("%s has the fewest bordering constituencies\n", lowest.name);
  for (unsigned int i = 0; i < lowest.numNeighbours; i++) {
    printf("%s\n", copy[lowest.neighbours[i]].name);
  }

  for (int i = 0; i < numConstituencies; i++) {
    destructConstituency(&copy[i]);
  }
  free(copy);
  
  return 0;

}