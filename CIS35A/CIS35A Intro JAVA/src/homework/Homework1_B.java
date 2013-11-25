/*
 Program Name: Programming HW #1: Displaying and Initializing 
 Programmer Name: Evan Chen
 Date: January 16th, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Problem B: Initialize int to 0x468A in a loop 3 times. Rotate int to the right
 	by 4 bits and store back into int variable. Then, print the variable
 	in hexadecimal format.
 Variable Names: num and temp. num is the int that will be manipulated.
 temp is to store the manipulated num which will then be stored back into num
 */

package homework;

public class Homework1_B {
	public static void main(String[] args) {
	int num,temp; //Local Variable
	num = 0x468A; //Initializing num
	
	for(int i=0;i<3;i++){
	temp = (num << (32-4)); //temp variable to store 4 rightmost bits
	num = (num >>> 4) | temp; //rotating to right by 4 bits
	System.out.printf("%X\n",num); //printing in hexadecimal format
	}
	}
}

/*OUTPUT

A0000468
8A000046
68A00004

*/