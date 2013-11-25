/*
 Program Name: Programming HW #2: Game of Minesweeper
 Programmer Name: Evan Chen
 Date: January 30th, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 2 secondary: This class contains the method that will save the user's guesses.  
 */

package homework;

public class Homework2_setInputValue {

//3
	public static void setInputValues(boolean userGrid[][], int numSpots){
		int userRow,userColumn,i;
		
		Homework2.initGrid(userGrid);
		for(i=0;i<numSpots;i++){
			userRow = Homework2_readDim.readuserRow(userGrid);
			userColumn = Homework2_readDim.readuserColumn(userGrid);
			if(userGrid[userRow][userColumn] == false)
				userGrid[userRow][userColumn] = true;
		}
	}
}
