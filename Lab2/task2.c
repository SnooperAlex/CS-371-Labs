// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// 
// (c) Martin Porcheron
//     m.a.w.porcheron@swansea.ac.uk
// -----------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "timestables.h"

int *tables_array[MAX_TIMES_TABLE];
int i;
int values;

int main(int argc , char *argv[]) {

	for(i = 0; i < MAX_TIMES_TABLE; i++){
		tables_array[i] = (int*) malloc(MAX_TABLE_SIZE * sizeof(int));
		generateTable(i, tables_array[i]);
	}
	printTables(tables_array);
	
	return 0;
}
