// Stack ADT header file 
// Linked list implementation


#ifdef __cplusplus
extern "C" {
#endif


/* stack node structure */
typedef struct stackNode
{
    void *dataPtr;
    struct stackNode *link;
}STACK_NODE;


/* stack header structure */
typedef struct
{
    int count;
    STACK_NODE *top;
}STACK;


/* Allocates memory for a stack head node   */
/* Pre	   nothing                          */
/* Post	   head is allocated and initialized*/
/* Return  head's address if successful     */
/*         null if overflow                 */
STACK *createStack (void);

/* Inserts data into a stack			*/
/* Pre	   stack has been created		*/
/* Post	   data have been inserted		*/
/* Return  true if successful			*/
/*	       false if overflow			*/
int pushStack (STACK *stack, void *dataInPtr);

/* Deletes a node from the stack             */
/* Pre	   stack has been create             */
/* Post	   data pointer to the stack top     */
/*	       returned to user, and top node    */
/*	       element deleted and recycled		 */
/* Return  pointer to data previously at top */
/*	         of stack if successful	      	 */
/*	       null if underflow		    	 */
void *popStack (STACK *stack);

/* Retrieves data at the top of the stack	*/
/* without changing the stack content		*/
/* Pre	   stack is a pointer to the stack	*/
/* Post    itemPtr passed back to caller	*/
/* Return  pointer to data at top of stack	*/
/*	         if successful			        */
/*	       null if underflow	    		*/
void *stackTop (STACK *stack);

/* Checks to see if the stack is empty		*/
/* Pre	   stack is a pointer to the stack	*/
/* Return  1 if empty			            */
/*	       0 if stack has data              */
int emptyStack (STACK *stack);

/* Checks to see if stack is full.  With a	*/
/* full stack, memeory cannot be allocated	*/
/* for another node                         */
/* Pre	   stack is a pointer to the stack	*/
/* Return  1 if full                        */
/*	       0 if there is memory             */
int fullStack (STACK *stack);

/* Returns the number of elements in the stack */
/* Pre	   stack is a pointer to the stack     */
/* Return  stack count				           */
int stackCount (STACK *stack);

/* Deletes all data from a stack and recycles	*/
/* its memory, then deletes and recycles stack	*/
/* head pointer					                */
/* Pre	   stack is a pointer to the stack	    */
/* Post	   all data have been deleted and       */
/*	            recycled                        */
/* Return  null pointer						    */
STACK *destroyStack (STACK *stack);

#ifdef __cplusplus
}
#endif
