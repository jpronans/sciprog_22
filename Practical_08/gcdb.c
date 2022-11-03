#include <stdio.h>

// Declare GCD Function
int gcd (int a, int b);

// Find the Greatest Common Divisor of a pair of Integers using recursion
int main(void)
{
  // Two numbers
  int a, b;

  printf("Please enter 'A'\n");
  scanf("%d", &a);
  if (a < 1){
    printf("To small, try again");
    return 0;
  }

  printf("Please enter 'B'\n");
  scanf("%d", &b);
  if (b < 1){
    printf("To small, try again");
    return 0;
  }
  int temp;
  while ( b != 0){
    temp = b;
    b = a % b;
    a = temp; 
  }
  printf("GCD is %d\n", a); 

  // Exit cleanly
  printf("Done!\n");
  return 0;
}

int gcd (int a, int b) {
  if (b != 0 )
    return gcd(b, a % b);
  else
    return a;
}
