#include <stdio.h>
#include <stdlib.h>
#include "magic_square.h"

#define TESTORDER 3

// Function in header declared
int isMagicSquare(int ** square, const int n);

void test_code(void){
  printf("Test of 3x3 matrix\n");

  // Declare file pointer
  FILE* fp;

  // row and column counters
  int r, c;

  // Declare and Initialise Integer arrays
  int three1[TESTORDER]= {2,7,6};
  int three2[TESTORDER]= {9,5,1};
  int three3[TESTORDER]= {4,3,8};
  
  // Initialise array of pointers to arrays
  int *newthree[TESTORDER] = {three1,three2,three3};

  // Check return value of isMagicSquare  
  if (isMagicSquare(newthree, TESTORDER) == 1)
    printf("Test Matrix is Magic\n");
  
  // Write out test array
  fp=fopen("test","w");

  // Print the order
  fprintf(fp, "%d\n", TESTORDER);

  // print row by row (by stepping through columns
  for(r = 0; r < TESTORDER; r++){
    for(c = 0; c < TESTORDER; c++){
      // print to file
      fprintf(fp, " %d", newthree[r][c]);
      // print to console
      //printf(" %d", newthree[r][c]);
    }
    // print newline
    fprintf(fp, "\n");
  }
  // close file
  fclose(fp);
  // print newline
  printf("\n");

}

// Main O(n) - Linear behaviour
int main(void)
{

  // Counter variables
  int i;// , k; //,p,q,mid,order,res;

  // File pointer for file operations
  FILE* fp;

  // location to store line information in.
  int *line = NULL;

  // Variable for holding matrix
  int **matrix=NULL;

  // Temp variable for reading characters and checking for newline 
  char temp;

  // Rows, Order
  int r, order;
  
  // Run the magic checker with known good values to check it
  test_code(); 
  
  // Read file with stored matrix
  fp = fopen("test1","r");
  fscanf(fp, "%d", &order);

  printf("Order read from file is %d\n", order);
  
  // Allocate space for 'order' Int Memory Pointers. 
  matrix=(int **)malloc(order*sizeof(int*));
  // Start reading row by row 
  for(r=0; r<order; r++){
    //Allocate memory to store the line 
    line=(int *)malloc(order*sizeof(int));
    
    // Read the line until \n is encountered
    // Storing the values as they are read
    i=0;
    do {
      fscanf(fp, "%d%c", line+i, &temp);
      i++;

    } while (temp != '\n' && i < order); // use order here as a safety in case \n isn't recognised
    // Point the matrix row pointer to the row.
    matrix[r]=line;
  }
  
  // Check return value of isMagicSquare  
  if (isMagicSquare(matrix, order) == 1)
    printf("Woot, Matrix is Magic\n");  
  else
    printf("Boo!, Matrix is not Magic\n");
        
  // Release the memory allocated to each line
  for(r=0; r < order; r++){
    if (matrix[r] != NULL)
      free(matrix[r]);
  }
  // Release the memory allocated to the list of pointers
  free(matrix);
  return 0;

}
