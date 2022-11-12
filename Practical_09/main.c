#include <stdio.h>
#include <stdlib.h>

// Dynamically allocate the memory for an array of 'n' integers
int *allocatearray(const int order){
  int *myints;

  myints = (int *)malloc((order * order ) * sizeof(int));

  // Check return value
  if (myints == NULL){
  printf("Malloc Failed, exiting...\n");
                 
  // exit on failure
  exit(1);
  }

  // return allocated memory space
  return myints;
}


// Main
int main(void)
{

  // Counter variables
  int i,j,k,p,q,mid,order;
  int* magic;
 

  printf("Enter the order of the magic square to be generated (must be odd)");
  if ((scanf("%d", &order)) != 1){
    printf("Error in scanf\n");
    exit(1);
  }
   
  if( order%2 == 0){
    printf("The order must be odd.\n");
    exit(1);
  }
  magic = allocatearray(order);

  // Based on https://www.codesansar.com/c-programming-examples/generate-magic-square.htm 
  mid = order/2;
  
  for(i=0;i< order; i++){
    for(j=0; j< order; j++){
      magic[order*i+j]=0;
    }
  }
                                                          
  k=mid;
  j=0;
  for(i=1; i<= order*order; i++){
    magic[order*j + k] = i;
    p = j--;
    q = k++;
                                                                                                      
    if(j< 0){
      j = order-1;
    }
    
    if(k>order-1){
      k=0;
    }
    
    if(magic[j+k] != 0){
      k = q;
      j = p+1;
    }
  }
  
  printf("Generated MAGIC SQUARE is:\n");
  for(i=1;i<=6*order;i++){
    printf("-");
  }
  printf("\n");
  for(j=0;j< order;j++){
    printf("|");
    for(k=0; k< order; k++){
      printf("%4d |", magic[j+k]);
    }
    printf("\n");
    for(i=1; i<=6*order; i++){
      printf("-");
    }
    printf("\n");
  }
  return 0;

}
