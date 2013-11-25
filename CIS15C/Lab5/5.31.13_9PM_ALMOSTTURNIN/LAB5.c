//  LAB 5: Using a randomized array of ints, sort the array with a heap, shell, and quick sort
//  and print out the number of comparisons and moves for each sort
//  Created by Evan Chen on 5/30/13.

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define MAX_ARRAY 100

//NOT DONE YET

//Function Prototypes
/*1*/void sortHeap(int randomArray[],int last,int*compares,int*moves);
/*2*/void sortShell(int randomArray[],int last,int*compares,int*moves);
/*3*/void sortQuick(int randomArray[],int first,int last,int*compares,int*moves);
/*4*/void printArray(int randomArray[]);
/*5*/void reheapUp(int randomArray[],int newIndex,int*compares,int*moves);
/*6*/void reheapDown(int randomArray[],int root,int last,int*compares,int*moves);
/*7*/void exchange(int randomArray[],int num1,int num2);
/*8*/void medianLeft(int randomArray[],int left,int right,int*compares,int*moves);
/*9*/void sortInsertion(int randomArray[],int last,int*compares,int*moves);
/*10*/void makeNearSort(int randomArray[]);

int main(void)
{
	int randomArray[MAX_ARRAY];
	int randomNum,i;
    int* compares;
    int* moves;
    int comNum = 0;
    int moveNum = 0;
    
    compares = &comNum;
    moves = &moveNum;
    
    //Randomize the array
	srand((unsigned int)time(NULL));
	for(i=0;i<MAX_ARRAY;i++){
		randomNum = (rand() % (7500+1 - 0))+0;
		randomArray[i] = randomNum;
	}//end for
    
    //Heap Sorting
    sortHeap(randomArray,MAX_ARRAY-1,compares,moves);
	if(MAX_ARRAY == 100)
        printArray(randomArray);
    printf("\nArray Size: %d\n",MAX_ARRAY);
    printf("random list heapSort:  compares = %d  moves = %d\n",*compares,*moves);
    makeNearSort(randomArray);
    sortHeap(randomArray,MAX_ARRAY-1,compares,moves);
    printf("nearly ordered heapSort:  compares = %d  moves = %d\n\n",*compares,*moves);
    
    //Shell Sorting
    sortShell(randomArray,MAX_ARRAY-1,compares,moves);
	if(MAX_ARRAY == 100)
        printArray(randomArray);
    printf("\nArray Size: %d\n",MAX_ARRAY);
    printf("random list shellSort:  compares = %d  moves = %d\n",*compares,*moves);
    makeNearSort(randomArray);
    sortShell(randomArray,MAX_ARRAY-1,compares,moves);
    printf("nearly ordered shellSort:  compares = %d  moves = %d\n\n",*compares,*moves);
    
    //Quick Sorting
    *compares = 0;
    *moves = 0;
    sortQuick(randomArray,0,MAX_ARRAY-1,compares,moves);
    if(MAX_ARRAY == 100)
        printArray(randomArray);
    printf("\nArray Size: %d\n",MAX_ARRAY);
    printf("random list quickSort:  compares = %d  moves = %d\n",*compares,*moves);
    makeNearSort(randomArray);
    *compares = 0;
    *moves = 0;
    sortQuick(randomArray,0,MAX_ARRAY-1,compares,moves);
    printf("nearly ordered quickSort:  compares = %d  moves = %d\n\n",*compares,*moves);
    
    printf("The most efficient sort for a large, random list is: \n");   //NOT DONE YET
    printf("The most efficient sort for a large, nearly ordered list is: \n");
    printf("The most efficient sort for a small, random list is: \n");
    printf("The most efficient sort for a small, nearly ordered list is: \n");
    
	return 0;
}

/*sortHeap: This function will sort the array passed in with a heap sort. It will
 also count the number of compares and moves while the heapsort is running.
 Input: randomArray(array of ints),last(int),compares(int*),moves(int*)
 Return: Nothing*/
