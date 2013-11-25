 /*
 Program Name: Programming HW #3: Game of Minesweeper (OBJECTS)
 Programmer Name: Evan Chen
 Date: February 11th, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 3 Object: This is thepart of the Minesweeper program that contains the object class. This part of the program
 contains two constructors which do the following:
 Constructor 1: Check row and column that it fits in dimensions and then create a new array grid.
 Constructor 2: Check the dimensions fit within min/max dimensions. If they do not, then they will be changed to default
 dimensions. If they do, then the parameter array will be read into the object's array grid.
 This program also contains the instance methods that will set random spots of the arrays to true (mines), initialize all
 elements of an array to false, put user's value into the grid arrays, compare grid arrays, and display the
 three grid arrays for the user.
 */

package homework;

public class MineGrid {

	private boolean[][] grid;
	private static int MIN_DIM = 5;
	private static int MAX_DIM = 20;
	
	public MineGrid(int row, int column){
		if(row<MIN_DIM)
			row = MIN_DIM;
		if(row>MAX_DIM)
			row = MAX_DIM;
		if(column<MIN_DIM)
			column = MIN_DIM;
		if(column>MAX_DIM)
			column = MAX_DIM;
		grid = new boolean[row][column];
	}
	
	public MineGrid(boolean[][] array){
		boolean columnCheck = true;
		boolean minDimCheck = true;
		boolean maxDimCheck = true;
		int i,columnNum;
		
		if(array.length<MIN_DIM)
			minDimCheck = false;
		if(array.length>MAX_DIM)
			maxDimCheck = false;
		columnNum = array[0].length;
		for(i=0;i<array.length;i++){
			if(columnNum!=array[i].length)
				columnCheck = false;
			if(array[i].length<MIN_DIM)
				minDimCheck = false;
			if(array[i].length>MAX_DIM)
				maxDimCheck = false;
		}
		if((minDimCheck==false)||(maxDimCheck==false)||(columnCheck==false)){
			grid = new boolean[MIN_DIM][MIN_DIM];
		}
	
		grid = array;
	}
	//1
	public int getRow(){
		return grid.length;
	}
	//2
	public int getColumn(){
		return grid[0].length;
	}
	//3
	public void setrandSpots(int numSpots){
		int i;
		int randRow,randColumn;
		int maxRow = (grid.length)-1;
		int maxColumn = (grid[0].length)-1;
		int min = 0;
		
		setinitGrid();
		for(i=0;i<numSpots;i++){
			randRow = (int)(Math.random() * (maxRow-min+1) ) + min;
			randColumn = (int)(Math.random() * (maxColumn-min+1) ) + min;
			if(grid[randRow][randColumn] == false)
				grid[randRow][randColumn] = true;
		}
	}
	//4
	public void setinitGrid(){
		int i,j;
		for(i=0;i<grid.length;i++){
			for(j=0;j<grid[0].length;j++){
				grid[i][j] = false;
			}
		}
	}
	//5
	public boolean setDimValue(int row, int column){
		int arrayRow,arrayColumn;
		arrayRow = getRow() -1;
		arrayColumn = getColumn() -1;
		
		if((row<0)||(row>arrayRow)){
			return false;
		}
		if((column<0)||(column>arrayColumn)){
			return false;
		}
		grid[row][column] = true;
		return true;
	}
	//6
	public boolean getArrayElement(int row, int column){
		int arrayRow,arrayColumn;
		arrayRow = getRow() -1;
		arrayColumn = getColumn() -1;
		boolean element;
		
		
		if((row<0)||(row>arrayRow)||(column<0)&&(column>arrayColumn)){
			return false;
		}
		element = grid[row][column];
		return element;
	}
	//7
	public MineGrid compareGrid(MineGrid filledGrid){
		int i,j;
		boolean tempGrid[][] = null;
		
		if((grid.length==filledGrid.grid.length)&&(grid[0].length==filledGrid.grid[0].length)){
			tempGrid = new boolean[grid.length][grid[0].length];
			for(i=0;i<grid.length;i++){
				for(j=0;j<grid[0].length;j++){
					if((filledGrid.grid[i][j]==true)&&(grid[i][j]==true)){
						tempGrid[i][j]=true;
					}
						
				}
			}
		}
		return new MineGrid(tempGrid);
	}
	//8
	public void displayGrid(char verify){
		int h,i,j;
		
		for(h=0;h<grid[0].length;h++){
			System.out.print("----");
		}
		System.out.print("\n");
		for(i=0;i<grid.length;i++){
			for(j=0;j<grid[0].length;j++){
				System.out.print("|");
				if(grid[i][j]==false)
					System.out.print("   ");
				if(grid[i][j]==true)
					System.out.printf(" %c ",verify);
			}
			System.out.print("|\n");
			for(h=0;h<grid[0].length;h++){
				System.out.print("----");
			}
			System.out.print("\n");
		}
		System.out.print("\n\n");
	}
}
