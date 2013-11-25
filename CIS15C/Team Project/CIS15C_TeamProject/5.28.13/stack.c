/* Stack ADT implementation file */

#include <stdlib.h>
#include "stack.h"

/* Allocates memory for a stack head node     */
/* Pre	   nothing                            */
/* Post	   head is allocated and initialized  */
/* Return  head's address if successful       */
/*	       null if overflow                   */
STACK *createStack (void)
{
	STACK *stack;

	stack = (STACK *) malloc (sizeof(STACK));
	if (stack)
	{
		stack->top = NULL;
		stack->count = 0;
	}
	return stack;
}

/* Inserts data into a stack            */
/* Pre	   stack has been created       */
/* Post	   data have been inserted      */
/* Return  1 if successful              */
/*	       0 if overflow                */
int pushStack (STACK *stack, void *dataInPtr)
{
	STACK_NODE *newPtr;

	newPtr = (STACK_NODE *) malloc (sizeof(STACK_NODE));
	if (!newPtr)
		return 0;
	
	newPtr->dataPtr = dataInPtr;
	newPtr->link = stack->top;
	stack->top = newPtr;

	(stack->count)++;
	return 1;
}

/* Deletes a node from the stack             */
/* Pre	   stack has been created            */
/* Post	   data pointer to the stack top     */
/*         returned to user, and top node    */
/*         deleted and recycled              */
/* Return  pointer to data previously at top */
/*           of stack if successful          */
/*	       null if underflow                 */
void *popStack (STACK *stack)
{
	void *dataOutPtr;

	STACK_NODE *temp;

	if (stack->count == 0)
		dataOutPtr = NULL;
	else
	{
		temp = stack->top;
		dataOutPtr = stack->top->dataPtr;
		stack->top = stack->top->link;
		free(temp);
		(stack->count)--;
	}
	return dataOutPtr;
}

/* Retrieves data at the top of the stack    */
/* without changing the stack content        */
/* Pre	   stack is a pointer to the stack   */
/* Post	   itemPtr passed back to caller     */
/* Return  pointer to data at top of stack   */
/*	         if successful                   */
/*	       null if underflow                 */
void *stackTop (STACK *stack)
{
	if (stack->count > 0)
		return stack->top->dataPtr;
	else
		return NULL;
}

/* Checks to see if the stack is empty        */
/* Pre	   stack is a pointer to the stack    */
/* Return  1 if empty                         */
/*	       0 if stack has data                */
int emptyStack (STACK *stack)
{
	return (stack->count == 0);
}

/* Checks to see if stack is full.  With a     */
/* full stack, memory cannot be allocated      */
/* for another node                            */
/* Pre	   stack is a pointer to the stack     */
/* Return  1 if full                           */
/*	       0 if there is memory                */
int fullStack (STACK *stack)
{
	STACK_NODE *temp;

	if ((temp = (STACK_NODE *) malloc (sizeof(STACK_NODE))))
	{
		free (temp);
		return 0;
	}
	return 1;
}

/* Returns the number of elements in the stack  */
/* Pre	   stack is a pointer to the stack      */
/* Return  stack count                          */
int stackCount (STACK *stack)
{
	return stack->count;
}

/* Deletes all data from a stack and recycles   */
/* its memory, then deletes and recycles stack  */
/* head pointer                                 */
/* Pre	   stack is a pointer to the stack      */
/* Post	   all data have been deleted and       */
/*             recycled                         */
/* Return  null pointer                         */
STACK *destroyStack (STACK *stack)
{
	STACK_NODE *temp;

	if (stack)
	{
		while (stack->top != NULL)
		{
			free (stack->top->dataPtr);
			temp = stack->top;
			stack->top = stack->top->link;
			free (temp);
		}
		free (stack);
	}
	return NULL;
}
