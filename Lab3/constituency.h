#ifndef CONSTIT
#define CONSTIT

typedef struct Constituency{
    char *name;
    unsigned int *neighbours;
    unsigned int numNeighbours;
} Constituency;

void constructConstituency(struct Constituency * const obj, char const *name, unsigned int* const neighbours,unsigned int numNeighbours);
void destructConstituency(struct Constituency * const obj);
void printConstituency(struct Constituency * const obj);
struct Constituency * copyConstituencies(struct Constituency constituencies[], unsigned int const numConstituencies);

#endif