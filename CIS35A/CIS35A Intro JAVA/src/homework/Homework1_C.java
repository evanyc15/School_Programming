/*
 Program Name: Programming HW #1: Displaying and Initializing 
 Programmer Name: Evan Chen
 Date: January 16th, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Problem C: Display all of the Perfect Numbers between 2 and 500 (inclusive)
 Variable Names: sum, i, j, MAX, MIN. sum is used to calculate if the factors add
 up to the number so it can be determined a perfect number of not. i and j are 
 used in the for loop. MAX and MIN are 500 and 2 respectively and are the range of numbers
 the program is trying to find perfect numbers in.
 */

package homework;

public class Homework1_C {
	public static final int MAX =500;
	public static final int MIN = 2;
	public static void main(String[] args) {
	int sum,i,j; //Local Variables
	
	for(i=MIN;i<=MAX;i++){ //for loop to find perfect squares between 2 and 500
		sum=0;
		for(j=1;j<i;j++){
			if(i%j==0){
			sum+=j;
			}
		}
		if(sum==i){
		System.out.printf(i+" \n"); //display perfect square when found
		}
	}
	}
}


/*OUTPUT

6 
28 
496 

*/