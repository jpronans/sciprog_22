#include <stdio.h>

int main(void) {
  int i; double a;
  // Get information from user
  printf("please enter an int and double\n");
  scanf("%d %lf",&i,&a);
  printf("Int = %d, Double = %lf\n",i,a);
  return 0;
}
