#include <stdio.h>
#include <stdlib.h>


// Takes integer as argument, returns pointer to memory block
int *allocatearray(const int n){

  // Declare pointer
  int *myints = NULL;

  // Allocate memory based on argument
  myints = (int *)malloc(n * sizeof(int));
  if (myints == NULL){
    printf("Malloc Failed, exiting...\n");
    exit(1);
  }
  return myints;
}

// Fill all elements of the array with a. Needs arraylength to know when to stop
void fillwithones(int *intarray, const int arraylen){
  int i=0;
  for(i = 0; i < arraylen; i++){
    intarray[i] = 1;
  }
}

// Take a point to an array of ints, the legth and print it out.
void printarray(int *intarray, const int arraylen){
  int i=0;

  for(i = 0; i < arraylen; i++){
     printf("Element %d: %d\n", i, intarray[i]);
  }

  printf("\n");
}

// Free the memory allocated by malloc
void freearray(int *intarray){
  free(intarray);
}

// Main function
int main(void)
{
  // Integer pointer and length variable
  int* myints = NULL;
  int arraylen = 0;
 
  printf("Please enter the size of the array\n");
  scanf("%d", &arraylen);
  if (arraylen < 1){
    printf("To small, try again");
    return 0;
  }
  // Allocate memory for the integers
  myints = allocatearray(arraylen);

  // Print the array 
  printarray(myints, arraylen);

  // Change all the values to 1
  fillwithones(myints, arraylen);

  // Print once more
  printarray(myints, arraylen);
    
  // Free stack memory
  free(myints);
  
  // Set the pointer to NULL to avoid reuse
  myints = NULL;
  
  // Exit cleanly
  printf("Done!\n");
  return 0;
}