/*1*/void sortHeap(int randomArray[],int last,int*compares,int*moves)
{
    int sorted;
	int walker = 1;
    
    *compares = 0;
    *moves = 0;
    
	while(walker<=last){
		reheapUp(randomArray,walker,compares,moves);
		walker = walker+1;
	}//end while
	sorted = last;
	while(sorted > 0){
		exchange(randomArray,0,sorted);
        *moves+=3;
		sorted = sorted-1;
		reheapDown(randomArray,0,sorted,compares,moves);
	}//end while
}//end sortHeap

/*sortShell: This function will sort the array passed in with a shell
 sort. It will also count the number of compares and moves while the 
 heapsort is running.
 Input: randomArray(array of ints),last(int),compare(int*),moves(int*)
 Return: Nothing*/
/*2*/void sortShell(int randomArray[],int last,int*compare,int*moves)
{
	int increment,current,hold,walker;
    
    *compare = 0;
    *moves = 0;
	increment = (last)/2;
	while(increment != 0){
		for(current = increment; current<=last;current++){
			hold = randomArray[current];
            *moves+=1;
			walker = current - increment;
			while(walker >= 0 && (*compare+=1,hold>=randomArray[walker])){ //Determines ascending or descending
				randomArray[walker+increment] = randomArray[walker];
                *moves+=1;
				walker = (walker - increment);
			}//end while
			randomArray[walker+increment] = hold;
            *moves+=1;
		}//end for
		increment = increment/2;
	}//end while
}//end sortShell

/*sortQuick: This function will sort the array passed in with a quick sort
 It will also count the number of compares and moves while the heapsort is 
 running.
 Input: randomArray(array of ints),left(int),right(int),compares(int*),moves(int*)
 Return: Nothing*/
/*3*/void sortQuick(int randomArray[],int left,int right,int*compares,int*moves)
{
	int pivot,sortLeft,sortRight;

	if((right - left) >= 3){
		medianLeft(randomArray,left,right,compares,moves);
		pivot = randomArray[left];
        *moves+=1;
		sortLeft = left+1;
		sortRight = right;
		while(sortLeft <= sortRight){
			while(*compares+=1,randomArray[sortLeft] >= pivot){ //Determines ascending or descending
				sortLeft = sortLeft+1;;
			}//end while
			while(*compares+=1,randomArray[sortRight] < pivot){ //Determines ascending or descending
				sortRight = sortRight-1;;
			}//end while
			if(sortLeft <= sortRight){
				exchange(randomArray,sortLeft,sortRight);
                *moves+=3;
				sortLeft = sortLeft+1;
				sortRight = sortRight-1;;
			}//end if
		}//end while
		randomArray[left] = randomArray[sortLeft-1];
        *moves+=1;
		randomArray[sortLeft-1] = pivot;
        *moves+=1;
		if(left < sortRight)
			sortQuick(randomArray,left,sortRight-1,compares,moves);
		if(sortLeft < right)
			sortQuick(randomArray,sortLeft,right,compares,moves);
	}//end if
	else
		sortInsertion(randomArray,right,compares,moves);
}//end sortQuick

/*printArray: prints the array passed in as a 10x10
 Input: randomArray(array of ints)
 Return: Nothing*/
/*4*/void printArray(int randomArray[])
{
	int i;
    
	for(i=0;i<MAX_ARRAY;i++){
		printf("%-5d",randomArray[i]);
		if(((i+1)%10)==0 && i!= 0)
			printf("\n");
	}//end for
}//end printArray

/*reheapUp: This function is called by the heap sort to 
 sort the array starting from the last element up. With an array
 implementation, this works from right to left. It continues using
 recursion.
 Input: randomArray(array of ints),newIndex(int),compares(int*),moves(int*)
 Return: Nothing*/
/*5*/void reheapUp(int randomArray[],int newIndex,int*compares,int*moves)
{
    int parent;
    
    if(newIndex != 0){
        parent = (newIndex-1)/2;
        if(*compares+=1,randomArray[newIndex] < randomArray[parent]){ //Determines ascending or descending
            exchange(randomArray,newIndex,parent);
            *moves+=3;
            reheapUp(randomArray,parent,compares,moves);
        }//end if
    }//end if
}//end reheapUp

