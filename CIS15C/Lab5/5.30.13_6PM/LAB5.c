
//ALL SORTS ARE STILL DOING ASCENDING ORDER, MUST CHANGE ALL TO DESCENDING ORDER LATER.

//!!!!!!!!!!!!!!!!!!!!!!!!


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY 100

/*1*/void sortHeap(int randomArray[]); //may need to return success or fail
/*2*/void sortShell(int randomArray[]);
/*3*/void sortQuick(int randomArray[],int first,int last);
/*4*/void printArray(int randomArray[]);
/*5*/void reheapUp();
/*6*/void reheapDown();
/*7*/void exchange(int randomArray[],int num1,int num2);
/*8*/void medianLeft(int randomArray[],int left,int right);
/*9*/void sortInsertion(int randomArray[]);

int main(void)
{
	int randomArray[MAX_ARRAY];
	int randomNum;
	int i;

	srand(time(NULL));
	for(i=0;i<MAX_ARRAY;i++){
		randomNum = (rand() % (7500+1 - 0))+0;
		randomArray[i] = randomNum;
	}
	sortQuick(randomArray,0,MAX_ARRAY-1);
	printArray(randomArray);


	return 0;
}

/*1*/void sortHeap(int randomArray[]) //may need to return success or fail
{
	int walker = 1;
	int sorted;

	while(walker<=MAX_ARRAY){
		//need to use reheapUp here
		walker++;
	}
	sorted = randomArray[MAX_ARRAY]; //sets sorted to last
	while(sorted > 0){ //Not sure if this works cause we are doing descending order rather than ascending
		//need to use exchange function here
		sorted = sorted - 1;
		//reheapDown here;
	}

}

/*2*/void sortShell(int randomArray[])
{
	int increment,current,hold,walker;

	increment = (MAX_ARRAY)/2;
	while(increment != 0){
		for(current = increment; current<MAX_ARRAY;current++){
			hold = randomArray[current];
			walker = current - increment;
			while(walker >= 0 && hold<randomArray[walker]){ //This is where it is ascending
				randomArray[walker+increment] = randomArray[walker]; //This is moving element up in list
				walker = (walker - increment);
			}//end while
			randomArray[walker+increment] = hold;
		}//end for
		increment = increment/2;
	}//end while
}

/*3*/void sortQuick(int randomArray[],int left,int right)
{
	int pivot,sortLeft,sortRight;
	
	if((right - left) > 0){
		medianLeft(randomArray,left,right);
		pivot = randomArray[left]; //pivot = median
		sortLeft = left+1;
		sortRight = right;
		while(sortLeft <= sortRight){
			while(randomArray[sortLeft] < pivot){ //greater and equal to maybe?
				sortLeft++;
			}
			while(randomArray[sortRight] >= pivot){
				sortRight--;
			}
			if(sortLeft<=sortRight){
				exchange(randomArray,sortLeft,sortRight);
				sortLeft++;
				sortRight--;
			}
		}
		randomArray[left] = randomArray[sortLeft-1];
		randomArray[sortLeft-1] = randomArray[pivot];
		if(left<sortRight)
			sortQuick(randomArray,left,sortRight-1);
		if(sortLeft<right)
			sortQuick(randomArray,sortLeft,right);
	}
	else
		sortInsertion(randomArray,right);
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

/*7*/void exchange(int randomArray[],int left,int right)
{
	int temp;

	temp = randomArray[left];  //left index's value saved into temp
	randomArray[left] = randomArray[right]; //right index's value saved into left index
	randomArray[right] = temp; //right index's value is temp;
}

/*8*/void medianLeft(int randomArray[],int left,int right)
{
	int mid;

	mid = (left+right)/2;
	if(randomArray[left] > randomArray[mid])
		exchange(randomArray,left,mid);
	if(randomArray[left] > randomArray[right])
		exchange(randomArray,left,right);
	if(randomArray[mid] > randomArray[right])
		exchange(randomArray,mid,right);
	exchange(randomArray,left,mid);
}

/*9*/void sortInsertion(int randomArray[],int last) //not sure if this works
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