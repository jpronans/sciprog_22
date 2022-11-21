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
  // Init to 'sentinel' value
	s->top = -1;
  // Allocate space for array of ints
	s->array = (int*) malloc(s->capacity * sizeof(int));
	return s;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{ 
  // One less than the capcaity = FULL 
  return (stack->top == stack->capacity - 1);
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
  return (stack->top == -1);
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack *stack, int item)
{ 
  // Don't do anything if its full 
	if (isFull(stack)  )
  {
		return;
  }
  // Store the item into the top of the stack(pre-increment)
  stack->array[++stack->top] = item;
}

// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack* stack)
{
  // Underflow
	if (isEmpty(stack))
		return -9;
  // Return 
  return stack->array[stack->top--];
}

//Function to show the movement of disks
void showMove(char from, char to, int disk)
{ 
    // not a disk
    if (disk == -9)
      return;
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

// Function to implement legal movement between two poles
void swapDisks(struct Stack *src, struct Stack *dest, char s, char d)
{
    // Get the two top values
    int pole1Top = pop(src);
    int pole2Top = pop(dest);
 
    // When source pole is empty
    if (pole1Top == -9)
    {
        //if src is empty, move top of dest to it.        
        push(src, pole2Top);
        showMove(d, s, pole2Top);
    }
 
    // When dest pole is empty move top of src to it.
    else if (pole2Top == -9)
    {
        push(dest, pole1Top);
        showMove(s, d, pole1Top);
    }
 
    // When top disk of src > top disk of dest, push them to src in right order
    else if (pole1Top > pole2Top)
    {
        push(src, pole1Top);
        push(src, pole2Top);
        showMove(d, s, pole2Top);
    }
 
    // When top disk of src < top disk of dest, push them to dest in right order
    else
    {
        push(dest, pole2Top);
        push(dest, pole1Top);
        showMove(s, d, pole1Top);
    }
}





void create_and_test_stack(int no_of_disks){
  struct Stack *temp;
  int i=0;
  int tmp=0;
  temp=createStack(no_of_disks);
  
  for(i=0; i< no_of_disks;i++){
    push(temp, i);
  }
  
  // print and pop
  for(i=0; i< no_of_disks;i++){
    tmp=pop(temp);
    printf("Stored Value is %d\n",tmp);
  }
  printf("Stack Test complete\n\n");
  
  free(temp); 
}

void iterate(int no_of_disks, struct Stack *src, struct Stack *dest, struct Stack* spare){
  
  // Iterator and holds calculated value
  int i, total_no_of_moves;

  char s = 'A', d = 'C', p = 'B'; //  Source, Dest, Spare

  struct Stack *tmpPtr;

  /* Used for printing out the stack
  // Assignment prevents compiler warnings
  int tmp=0;  
  int tmp1=0; 
  int tmp2=0; 
  */

  // If number of disks is even, then interchange destination pole and spare/extra/middle pole
  // i.e. move the smallest disk to the spare.
  if (no_of_disks % 2 == 0)
  {
    tmpPtr = dest;
    dest = spare;
    spare = tmpPtr;
    char temp = d;
    d = p;
    p = temp;
  }
  // Known value
  total_no_of_moves = (no_of_disks*no_of_disks) - 1;


  // Seed the source stack
  for (i = no_of_disks; i >= 1; i--){
    //printf("Seeding stack posn %d with %d\n",i, i);
    push(src, i);
  }

  // Looking at the video, it all comes down to the same few moves, again and again.
  for (i = 1; i <= total_no_of_moves; i++)
  {
    if (i % 3 == 0){ // Move spare to dest
      swapDisks(spare, dest, p, d);
    }
    else if (i % 3 == 1){// move src to dest
      swapDisks(src, dest, s, d);
    }
    else if (i % 3 == 2){ // move src to  spare
      swapDisks(src, spare, s, p);
    }

  }
  /*
   *
  // pop and print
  printf("Check the stacks\n");
  printf("Index:\tsrc\tspare\tdest\n");
  for (i = no_of_disks; i >= 1; i--){
     tmp=pop(src);
     tmp1=pop(spare);
     tmp2=pop(dest);

     printf("%d\t%d\t%d\t%d\n",i,tmp, tmp1, tmp2);
  }
  if( tmp2 != no_of_disks )
    printf("Dest stack not correct, try again!\n");
  //
  */

}

/*
 * from https://www.youtube.com/watch?v=rf6uf3jNjbo
 * let f(n) be recursive function
 * assume f(n-1) works
 * show f(n) works using f(n-1)
 * Not sure the domino example helped at all ;(
 */
int recursive_h(int n, char src, char mid, char dest){
  if (n == 1 ) {
      printf("Moving disk 1 from %c to %c\n", src, dest);
  }
  else {
    recursive_h(n-1, src, dest, mid);
    printf("Moving disk %d from %c to %c\n", n, src, dest);    
    recursive_h(n-1, mid, src, dest);
  }
  // Default
  return 0;     
}

// Attempt at iterative Tower of Hanoi solution 
int main(void)
{
	int no_of_disks = 0;  // user inputs number of disks

	struct Stack *src, *dest, *spare;

  printf("Please enter the number of disks\n");
  scanf("%d", &no_of_disks);
  printf("\n");

  // Small bit of defensive programming, fail early
  if (no_of_disks < 1){
    printf("Non zero please, try again\n");
    return 0;
  }
  
  // Code for testing Stack Push and Pop
  create_and_test_stack(no_of_disks);

  // Create three 'no_of_disks' sized stacks
  src = createStack(no_of_disks);
  dest = createStack(no_of_disks);
  spare = createStack(no_of_disks);

  // Iterate over the three poles.
  printf("Running Iterative solution\n");
  iterate(no_of_disks, src, dest, spare);

  printf("\nRunning Recursive solution\n");
  recursive_h(no_of_disks, 'A','B','C');
  printf("\nAll done\n");

  // Free up what we allocated with createStack
  free(src);
  free(dest);
  free(spare);  
	// exit cleanly
  return 0;
}

