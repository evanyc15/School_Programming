/*
 Program Name: Programming HW #2: Game of Minesweeper
 Programmer Name: Evan Chen
 Date: January 30th, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 2 secondary: This class contains methods that are mainly used for prompting the user for dimensions of the game grid or dimensions
 of what row and column they wish to guess on. It also contains a method that will prompt the user if they wish to play again when the
 game is finished. If yes, then the game will ask the user for new guesses.
 */

package homework;

import java.util.Scanner;

public class Homework2_readDim {
	static Scanner scanner = new Scanner(System.in);
	public static final int MAX = 20;
	public static final int MIN = 5;
		
		public static int InputMethods(String askDimension){
			int userDimension;
			
			System.out.print(askDimension);
			userDimension = scanner.nextInt();
			while(userDimension<MIN || userDimension>MAX){
				System.out.print(askDimension);
				userDimension = scanner.nextInt();
			}
			
			return userDimension;
	}
		
		public static int readuserRow(boolean filledArray[][]){
			int userRow;
			
			System.out.print("Please enter a row: ");
			userRow = scanner.nextInt();
			userRow = userRow - 1;
			while(userRow<0 || userRow>=filledArray.length){
				System.out.print("Please enter a row that falls within the provided dimensions: ");
				userRow = scanner.nextInt();
				userRow = userRow - 1;
			}
			
			return userRow;
		}
		
		public static int readuserColumn(boolean filledArray[][]){
			int userColumn;
			
			System.out.print("Please enter a column: ");
			userColumn = scanner.nextInt();
			userColumn = userColumn - 1;
			while(userColumn<0 || userColumn>=filledArray[0].length){
				System.out.print("Please enter a column that falls within the provided dimensions: ");
				userColumn = scanner.nextInt();
				userColumn = userColumn - 1;
			}
			
			return userColumn;
		}
		
		public static boolean playAgain(){
			String answer;
			
			System.out.print("Would you like to play again? ");
			answer = scanner.next();
			if(answer.startsWith("y") || answer.startsWith("Y"))
				return true;
			else
				return false;
		}
}
