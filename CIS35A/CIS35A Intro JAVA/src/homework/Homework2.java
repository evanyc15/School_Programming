/*
 Program Name: Programming HW #2: Game of Minesweeper
 Programmer Name: Evan Chen
 Date: January 30th, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 2 MAIN: This is the main part of the Minesweeper program. This part of the program will first Welcome the user and 
 ask for what dimensions they would like to use for the Minesweeper game. It will then save the dimensions and call another method
 to allocate memory for the three two-dimensional arrays. The arrays will be used as follows:
 1. Game grid - The grid that saves random locations of mines for the user to play. 
 2. User grid - The grid that saves the guesses that the user inputs (Prompting and saving through another class's method)
 3. Results grid - The grid that shows if the user chose correctly. (Compare the game grid and user grid through another method)
 The game will then ask if the user wants to play again, if yes then it will ask for new guesses.
 */

package homework;

import java.util.Scanner;


public class Homework2 {
	static Scanner scanner = new Scanner(System.in);
	public static final int MAX = 20;
	public static final int MIN = 5;

	public static void main(String[] args) {
		String row = "Please enter the number of rows: ";
		String column = "Please enter the number of columns: ";
		int numRow, numColumn, numSpots;
		boolean gameGrid[][];
		boolean userGrid[][];
		boolean resultGrid[][];
		
		System.out.print("Welcome to Minesweeper!\n");
		System.out.print("What dimensions would you like (Between 5- 20)?\n\n");
		numRow = Homework2_readDim.InputMethods(row);
		numColumn = Homework2_readDim.InputMethods(column);
		System.out.printf("Rows entered: %d, Columns Entered: %d\nThank you!\n\n",numRow,numColumn);
		
		gameGrid = allocateGrid(numRow,numColumn);
		userGrid = allocateGrid(numRow,numColumn);
		resultGrid = allocateGrid(numRow,numColumn);
		numSpots = (numRow+numColumn)/2;
		setRandomValues(gameGrid,userGrid,resultGrid,numSpots);
	}
	
//1	
	public static boolean[][] allocateGrid(int numRow,int numColumn){
		boolean createArray[][];
		
		if(numRow<1)
			numRow = 1;
		if(numColumn<1)
			numColumn = 1;
		createArray = new boolean[numRow][numColumn];
		
		return createArray;
	}
	
//2	
	public static void setRandomValues(boolean gameGrid[][],boolean userGrid[][],boolean resultGrid[][],int numSpots){
		int i;
		int randRow,randColumn;
		boolean repeatPlay;
		int maxRow = (gameGrid.length)-1;
		int maxColumn = (gameGrid[0].length)-1;
		int min = 0;
		
		System.out.printf("Now to play the game! You can choose %d different spots\n",numSpots);
		System.out.print("Please choose the coordinates you wish to guess:\n\n");
		
		repeatPlay = true;
		while(repeatPlay==true){
			initGrid(gameGrid);
			for(i=0;i<numSpots;i++){
				randRow = (int)(Math.random() * (maxRow-min+1) ) + min;
				randColumn = (int)(Math.random() * (maxColumn-min+1) ) + min;
				if(gameGrid[randRow][randColumn] == false)
					gameGrid[randRow][randColumn] = true;
			}
			
			Homework2_setInputValue.setInputValues(userGrid,numSpots);
			compareGrids(gameGrid,userGrid,resultGrid);
			System.out.print("\nYour guesses\n");
			displayGrid(userGrid,'G');
			System.out.print("Game Mines\n");
			displayGrid(gameGrid,'*');
			System.out.print("Your Matches\n");
			displayGrid(resultGrid,'M');
			repeatPlay = Homework2_readDim.playAgain();
		}
		System.out.print("Thank you for playing Minesweeper!");
	}
	
	public static void initGrid(boolean Array[][]){
		int i,j;
		
		for(i=0;i<Array.length;i++){
			for(j=0;j<Array[0].length;j++){
				Array[i][j] = false;
			}
		}
	}
	
//4
	public static void compareGrids(boolean gameGrid[][],boolean userGrid[][],boolean resultGrid[][]){
		int i,j;
		
		for(i=0;i<gameGrid.length;i++){
			for(j=0;j<gameGrid[0].length;j++){
				if((gameGrid[i][j] == true) && (userGrid[i][j] == true))
					resultGrid[i][j] = true;
				else
					resultGrid[i][j] = false;
			}
		}
	}
	
