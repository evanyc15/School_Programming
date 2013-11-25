/* BST ADT implementation file */


#include <stdlib.h>
#include "bst.h"

/* Allocates memory for a bst head node		  */
/* Pre	   nothing                            */
/* Post	   head is allocated and initialized  */
/* Return  head's address if successful       */
/*	       null if overflow                   */
BST *createBST (int (*compare) (void * a, void * b))
{
	BST * bst = NULL;

	bst = (BST *) malloc (sizeof(BST));
	if (bst)
	{
		bst->root = NULL;
		bst->count = 0;
		bst->compare = compare;
	}
	return bst;
}

/* Inserts data into a bst	            */ 
/* Pre	   bst has been created			*/
/* Post	   data is inserted				*/
/* Return  1 if successful              */
/*	       0 if overflow                */    
int insertBST (BST * bst, void * dataInPtr)   
{
	BST_NODE * newPtr;

	newPtr = (BST_NODE *) malloc (sizeof(BST_NODE));
	if (!newPtr)
		return 0;
	
	newPtr->dataPtr = dataInPtr;
	newPtr->left = NULL;
	newPtr->right = NULL;

	if (bst->count == 0)
		bst->root = newPtr;
	else
		_insert(bst, bst->root, newPtr);

	(bst->count)++;
	return 1;
}

/* internal insert function - uses recursion	*/
/* to insert new data at a leaf	node			*/
/* Pre		bst has been created				*/
/*			root pointer points to current root */
/*			newptr points to new data node		*/
/* Post		data has been inserted				*/ 
/* Return	pointer to new root					*/ 
BST_NODE * _insert(BST * bst, BST_NODE * root, BST_NODE * newPtr)
{
	if (!root)
		return newPtr;

	if (bst->compare(newPtr->dataPtr, root->dataPtr) < 0)
	{
		root->left = _insert(bst, root->left, newPtr);
		return root;
	}
	else 
	{
		root->right = _insert(bst, root->right, newPtr);
		return root;
	}
}


/* Deletes data from the bst	             */
/* Pre	   bst has been created		         */
/*		   dltKey points to the target data  */
/* Post    bst node is deleted and recycled  */
/*		   data is returned to the user		 */
/* Return  1 if successful			         */ 
/*	       0 if not found	                 */
int deleteBST (BST * bst, void * dltKey)		
{
	int success;
	BST_NODE * newRoot;

	newRoot = _delete(bst, bst->root, dltKey, &success);
	if (success)
	{
		bst->root = newRoot;
		(bst->count)--;
		if (bst->count == 0)
			bst->root = NULL;
	}
	return success;
}


/* internal delete function - uses recursion to		*/
/* delete a data node from the bst					*/
/* Pre		bst has been created					*/
/*			root points to current root				*/
/*			dltKey points to target data			*/
/*			success is a reference to boolean for	*/
/*			 success in deletion					*/
/* Post		delete data is returned to the user		*/
/*			bst node is delete and recycled			*/ 
/* Return	root pointer							*/ 
BST_NODE * _delete (BST * bst, BST_NODE * root, void * dltKey, 
					int * success)
{
	BST_NODE * dltPtr;
	BST_NODE * exchPtr;
	BST_NODE * newRoot;
	BST_NODE * holdPtr;

	if (!root)
	{
		*success = 0;
		return NULL;
	}

	if (bst->compare(dltKey, root->dataPtr) < 0)
		root->left = _delete(bst, root->left, dltKey, success);
	else if (bst->compare(dltKey, root->dataPtr) > 0)
		root->right = _delete(bst, root->right, dltKey, success);
	else
	{
		dltPtr = root;
		if (!root->left)
		{
			free(root->dataPtr);
			newRoot = root->right;
			free(dltPtr);
			*success = 1;
			return newRoot;
		}
		else
		{
			if (!root->right)
			{
				free (root->dataPtr);
				newRoot = root->left;
				free (dltPtr);
				*success = 1;
				return newRoot;
			}
			else
			{
				exchPtr = root->left;
				while (exchPtr->right)
					exchPtr = exchPtr->right;
				holdPtr = root->dataPtr;
				root->dataPtr = exchPtr->dataPtr;
				exchPtr->dataPtr = holdPtr;
				root->left = _delete(bst, root->left, exchPtr->dataPtr, success);
			}
		}
		
	}
	return root;
}



