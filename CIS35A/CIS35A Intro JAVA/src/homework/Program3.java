 /*
 Program Name: Programming HW #3: Game of Minesweeper (OBJECTS)
 Programmer Name: Evan Chen
 Date: February 11th, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 3 MAIN: This is the main part of the Minesweeper program. This part of the program will first Welcome the user and 
 ask for what dimensions they would like to use for the Minesweeper game. Most of this program is similar to homework 2 except for
 the usage of objects. Instead of having 3 two dimensional arrays, this program declares 3 object variables that are instantiated by
 another object's instance method. The program asks the user for rows and columns and then the other object's instance method
 instantiates the two of the object variables to the provided dimensions. Furthermore, this program will use a static method to
 request which rows and columns to guess for mines. The guesses will be passed to the other object to assign to the previous two instantiated
 object variables. The other object's instance method will then compare the two object variable arrays and use another instance method to 
 display all three to the user. (The three object variables represent the userGrid,gameGrid,resultsGrid)
 The program will then ask if the player wishes to play again.
 */

package homework;

import java.util.Scanner;

public class Program3 {
	static Scanner scanner = new Scanner(System.in);
	public static void main(String[] args) {
		String row = "Please enter the number of rows: ";
		String column = "Please enter the number of columns: ";
		int numRow, numColumn, numSpots,i;
		boolean repeatPlay = true;
		MineGrid userGrid;
		MineGrid gameGrid;
		MineGrid resultsGrid;
	
		System.out.print("Welcome to Minesweeper!\n");
		System.out.print("What dimensions would you like (Between 5- 20)?\n\n");
		numRow = Homework2_readDim.InputMethods(row);
		numColumn = Homework2_readDim.InputMethods(column);
		System.out.printf("Rows entered: %d, Columns Entered: %d\nThank you!\n\n",numRow,numColumn);
		
		userGrid = new MineGrid(numRow,numColumn);
		gameGrid = new MineGrid(numRow,numColumn);
		numSpots = (numRow+numColumn)/2;
		
		while(repeatPlay == true){
			gameGrid.setrandSpots(numSpots);
			setInput(userGrid, numSpots);
			resultsGrid = gameGrid.compareGrid(userGrid);
			System.out.print("\nYour guesses\n");
			userGrid.displayGrid('G');
			System.out.print("Game Mines\n");
			gameGrid.displayGrid('*');
			System.out.print("Your Matches\n");
			resultsGrid.displayGrid('M');
			repeatPlay = Homework2_readDim.playAgain();
		}
		System.out.print("Thank you for playing Minesweeper!");
	}
	
	public static void setInput(MineGrid tempGrid,int numSpots){
		int userRow,userColumn,i;
		
		tempGrid.setinitGrid();
		for(i=0;i<numSpots;i++){
		System.out.print("Please enter a row: ");
		userRow = scanner.nextInt();
		userRow = userRow - 1;
		System.out.print("Please enter a column: ");
		userColumn = scanner.nextInt();
		userColumn = userColumn - 1;
		while((tempGrid.setDimValue(userRow,userColumn))==false){
			System.out.print("Please enter a row that falls within the provided dimensions: ");
			userRow = scanner.nextInt();
			userRow = userRow - 1;
			System.out.print("Please enter a column that falls within the provided dimensions: ");
			userColumn = scanner.nextInt();
			userColumn = userColumn - 1;
			}
		}
	}
}		

