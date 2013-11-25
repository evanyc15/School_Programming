//
//  LAB5.c
//  CIS15C_LAB5
//
//  Created by Evan Chen on 5/30/13.
//  Copyright (c) 2013 Evan Chen. All rights reserved.
//

//All are descending
//Insertion Sort is not working and the top row (largest numbers) are not sorting correctly
//Make sure to triple check over all instructions
//Maybe make code easier by passing *moves into exchange so that it won't be so repetitive


#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define MAX_ARRAY 100

/*1*/void sortHeap(int randomArray[],int last,int*compares,int*moves); //may need to return success or fail
/*2*/void sortShell(int randomArray[],int last,int*compares,int*moves);
/*3*/void sortQuick(int randomArray[],int first,int last,int*compares,int*moves);
/*4*/void printArray(int randomArray[]);
/*5*/void reheapUp(int randomArray[],int newIndex,int*compares,int*moves);
/*6*/void reheapDown(int randomArray[],int root,int last,int*compares,int*moves);
/*7*/void exchange(int randomArray[],int num1,int num2);
/*8*/void medianLeft(int randomArray[],int left,int right,int*compares,int*moves);
/*9*/void sortInsertion(int randomArray[],int first,int last);
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
	}
    
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
    
	return 0;
}

/*1*/void sortHeap(int randomArray[],int last,int*compares,int*moves) //heap is not sorting the first couple largest numbers
{
    int sorted;
	int walker = 1;
    
    *compares = 0;
    *moves = 0;
    
	while(walker<=last){
		reheapUp(randomArray,walker,compares,moves);
		walker = walker+1;
	}
	sorted = last; //sets sorted to last
	while(sorted > 0){
		exchange(randomArray,0,sorted);
        *moves+=1;
		sorted = sorted-1;
		reheapDown(randomArray,0,sorted,compares,moves);
	}
}

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
}

/*3*/void sortQuick(int randomArray[],int left,int right,int*compares,int*moves)
{
	int pivot,sortLeft,sortRight;

	if((right - left) >= 0){
		medianLeft(randomArray,left,right,compares,moves);
		pivot = randomArray[left];
		sortLeft = left+1;
		sortRight = right;
		while(sortLeft <= sortRight){
			while(*compares+=1,randomArray[sortLeft] >= pivot){ //Determines ascending or descending
				sortLeft = sortLeft+1;;
			}
			while(*compares+=1,randomArray[sortRight] < pivot){ //Determines ascending or descending
				sortRight = sortRight-1;;
			}
			if(sortLeft <= sortRight){
				exchange(randomArray,sortLeft,sortRight);
                *moves+=1;
				sortLeft = sortLeft+1;
				sortRight = sortRight-1;;
			}
		}
		randomArray[left] = randomArray[sortLeft-1];
        *moves+=1;
		randomArray[sortLeft-1] = pivot;
        *moves+=1;
		if(left < sortRight)
			sortQuick(randomArray,left,sortRight-1,compares,moves);
		if(sortLeft < right)
			sortQuick(randomArray,sortLeft,right,compares,moves);
	}
	else
		sortInsertion(randomArray,left,right); //not done with insertion yet, not descending
}

/*4*/void printArray(int randomArray[])
{
	int i;
    
	for(i=0;i<MAX_ARRAY;i++){
		printf("%-5d",randomArray[i]);
		if(((i+1)%10)==0 && i!= 0)
			printf("\n");
	}
}

/*5*/void reheapUp(int randomArray[],int newIndex,int*compares,int*moves)
{
    int parent;
    
    if(newIndex != 0){
        parent = (newIndex-1)/2;
        if(*compares+=1,randomArray[newIndex] < randomArray[parent]){ //Determines ascending or descending
            exchange(randomArray,newIndex,parent);
            *moves+=1;
            reheapUp(randomArray,parent,compares,moves);
        }
    }
}

/*6*/void reheapDown(int randomArray[],int root,int last,int*compares,int*moves)
{
    int leftKey,rightKey,largeChildIndex;
    
    if((root*2+1) <= last){
        leftKey = randomArray[root*2+1];
        if((root*2+2) <= last)
            rightKey = randomArray[root*2+2];
        else
            rightKey = 7500;
        if(leftKey < rightKey)  //Determines ascending or descending
            largeChildIndex = root*2+1;
        else
            largeChildIndex = root*2+2;
        if(*compares+=1,randomArray[root] > randomArray[largeChildIndex]) //Determines ascending or descending
        {
            exchange(randomArray,root,largeChildIndex);
            *moves+=1;
            reheapDown(randomArray,largeChildIndex,last,compares,moves);
        }
    }
    
    
}

/*7*/void exchange(int randomArray[],int left,int right)
{
	int temp;
    
	temp = randomArray[left];  //left index's value saved into temp
	randomArray[left] = randomArray[right]; //right index's value saved into left index
	randomArray[right] = temp; //right index's value is temp;
}

/*8*/void medianLeft(int randomArray[],int left,int right,int*compares,int*moves)
{
	int mid;
    
	mid = (left+right)/2;
	if(*compares+=1,randomArray[left] > randomArray[mid]){
		exchange(randomArray,left,mid);
        *moves+=1;
    }
	if(*compares+=1,randomArray[left] > randomArray[right]){
		exchange(randomArray,left,right);
        *moves+=1;
    }
	if(*compares+=1,randomArray[mid] > randomArray[right]){
		exchange(randomArray,mid,right);
        *moves+=1;
    }
	exchange(randomArray,left,mid);
    *moves+=1;
}

/*9*/void sortInsertion(int randomArray[],int first,int last) //not sure if this works
{
	int hold;
	int walker;
	int current;
    
	for(current = 1;current<last;current++){
		hold = randomArray[last];
		for(walker = current-1;walker>=0 && randomArray[walker]>hold;walker--)
			randomArray[walker+1] = randomArray[walker];
        
		randomArray[walker+1] = hold;
	}
}

/*10*/void makeNearSort(int randomArray[])
{
    exchange(randomArray,10,11);
    exchange(randomArray,90,91);
}