/* Retrieves data in the bst						*/		
/* Pre		bst is created							*/
/*			keyPtr is pointer to key of target data	*/
/* Post		data is found							*/
/* Return	pointer to data found if successful		*/
/*			null if not found		                */
void * retrieveBST (BST * bst, void * keyPtr)
{
	if (bst->root)
		return _retrieve(bst, keyPtr, bst->root);
	else
		return NULL;
}


/* internal search function - uses recursion to look	*/
/* matched data											*/
/* Pre		bst points to head node						*/
/*			keyPtr points to target data				*/
/*			root points to current root node			*/
/* Post		found data pointer returned					*/
/* Return	found data pointer							*/
/*			NUll if not found							*/
void * _retrieve(BST * bst, void * keyPtr, BST_NODE * root)
{
	if (root)
	{
		if (bst->compare(keyPtr, root->dataPtr) < 0)
			return _retrieve(bst, keyPtr, root->left);
		else if (bst->compare(keyPtr, root->dataPtr) > 0)
			return _retrieve(bst, keyPtr, root->right);
		else
			return root->dataPtr;
	}
	else
		return NULL;
}


/* Inorder (RNL) traverse the bst						*/
/* Pre		bst has been created						*/
/*			process function pointer points to function */
/*			  to function that processes each node		*/
/* Post		all nodes have been processed				*/
/* Return	nothing										*/
void inOrder (BST * bst, void (*process) (void * dataPtr) )
{
	_traverse(bst->root, process);
	return;
}



/* internal inorder traverse - uses recursion to traverse	*/
/* and process each node									*/
/* Pre		root is pointer to current root					*/
/*			process is pointer to process function			*/
/* Post		all nodes have been processed					*/
/* Return	nothing											*/
void _traverse (BST_NODE * root, void (*process) (void * dataPtr) )
{
	if (root)
	{
		_traverse(root->left, process);
		process(root->dataPtr);
		_traverse(root->right, process);
	}
	return;
}


/* Checks to see if the bst is empty		*/
/* Pre	   bst has been created			    */
/* Return  1 if empty                       */
/*	       0 if bst has data				*/
int emptyBST (BST * bst)
{
	return (bst->count == 0);
}


/* Checks to see if bst is full.			*/
/* which means memory cannot be allocated   */
/* for another node                         */
/* Pre	   bst has been created				*/
/* Return  1 if full                        */
/*	       0 if there is memory             */
int fullBST (BST * bst)
{
	BST_NODE * temp;

	if ((temp = (BST_NODE *) malloc (sizeof(BST_NODE))))
	{
		free (temp);
		return 0;
	}
	return 1;
}


/* Returns the number of elements in the bst	*/
/* Pre	   bst has been created				    */
/* Return  bst count							*/
int BSTCount (BST * bst)
{
	return bst->count;
}


/* Deletes all data from a bst and recycles		*/
/* its memory, then deletes and recycles bst	*/
/* head pointer                                 */
/* Pre	   bst is created						*/
/* Post	   all data have been deleted and       */
/*             recycled                         */
/* Return  null pointer                         */
BST *destroyBST (BST * bst)
{
	if (bst)
		_destroy(bst->root);
	free(bst);
	return NULL;
}


/* internal destroy function - uses recursion to	*/
/* free all memory for data and tree node			*/
/* Pre		root is pointer to current root			*/
/* Post		all data and nodes are freed			*/
/* Return	null									*/
void _destroy(BST_NODE * root)
{
	if (root)
	{
		_destroy(root->left);
		free (root->dataPtr);
		_destroy(root->right);
		free(root);
	}
	return;
}
	


