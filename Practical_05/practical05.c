#include <stdio.h>

// Inputs are f(n-1) and f(n-2)
void calc(int *fn1, int *fn2)
{
  int next;
  // Fn = Fn-1 + Fn-2
  next = (*fn1) + (*fn2);

  // Remember to copy original before overwriting (doh!)
  (*fn2)=(*fn1);
  (*fn1)=next;
}

int main(void) {
  // Error variable 
  int err;
  // For loop counter
  int i;
  // Number of terms
  int n;
 
  // Initialse first two terms
  int f0 = 0, f1 = 1;
    

  // Get information from user
  printf("Can I have an 'n' please (int)\n");
  err=scanf("%d",&n);
  if (err != 1) {
    printf("Incorrect number of parameters or invalid type, exiting...\n");
    return 1;
  }
  if (n < 1) {
    printf("The number is not positive, exiting...\n");
    return 1;
  }
     

  printf("Fibonacci series is: \n");
  if (n == 1)
  { 
    // Print first two 
    printf(" %d %d\n", f0, f1);
  }
  else {
    // Print first two
    printf(" %d %d", f0, f1);
    
    // Continue to print the rest of the series requested up to 'n'
    for (i = 2; i <=n; i++){
      calc(&f1, &f0);
      printf(" %d", f0);
      if(((i+1)%5) == 0 )
        printf("\n");
    }
    // Add a newline after the last value in the series
    printf("\n");  
  }
  // No issues, exit cleanly
  return 0;
}
