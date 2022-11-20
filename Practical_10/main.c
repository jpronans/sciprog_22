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
	if (isFull(stack))
  {
    printf("Overflow adding %d to stack. Not added",item);  
		return;
  }
  // Store the item into the top of the stack(pre-increment)
  stack->array[++stack->top] = item;
}

// Function to remove an item from stack. It
// decreases top by 1
int pop(struct Stack* stack)
{
  // Underflow
	if (isEmpty(stack))
		return -9;
  // Return 
  return stack -> array[stack -> top--];
}

//Function to show the movement of disks
void showMove(char from, char to, int disk)
{
    printf("Move disk %d from:%c to :%c\n\n", disk, from, to);
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
  printf("Test complete\n");

  free(temp); 
}

void iterate(int no_of_disks, struct Stack *src, struct Stack *dest, struct Stack* spare){

  int i, tmp, total_num_of_moves;
  char s = 'S', d = 'D', p = 'P'; // Source, Dest, sPare

  // If number of disks is even, then interchange destination pole and auxiliary pole
  if (no_of_disks % 2 == 0)
  {
    char temp = d;
    d = p;
    p = temp;
  }
  // Known value
  total_num_of_moves = (no_of_disks*no_of_disks) - 1;


  //Larger disks will be pushed first
  for (i = no_of_disks; i >= 1; i--){
    printf("Seeding stack posn %d with %d\n",i, i);
    push(src, i);
  }


  // Looking at the video, it all comes down to the same few moves, again and again.
  for (i = 1; i <= total_num_of_moves; i++)
  {
    if (i % 3 == 1){
      printf("Swap src->item:%d, with dest->item:%d\n", src->top, dest->top);
      swapDisks(src, dest, s, d);
    }
    else if (i % 3 == 2){ // swap src and spare
      printf("Swap src->item:%d, with spare->item:%d\n", src->top, spare->top);
      swapDisks(src, spare, s, p);
    }

    else if (i % 3 == 0){
      printf("Swap spare->item:%d, with dest->top %d\n",spare->top, dest->top);
      swapDisks(spare, dest, p, d);
    }
  }
  // pop and print
  int tmp1, tmp2;
  for (i = no_of_disks; i >= 1; i--){
     tmp=pop(src);
     tmp1=pop(spare);
     tmp2=pop(dest);

     printf("Reading Stack posn %d, result %d:\t%d:\t%d\n",i,tmp, tmp1, tmp2);
  }
  //
}

// Attempt at iterative Tower of Hanoi solution 
int main(void)
{
	int no_of_disks = 0;  // user inputs number of disks

	struct Stack *src, *dest, *spare;

  printf("Please enter the number of disks\n");
  scanf("%d", &no_of_disks);

  // Small bit of defensive programming, fail early
  if (no_of_disks < 1){
    printf("Non zero please, try again\n");
    return 0;
  }
  create_and_test_stack(no_of_disks);

  // Create three 'no_of_disks' sized stacks
  src = createStack(no_of_disks);
  dest = createStack(no_of_disks);
  spare = createStack(no_of_disks);


  // Iterate over the three poles.
  iterate(no_of_disks, src, dest, spare);

  printf("All done\n");

  // Free up what we allocated with createStack
  free(src);
  free(dest);
  free(spare);  
	// exit cleanly
  return 0;
}

