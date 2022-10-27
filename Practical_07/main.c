#include <stdio.h>
#include <stdlib.h>

int *allocatearray(const int n){
  int *myints;

  myints = (int *)malloc(n * sizeof(int));
  if (myints == NULL){
    printf("Malloc Failed, exiting...\n");
    exit(1);
  }
  return myints;
}

void fillwithones(int *intarray, const int arraylen){

}

void printarray(int *intarray, const int arraylen){

}

void freearray(int *intarray){
  free(intarray);
  intarray = NULL;
}

// Main
int main(void)
{
  // Test
  int* myints = NULL;

  myints = allocatearray(10);

  free(myints);
  // Exit cleanly
  printf("Done!\n");
  return 0;
}
