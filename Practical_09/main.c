#include <stdio.h>
#include <stdlib.h>
#include "magic_square.h"

// Function in header declared
int isMagicSquare(int ** square, const int n);

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
  //int i,j,k,p,q,mid,order,res;
  //int* magic;

  int i,r,c;
   
  printf("Initial Test of 3x3\n");
  
  int three1[3]= {2,7,6};
  int three2[3]= {9,5,1};
  int three3[3]= {4,3,8};

  int *newthree[3] = {three1,three2,three3};

  
  // Check return value of isMagicSquare  
  if (isMagicSquare(newthree, 3) == 1)
    printf("Matrix is Magic\n");

  FILE* fp=fopen("test","w");
  
  for(r = 0; r < 3; r++){
    for(c = 0; c < 3; c++){
      fprintf(fp, "%d", newthree[r][c]); 
    }
    fprintf(fp, "\n");
  }
  fclose(fp);

 // fp = fopen("test","r");

  return 0;

}
