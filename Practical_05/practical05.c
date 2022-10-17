#include <stdio.h>

void calc(int *fn1, int *fn2)
{
  int next;
  // Fn = Fn-1 + Fn-2
  next = (*fn1) + (*fn2);

  // Remember to copy original before overwriting
  (*fn2)=(*fn1);
  (*fn1)=next;
}

int main(void) {
  
  // For loop counter
  int i;
  // Number of terms
  int n;
  // Initialse first two terms
  int f0 = 0;
  int f1 = 1;
    

  // Get information from user
  printf("Can I have an 'n' please (int)\n");
  scanf("%d",&n);

  printf("Fibonacci series is: \n");
  if (n == 0)  {
    // print first one
    printf("%d", f0);
  }
  else if (n == 1)
  { 
    // Print first two 
    printf("%d %d", f0, f1);
  }
  else {
    // Print first two
    printf("%d %d", f0, f1);
    
    // Continue to print the rest of the series requested up to 'n'
    for (i = 2; i <=n; i++){

      calc(&f1, &f0);
      printf(" %d", f0);
      
    }
    printf("\n");  
  }
  // No issues, exit cleanly
  return 0;
}