/*reheapDown: This function is called by heap sort to sort the
 array and is sort of like the opposite of reheapUp. It starts from
 the very top of the heap (left in array implementation) and then
 sorts towards the right, comparing parent with its largest child
 node(smallest in our case as we are doing descending order).
 Input: randomArray(array of ints),root(int),last(int),compares(int*),moves(int*)
 Return: Nothing*/
/*6*/void reheapDown(int randomArray[],int root,int last,int*compares,int*moves)
{
    int leftKey,rightKey,largeChildIndex;
    
    if((root*2+1) <= last){
        leftKey = randomArray[root*2+1];
        *moves+=1;
        if((root*2+2) <= last){
            rightKey = randomArray[root*2+2];
            *moves+=1;
        }//end if
        else{
            rightKey = 7500;
            *moves+=1;
        }//end else
        if(leftKey < rightKey)  //Determines ascending or descending
            largeChildIndex = root*2+1;
        else
            largeChildIndex = root*2+2;
        if(*compares+=1,randomArray[root] > randomArray[largeChildIndex]) //Determines ascending or descending
        {
            exchange(randomArray,root,largeChildIndex);
            *moves+=3;
            reheapDown(randomArray,largeChildIndex,last,compares,moves);
        }//end if
    }//end if
}//end reheapDown

/*exchange: This is the swap function that is called to swap
 two values at the indexes passed in.
 Input: randomArray(array of ints),left(int),right(int)
 Return: Nothing*/
/*7*/void exchange(int randomArray[],int left,int right)
{
	int temp;
    
	temp = randomArray[left];  //left index's value saved into temp
	randomArray[left] = randomArray[right]; //right index's value saved into left index
	randomArray[right] = temp; //right index's value is temp;
}//end exchange

/*medianLeft: This function is used to determine the pivot that will be
 used by the Quick Sort.
 Input: randomArray(array of ints),left(int),right(int),compares(int*),moves(int*)
 Return: Nothing*/
/*8*/void medianLeft(int randomArray[],int left,int right,int*compares,int*moves)
{
	int mid;
    
	mid = (left+right)/2;
	if(*compares+=1,randomArray[left] > randomArray[mid]){
		exchange(randomArray,left,mid);
        *moves+=3;
    }//end if
	if(*compares+=1,randomArray[left] > randomArray[right]){
		exchange(randomArray,left,right);
        *moves+=3;
    }//end if
	if(*compares+=1,randomArray[mid] > randomArray[right]){
		exchange(randomArray,mid,right);
        *moves+=3;
    }//end if
	exchange(randomArray,left,mid);
    *moves+=3;
}//end medianLeft

/*sortInsertion: This function is called by the quick Sort
 if the array passed in is too small. Using insertion sort
 for small arrays is more efficient.
 Input: randomArray(array of ints),last(int),compares(int*),moves(int*)
 Return: Nothing*/
/*9*/void sortInsertion(int randomArray[],int last,int*compares,int*moves) //not sure if this works
{
	int hold;
	int walker;
	int current;
    
	for(current = 1;current<=last;current++){
		hold = randomArray[current];
        *moves+=1;
        walker = current-1;
		while(walker >= 0 && (*compares+=1,randomArray[walker] <= hold)){
			randomArray[walker+1] = randomArray[walker];
            *moves+=1;
            walker--;
        }//end while
		randomArray[walker+1] = hold;
        *moves+=1;
	}//end for
}//end sortInsertion

/*makeNearSort: This function exchanges index 10 with 11
 and 90 with 91 to unsort a piece of the sorted array.
 Input: randomArray(array of ints)
 Return: Nothing*/
/*10*/void makeNearSort(int randomArray[])
{
    exchange(randomArray,10,11);
    exchange(randomArray,90,91);
}//end exchange



