 /*
 Program Name: Programming HW #7: KenoGame
 Programmer Name: Evan Chen
 Date: March 25, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 7 KenoGame: This object contains the data for the Keno Game.
 It contains the multi dimensional array that holds the payoff values the user
 gets depending on how many spots they chose and how many matched. The
 methods in this object will also return values that determine if the user's
 input is within bounds or has been chosen already. It will then call
 the methods to check for matches and calculate the winnings. Finally,
 all the results are displayed by calling the data from the other objects.
 */

package homework;

public class KenoGame7 implements NumberGameInterface7 {
	
		public static final int MAX_KENO_NUMBER = 80;
		public static final int DRAWN_NUMBERS = 20;
		public static final double [][] payoffAmounts = {{0},
			 {0, 2.75},
			 {0, 1., 5.},
			 {0, 0, 2.50, 25.00},
			 {0, 0, 1.0, 5.0, 80.0},
			 {0, 0, 0,  2.0, 10.0, 600.0},
			 {0, 0, 0,  1.0, 8.0, 50., 1499.0},
			 {0, 0, 0,  0,  5.0, 10.0, 250., 1500.0},
			 {0,  0,  0,  0,4.00, 8.00, 40.00, 400.00, 10000.00},
			 {0,  0,  0,  0, 2.00, 5.00, 20.00, 80.00, 2500.00, 15000.00},
			 {0,  0,  0,  0,  0, 2.00, 30.00, 100.00, 500.00, 3000.00, 17500.00},
			 {0,  0,  0,  0,  0, 2.00, 15.00, 50.00, 80.00, 800.00, 8000.00, 27500.00},
			 {0,  0,  0,  0,  0, 1.00, 5.00, 30.00, 90.00, 500.00, 2500.00, 15000.00, 30000.00},
			 {0,  0,  0,  0,  0, 1.00, 2.00, 10.00, 50.00, 500.00, 1000.00, 10000.00, 15000.00, 30000.00},
			 {0,  0,  0,  0,  0, 0, 2.00, 8.00, 32.00, 300.00, 800.00, 2500.00, 12000.00, 18000.00, 30000.00},
			 {0,  0,  0,  0,  0, 0, 1.00, 7.00, 21.00, 100.00, 400.00, 2000.00, 8000.00, 12000.00, 25000.00, 30000.}};

		private static KenoBoard7 gameGrid;
		private static KenoPlayer7 user;
		
		public KenoGame7(){
			gameGrid = new KenoBoard7(); 
		}
		public void initKenoPlayer(int num1, int num2){
			user = new KenoPlayer7(num1,num2);
		}
		public int setKenoPlayerSpot(int num){
			Spot7 temp;
			boolean setSpot;
			
			if(user == null){
				return -2;
			}
			if((num < 1) || (num>=MAX_KENO_NUMBER+1)){
			return (-1);
			}
			temp = gameGrid.getkenoSpots(num); 
			setSpot = user.setSpot(temp);
			if(setSpot == false){
				return 1;
			}
			return 0;
		}
		public int lengthKenoPlayerMarketSpot(){
			int length;
			length = user.getLengthMarkedSpots();
			return length;
		}
		public int getdrawnSpots(int index){
			int num;
			num = gameGrid.getdrawnSpots(index);
			return num;
		}
		public void drawNumbers(){
			gameGrid.resetSpots();
			gameGrid.chooseKenoSpots();
		}
		public void getResults(){
			user.calcNumMatches();
			user.calcWinnings();
		}
		public String displayResults(){
			return (user.toString());
		}
		
	}

	/*
	-------------------------------------------------------------
	KenoGame (UML) implements NumberGameInteface
	-------------------------------------------------------------
	-MAX_KENO_NUMBER:int (final)
	-DRAWN_NUMBERS:int (final)
	-payoffAmounts:double [][]
	-gameGrid:KenoBoard
	-user:KenoPlayer
	-------------------------------------------------------------
	+KenoGame()
	<<constructor>>
	+initKenoPlayer(num1:int,num2:int)
	+setKenoPlayerSpot(num:int):int
	+lengthKenoPlayerMarketSpot():int
	+drawNumbers()    <<abstract>>
	+getResults()     <<abstract>>
	+displayResults() <<abstract>>
	-------------------------------------------------------------
	 */

