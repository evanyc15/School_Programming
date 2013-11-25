//Evan Chen

package exercises;

import java.util.Scanner;

public class Exercise3_2 {
	static Scanner scanner = new Scanner(System.in);
	
	public static void main(String[] args) {
		int num1,num2,num3;
		int average;
		int largest;
		
		System.out.println("Please enter three numbers\n\nEnter Number 1: ");
		num1 = scanner.nextInt();
		System.out.println("Please enter Number 2: ");
		num2 = scanner.nextInt();
		System.out.println("Please enter Number 3: ");
		num3 = scanner.nextInt();
		
		average = averageNum(num1,num2,num3);
		largest = largestNum(num1,num2,num3);
		
		System.out.println("The average is " +average);
		System.out.println("The largest number is " +largest);
	}
	
	public static int averageNum(int num1,int num2,int num3){
		int average;
		
		average = (num1+num2+num3)/3;
		average = Math.round(average);
		
		return average;
	}
	
	public static int largestNum(int num1,int num2,int num3){
		int temp;
		
		temp = num1;
		if(temp<=num2)
			temp = num2;
		if(temp<=num3)
			temp = num3;
		
		return temp;
	}
}


/*OUTPUT
 
Please enter three numbers
 
Enter Number 1: 
9849
Please enter Number 2: 
9850
Please enter Number 3: 
9851
The average is 9850
The largest number is 9851

*/
