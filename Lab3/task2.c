// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2022/23)
// 
// (c) Lin Yuanbo Wu
//    l.y.wu@swansea.ac.uk
// -----------------------------------------------------

#include <stdio.h>

#include "constituency.h"

int main() {
  int i;
  const int numConstituencies = 5;
  struct Constituency constituencies[numConstituencies];

  constructConstituency(
  &constituencies[0], "Swansea East",
  (unsigned int[]){1, 2, 3, 4}, 4);
  constructConstituency(
  &constituencies[1], "Swansea West",
  (unsigned int[]){0, 2}, 2);
  constructConstituency(
  &constituencies[2], "Gower",
  (unsigned int[]){0, 1, 3}, 3);
  constructConstituency(
  &constituencies[3], "Neath",
  (unsigned int[]){0, 2, 4}, 3);
  constructConstituency(
  &constituencies[4], "Aberavon",
  (unsigned int[]){0 , 3}, 2);

  
  struct Constituency lowest = constituencies[0];
  struct Constituency highest = constituencies[0];

  for (int i = 0; i < numConstituencies; i++) {
    printConstituency(&constituencies[i]);
  }

  printf("\n");

  for (int i = 0; i < numConstituencies; i++) {

    if (constituencies[i].numNeighbours < lowest.numNeighbours) {
      lowest = constituencies[i];
    }

    if (constituencies[i].numNeighbours > highest.numNeighbours) {
      highest = constituencies[i];
    }
  }

  printf("%s has the most bordering constituencies\n", highest.name);
  for (unsigned int i = 0; i < highest.numNeighbours; i++) {
    printf("%s\n", constituencies[highest.neighbours[i]].name);
  }

  printf("\n");

  printf("%s has the fewest bordering constituencies\n", lowest.name);
  for (unsigned int i = 0; i < lowest.numNeighbours; i++) {
    printf("%s\n", constituencies[lowest.neighbours[i]].name);
  }

  
  for (int i = 0; i < numConstituencies; i++) {
    destructConstituency(&constituencies[i]);
  }
  
  return 0;
}