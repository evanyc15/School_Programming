//Evan Chen
//Exercise 4.2

package exercises;

import java.util.Scanner;

public class Exercise4_2 {
	static Scanner scanner = new Scanner(System.in);
	
	public static void main(String[] args) {
	int array1[][] = null;
	
	array1 = createArray(array1);
	initArray(array1);
	printArray(array1);
	
	}
	public static int[][] createArray(int array1[][]) {
		int row,column;
		
		System.out.println("Please enter the number of rows for array: ");
		row = scanner.nextInt();
		System.out.println("Please enter the number of columns for array: ");
		column = scanner.nextInt();
		array1 = new int[row][column];
		return array1;
	}
	
	public static void initArray(int array1[][]){
		int i,j;
		
		for(i=0;i<array1.length;i++){
			for(j=0;j<array1[0].length;j++){
				array1[i][j] = i+j;
			}
		}
	}
	public static void printArray(int array1[][]){
		int i,j;
		
		for(i=0;i<array1.length;i++){
			for(j=0;j<array1[0].length;j++){
				System.out.print("\t"+array1[i][j]);
			}
			System.out.print("\n");
		}
	}
}

/*Output
  
Please enter the number of rows for array: 
5
Please enter the number of columns for array: 
7
	0	1	2	3	4	5	6
	1	2	3	4	5	6	7
	2	3	4	5	6	7	8
	3	4	5	6	7	8	9
	4	5	6	7	8	9	10
*/