	public static void displayGrid(boolean filledArray[][],char verify){
		int h,i,j;
		
		for(h=0;h<filledArray[0].length;h++){
			System.out.print("----");
		}
		System.out.print("\n");
		for(i=0;i<filledArray.length;i++){
			for(j=0;j<filledArray[0].length;j++){
				System.out.print("|");
				if(filledArray[i][j]==false)
					System.out.print("   ");
				if(filledArray[i][j]==true)
					System.out.printf(" %c ",verify);
			}
			System.out.print("|\n");
			for(h=0;h<filledArray[0].length;h++){
				System.out.print("----");
			}
			System.out.print("\n");
		}
		
		System.out.print("\n\n");
	}
}

/*OUTPUT

Welcome to Minesweeper!
What dimensions would you like (Between 5- 20)?

Please enter the number of rows: 1
Please enter the number of rows: 21
Please enter the number of rows: 5
Please enter the number of columns: 1
Please enter the number of columns: 28
Please enter the number of columns: 5
Rows entered: 5, Columns Entered: 5
Thank you!

Now to play the game! You can choose 5 different spots
Please choose the coordinates you wish to guess:

Please enter a row: 1
Please enter a column: 2
Please enter a row: 1
Please enter a column: 2
Please enter a row: 3
Please enter a column: 3
Please enter a row: 4
Please enter a column: 4
Please enter a row: 5
Please enter a column: 5

Your guesses
--------------------
|   | G |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   | G |   |   |
--------------------
|   |   |   | G |   |
--------------------
|   |   |   |   | G |
--------------------


Game Mines
--------------------
|   |   |   |   |   |
--------------------
| * |   |   |   |   |
--------------------
| * |   |   |   |   |
--------------------
| * | * |   |   |   |
--------------------
|   |   |   | * |   |
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
Please enter a row: 5
Please enter a column: 1
Please enter a row: 1
Please enter a column: 3
Please enter a row: 2
Please enter a column: 4
Please enter a row: 5
Please enter a column: 2
Please enter a row: 3
Please enter a column: 4

Your guesses
--------------------
|   |   | G |   |   |
--------------------
|   |   |   | G |   |
--------------------
|   |   |   | G |   |
--------------------
|   |   |   |   |   |
--------------------
| G | G |   |   |   |
--------------------


Game Mines
--------------------
|   |   |   |   | * |
--------------------
|   |   |   |   |   |
--------------------
|   | * |   |   | * |
--------------------
|   |   |   |   | * |
--------------------
| * |   |   |   |   |
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
| M |   |   |   |   |
--------------------


Would you like to play again? yes
Please enter a row: 1
Please enter a column: 3
Please enter a row: 2
Please enter a column: 5
Please enter a row: 2
Please enter a column: 1
Please enter a row: 3
Please enter a column: 4
Please enter a row: 2
Please enter a column: 1

Your guesses
--------------------
|   |   | G |   |   |
--------------------
| G |   |   |   | G |
--------------------
|   |   |   | G |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------


Game Mines
--------------------
|   |   |   |   |   |
--------------------
| * |   |   |   |   |
--------------------
|   | * |   | * |   |
--------------------
| * |   |   |   |   |
--------------------
|   |   | * |   |   |
--------------------


Your Matches
--------------------
|   |   |   |   |   |
--------------------
| M |   |   |   |   |
--------------------
|   |   |   | M |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------


Would you like to play again? yes
Please enter a row: 1
Please enter a column: 2
Please enter a row: 3
Please enter a column: 1
Please enter a row: 4
Please enter a column: 5
Please enter a row: 5
Please enter a column: 1
Please enter a row: 2
Please enter a column: 3

Your guesses
--------------------
|   | G |   |   |   |
--------------------
|   |   | G |   |   |
--------------------
| G |   |   |   |   |
--------------------
|   |   |   |   | G |
--------------------
| G |   |   |   |   |
--------------------


Game Mines
--------------------
|   | * |   |   | * |
--------------------
|   |   |   |   |   |
--------------------
| * |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   | * | * |   |   |
--------------------


Your Matches
--------------------
|   | M |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
| M |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------
|   |   |   |   |   |
--------------------


Would you like to play again? no
Thank you for playing Minesweeper!
*/