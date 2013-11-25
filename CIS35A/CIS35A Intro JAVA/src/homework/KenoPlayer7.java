 /*
 Program Name: Programming HW #7: KenoGame
 Programmer Name: Evan Chen
 Date: March 21, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 7 KenoPlayer: This object holds the player's data. It contains the
 Spot array markedSpots, and ints for the currentIndex, number of matched keno
 numbers, player's bet, and the player's winnings. The object will calculate
 if the player's chosen number matches one of the 20 random numbers. It will also
 call different methods to the amount of winning's based on the matches and return
 the information to the user.
 */


package homework;


public class KenoPlayer7 {
	private Spot7 [] markedSpots;
	private int currentIndex = 0;
	private int numMatches = 0;
	private int playerBet = 1;
	private double playerWinnings = 0;
	
	public KenoPlayer7(int numSpots, int bet){
		if((numSpots > 0) && (numSpots <= KenoGame7.payoffAmounts.length)){
			markedSpots = new Spot7[numSpots];
		}
		if((numSpots <= 0) || (numSpots > KenoGame7.payoffAmounts.length)){
			markedSpots = new Spot7[1];
		}
		if(bet > 0 ){
			this.playerBet = bet;
		}
	}

	public int getLengthMarkedSpots(){
		return markedSpots.length;
	}
	public int getPlayerBet(){
		return this.playerBet;
	}
	public int getNumMatches(){
		return numMatches;
	}
	public double getPlayerWinnings(){
		return this.playerWinnings;
	}
	public boolean setSpot(Spot7 input){
		boolean checkParam = true;
		int i;
		
		if((input!=null) && (currentIndex <= markedSpots.length)){
			for(i=0;i<markedSpots.length;i++){
				if(markedSpots[i]==input){
					checkParam = false;
				}
			}	
			if(checkParam==true){
				markedSpots[currentIndex] = input;   
				currentIndex++;
				return true;
			}			
		}	
		return false;
	}
	public void calcNumMatches(){
		int i;
		boolean numChosen;
		
		for(i=0;i<markedSpots.length;i++){
		numChosen = markedSpots[i].getChosen();
			if(numChosen == true){
				numMatches++;
			}
		}
	}
	public void calcWinnings(){
		int marked = markedSpots.length;	
		double payoff = KenoGame7.payoffAmounts[marked][numMatches];
		this.playerWinnings = ((double)playerBet) * payoff;	
	}
	public String toString(){
		StringBuilder PlayerData = new StringBuilder("Player's spots: ");
		int i;
		int markedValues;
		
		if(markedSpots!=null){
		for(i=0;i<markedSpots.length;i++){
			markedValues = markedSpots[i].getValue();
			PlayerData.append(Integer.toString(markedValues)+" ");
			}
		}
		PlayerData.append("You Matched "+numMatches+" number(s)"+" You won $"+playerWinnings+"\n");
		return PlayerData.toString();
	}
}
/*
-------------------------------------------------------------
KenoPlayer (UML)
-------------------------------------------------------------
-markedSpots:Spot[]
-currentIndex:int
-numMatches:int
-playerBet:int
-playerWinnings:double
-------------------------------------------------------------
+KenoSpots(numSpots:int,bet:int)
<<constructor>>
+getLengthMarkedSpots():int
+getPlayerBet():int
+getNumMatches():int
+getPlayerWinnings():double
+setSpot(input:Spot):boolean
+calcNumMatches()
+calcWinnings()
+toString():String
-------------------------------------------------------------
 */



