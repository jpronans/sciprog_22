#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


// A structure to represent a stack
struct Stack
{
  unsigned capacity;
  // Where is my top
  int top;
  // Unknown how big it will get so pointer.
  int *array;
};

// function to create a stack of given capacity.
struct Stack* createStack(const int capacity)
{
	struct Stack* s =	(struct Stack*) malloc(sizeof(struct Stack));
	s->capacity = capacity;
  // Init to 'bad' value
	s->top = -1;
  // Allocate space for array of ints
	s->array = (int*) malloc(s->capacity * sizeof(int));
	return s;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
  return (stack->top == stack->capacity - 1);
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
  return (stack->top == -1);
}

// Function to add an item to stack. It increases
// top by 1
void push(struct Stack *stack, int item)
{ 
	if (isFull(stack))
  {
    printf("Overflow adding %d to stack. Not added",item);  
		return;
  }
}

// Function to remove an item from stack. It
// decreases top by 1
int pop(struct Stack* stack)
{
  // Underflow
	if (isEmpty(stack))
		return -1;

}


// Function to implement legal movement between two poles
void moveDisks(struct Stack *src, struct Stack *dest, char s, char d)
{

}

//Function to implement Towers of Hanoi
iterate(int no_of_disks, struct Stack *src, struct Stack *dest,	struct Stack *aux)
{
// Just do it!
}


void create_and_test_stack(int no_of disks){

}

void interate(int n, stack *src, stack *dest, stack* spare) 

// Driver Program
int main()
{
	// Input: number of disks
	int no_of_disks = 0;

	struct Stack *test, *src, *dest, *aux;

  printf("Please enter the number of disks\n");
  scanf("%d", &no_of_disks);

  // Small bit of defensive programming, fail early
  if (no_of_disks < 1){
    printf("Non zero please, try again\n");
    return 0;
  }
  create_and_test_stack(no_of_disks);

// Iterate over the three poles.
// iterate(no_of_disks, src, spare, dest);
	return 0;
}

