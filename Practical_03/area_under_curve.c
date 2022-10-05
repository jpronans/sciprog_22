#include <stdio.h>
#include <math.h>

// Used to get the approx first and last values
float y(float x)
{
	// f(x) = 1/(1+x*x)
	return 1/(1+x*x);
}

float trapezodial(float a, float b, float n)
{
	int i=0;
	// Figure out spacing
	float h = (b-a)/n;

	// Compute first and last terms
	float s = y(a)+y(b);
	
	// Fill in the rest
	for (i = 1; i < n; i++)
	{
		s=s+2*y(a+i*h);
	}
	
	// h/2 is (b-a)/2n multiplied then by s
	return (h/2)*s;
}
double f(double x)
{
	return pow(x,2);
	//return x*x;
}

void main(void) {
  // Declare variables
  int int1, int2, i;
  float float1, float2, spacing;
  double sum;
  
  // Test Values
  int1 = 33554430;
  int2 = 33554430;
  float1 = 33554430;
  float2 = 33554430;

  // No special formatting
  printf("Two ints %d, %d and two floats %f, %f\n", int1, int2, float1, float2);

  // Add formatting to float
  printf("Two ints %d, %d and two floats %.4f, %.4f\n", int1, int2, float1, float2);

  // Testing trapezodial
  float x0=0;
  float xn=20;
  int n = 19;
  printf("-----\nExercise 3a\n");
  printf("Result of integral = %6.6f\n-----\n",trapezodial(x0,xn,n));
  
  sum = 0.0;
  i = 0;

/*    
// spacing / number of rectangles
   spacing = (xn-x0)/n;
   printf("Spacing is (%f - %f) / %d\n", xn, x0, n);
   printf("Spacing %f\n",spacing);
   for( i=1; i<=n; i++)
   {
	printf("sum %lf\n",sum);
	sum = sum + (f(x0 + (i-1)*spacing)*spacing);
   }
   printf("Sum = %6.6lf\n",sum);
//   return 0;
*/
}
