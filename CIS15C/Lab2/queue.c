/* Queue ADT source file */

#include <stdlib.h>
#include "queue.h"


/* Allocates memory for a queue head node 	*/
/* Pre	   nothing                          */
/* Post	   head is allocated and initialized*/
/* Return  head's address if successful  	*/
/*	       null if overflow                 */
QUEUE *createQueue (void)
{
	QUEUE *queue;

	queue = (QUEUE *) malloc (sizeof(QUEUE));
	if (queue)
	{
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;
	}
	return queue;
}

/* Inserts data into a queue			*/
/* Pre	   queue has been created		*/
/* Post	   data have been inserted		*/
/* Return  1 if successful	     		*/
/*	       0 if overflow			    */
int enqueue (QUEUE *queue, void *itemPtr)
{
	QUEUE_NODE *newPtr;

	newPtr = (QUEUE_NODE *) malloc (sizeof(QUEUE_NODE));
	if (!newPtr)
		return 0;
	
	newPtr->dataPtr = itemPtr;
	newPtr->link = NULL;
	
	if (queue->count == 0)
		queue->front = newPtr;
	else
		queue->rear->link = newPtr;

	(queue->count)++;
	queue->rear = newPtr;
	return 1;
}

/* Deletes a node from the queue                */
/* Pre	   queue has been created               */
/* Post	   data pointer to queue front returned */
/*	       to user, and front node deleted and  */
/*         recycled                             */
/* Return  1 if successful                      */
/*         0 if underflow                       */
int dequeue (QUEUE *queue, void **itemPtr)
{

	QUEUE_NODE *deleteLoc;

	if (!queue->count)
		return 0;
	*itemPtr = queue->front->dataPtr;

	deleteLoc = queue->front;
	if (queue->count == 1)
		queue->rear = queue->front = NULL;
	else
		queue->front = queue->front->link;
	(queue->count)--;
	free (deleteLoc);

	return 1;
} 

/* Retrieves data at the front of the queue */
/* without changing the queue content		*/
/* Pre	   queue is a pointer to the queue	*/
/* Post	   itemPtr passed back to caller	*/
/* Return  1 if successful                  */
/*         0 if underflow                   */
int queueFront (QUEUE *queue, void **itemPtr)
{
	if (!queue->count)
		return 0;
	else
	{
		*itemPtr = queue->front->dataPtr;
		return 1;
	}
}

/* Retrieves data at the rear of the queue 	*/
/* without changing the queue content		*/
/* Pre	   queue is a pointer to the queue	*/
/* Post	   itemPtr passed back to caller	*/
/* Return  1 if successful                  */
/*         0 if underflow                   */
int queueRear (QUEUE *queue, void **itemPtr)
{
	if (!queue->count)
		return 0;
	else
	{
		*itemPtr = queue->rear->dataPtr;
		return 1;
	}
}

/* Checks to see if the queue is empty     */
/* Pre	   queue is a pointer to the queue */
/* Return  1 if empty                      */
/*	       0 if queue has data             */
int emptyQueue (QUEUE *queue)
{
	return (queue->count == 0);
}

/* Checks to see if queue is full.  With a	*/
/* full queue, memeory cannot be allocated	*/
/* for another node                         */
/* Pre	   queue is a pointer to the queue	*/
/* Return  1 if full                        */
/*	       0 if there is memory             */
int fullQueue (QUEUE *queue)
{
	QUEUE_NODE *temp;

	if ((temp = (QUEUE_NODE *) malloc (sizeof(QUEUE_NODE))))
	{
		free (temp);
		return 0;
	}
	return 1;
}

/* Returns the number of elements in the queue */
/* Pre	   queue is a pointer to the queue     */
/* Return  queue count                         */
int queueCount (QUEUE *queue)
{
	return queue->count;
}

/* Deletes all data from a queue and recycles	*/
/* its memory, then deletes and recycles queue	*/
/* head pointer                                 */
/* Pre	  queue is a pointer to the queue       */
/* Post	  all data have been deleted and        */
/*	         recycled                           */
/* Return  null pointer                         */
QUEUE *destroyQueue (QUEUE *queue)
{
	QUEUE_NODE *deletePtr;

	if (queue)
	{
		while (queue->front != NULL)
		{
			free (queue->front->dataPtr);
			deletePtr = queue->front;
			queue->front = queue->front->link;
			free (deletePtr);
		}
		free (queue);
	}
	return NULL;
}
