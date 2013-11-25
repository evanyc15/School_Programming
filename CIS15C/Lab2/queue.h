// Queue ADT header file
// Linked list implementation

#ifdef __cplusplus
extern "C" {
#endif

/* queue node structure */
typedef struct queueNode
{
   void *dataPtr;
   struct queueNode *link;
}QUEUE_NODE;


/* queue header structure */
typedef struct
{
   QUEUE_NODE *front;
   QUEUE_NODE *rear;
   int count;
}QUEUE;


/* Allocates memory for a queue head node		*/
/* Pre	   nothing								*/
/* Post	   head is allocated and initialized	*/
/* Return  head's address if successful			*/
/*	   null if overflow							*/
QUEUE *createQueue (void);

/* Inserts data into a queue			*/
/* Pre	   queue has been created		*/
/* Post	   data have been inserted		*/
/* Return  true if successful			*/
/*	   false if overflow			    */
int enqueue (QUEUE *queue, void *itemPtr);

/* Deletes a node from the queue		*/
/* Pre	   queue has been created		*/
/* Post	   data pointer to queue front	*/
/*	   returned to user, and front node	*/
/*	   deleted and recycled		        */
/* Return  true if successful			*/
/*	   false if underflow			*/
int dequeue (QUEUE *queue, void **itemPtr);

/* Retrieves data at the front of the queue */
/* without changing the queue content		*/
/* Pre	   queue is a pointer to the queue	*/
/* Post	   itemPtr passed back to caller	*/
/* Return  true if successful				*/
/*	   false if underflow					*/
int queueFront (QUEUE *queue, void **itemPtr);

/* Retrieves data at the rear of the queue  */
/* without changing the queue content		*/
/* Pre	   queue is a pointer to the queue	*/
/* Post	   itemPtr passed back to caller	*/
/* Return  true if successful				*/
/*	   false if underflow					*/
int queueRear (QUEUE *queue, void **itemPtr);

/* Checks to see if the queue is empty		*/
/* Pre	   queue is a pointer to the queue	*/
/* Return  true if empty					*/
/*	   false if queue has data				*/
int emptyQueue (QUEUE *queue);

/* Checks to see if queue is full.  With a	*/
/* full queue, memeory cannot be allocated	*/
/* for another node							*/
/* Pre	   queue is a pointer to the queue	*/
/* Return  true if full						*/
/*	   false if there is memory				*/
int fullQueue (QUEUE *queue);

/* Returns the number of elements in the queue	*/
/* Pre	    queue is a pointer to the queue		*/
/* Return   queue count							*/
int queueCount (QUEUE *queue);

/* Deletes all data from a queue and recycles	*/
/* its memory, then deletes and recycles queue	*/
/* head pointer									*/
/* Pre	   queue is a pointer to the queue		*/
/* Post	   all data have been deleted and 		*/
/*         recycled								*/
/* Return  null pointer							*/
QUEUE *destroyQueue (QUEUE *queue);

#ifdef __cplusplus
}
#endif