/*
Welcome to Minesweeper!
What dimensions would you like (Between 5- 20)?

Please enter the number of rows: 0
Please enter the number of rows: 0
Please enter the number of rows: 22
Please enter the number of rows: 5
Please enter the number of columns: -10
Please enter the number of columns: 23
Please enter the number of columns: 5
Rows entered: 5, Columns Entered: 5
Thank you!

Please enter a row: 5
Please enter a column: 3
Please enter a row: 2
Please enter a column: 2
Please enter a row: 3
Please enter a column: 1
Please enter a row: 
4
Please enter a column: 4
Please enter a row: 1
Please enter a column: 2

Your guesses
--------------------
|   | G |   |   |   |
--------------------
|   | G |   |   |   |
--------------------
| G |   |   |   |   |
--------------------
|   |   |   | G |   |
--------------------
|   |   | G |   |   |
--------------------


Game Mines
--------------------
|   |   |   |   |   |
--------------------
| * | * |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   | * |   |   |   |
--------------------
|   |   |   |   |   |
--------------------


Your Matches
--------------------
|   |   |   |   |   |
--------------------
|   | M |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------


Would you like to play again? yes
Please enter a row: 5
Please enter a column: 1
Please enter a row: 3
Please enter a column: 2
Please enter a row: 3
Please enter a column: 3
Please enter a row: 4
Please enter a column: 1
Please enter a row: 53
Please enter a column: 5
Please enter a row that falls within the provided dimensions: 3
Please enter a column that falls within the provided dimensions: 5

Your guesses
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   | G | G |   | G |
--------------------
| G |   |   |   |   |
--------------------
| G |   |   |   |   |
--------------------


Game Mines
--------------------
|   |   |   |   | * |
--------------------
|   |   |   | * |   |
--------------------
|   |   |   |   |   |
--------------------
|   | * | * | * |   |
--------------------
|   |   |   |   |   |
--------------------


Your Matches
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------


Would you like to play again? yes
Please enter a row: 1
Please enter a column: 2
Please enter a row: 3
Please enter a column: 4
Please enter a row: 5
Please enter a column: 2
Please enter a row: 3
Please enter a column: 4
Please enter a row: 2
Please enter a column: 1

Your guesses
--------------------
|   | G |   |   |   |
--------------------
| G |   |   |   |   |
--------------------
|   |   |   | G |   |
--------------------
|   |   |   |   |   |
--------------------
|   | G |   |   |   |
--------------------


Game Mines
--------------------
| * |   |   |   | * |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   | * |   |
--------------------
|   |   | * |   |   |
--------------------
|   | * |   |   |   |
--------------------


Your Matches
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   | M |   |
--------------------
|   |   |   |   |   |
--------------------
|   | M |   |   |   |
--------------------


Would you like to play again? yes
Please enter a row: 1
Please enter a column: 1
Please enter a row: 2
Please enter a column: 2
Please enter a row: -10
Please enter a column: -10
Please enter a row that falls within the provided dimensions: 2
Please enter a column that falls within the provided dimensions: 4
Please enter a row: 20
Please enter a column: 20
Please enter a row that falls within the provided dimensions: 5
Please enter a column that falls within the provided dimensions: 1
Please enter a row: 2
Please enter a column: 4

Your guesses
--------------------
| G |   |   |   |   |
--------------------
|   | G |   | G |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
| G |   |   |   |   |
--------------------


Game Mines
--------------------
|   | * | * |   |   |
--------------------
|   |   | * |   |   |
--------------------
|   |   | * |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------


Your Matches
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------


Would you like to play again? yes
Please enter a row: 500
Please enter a column: 400
Please enter a row that falls within the provided dimensions: 1
Please enter a column that falls within the provided dimensions: 2
Please enter a row: 3
Please enter a column: 1
Please enter a row: 5
Please enter a column: 1
Please enter a row: 4
Please enter a column: 4
Please enter a row: 4
Please enter a column: 2

Your guesses
--------------------
|   | G |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
| G |   |   |   |   |
--------------------
|   | G |   | G |   |
--------------------
| G |   |   |   |   |
--------------------


Game Mines
--------------------
| * |   |   |   | * |
--------------------
|   | * |   |   |   |
--------------------
|   |   | * |   | * |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------


Your Matches
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------


Would you like to play again? no
Thank you for playing Minesweeper!
*/
