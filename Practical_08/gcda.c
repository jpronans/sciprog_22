#include <stdio.h>

// Solve for Greatest Common Divisor using loop method 
// Can't quite visualise it though 
int main(void)
{
  // A variable per number
  int a, b;

  printf("Please enter 'A'\n");
  scanf("%d", &a);

  // Small bit of defensive programming, fail early
  if (a < 1){
    printf("Non zero please, try again\n");
    return 0;
  }

  printf("Please enter 'B'\n");
  scanf("%d", &b);
  
  // Small bit of defensive programming 
  if (b < 1){
    printf("Non zero please, try again\n");
    return 0;
  }
  int temp = 0;
  while ( b != 0){
    // Store b
    temp = b;
    // B is the remainder of a divided by b range[0, b-1)
    b = a % b;

    // Restore for next run through  
    a = temp; 
  }
  printf("GCD is %d\n", a); 

  // Exit cleanly
  printf("Done!\n");
  return 0;
}
