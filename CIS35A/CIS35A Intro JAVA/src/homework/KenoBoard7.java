 /*
 Program Name: Programming HW #7: KenoGame
 Programmer Name: Evan Chen
 Date: March 25, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 7 KenoBoard: This object holds the Keno Board. The object contains two Spot
 array objects kenoSpots and drawnSpots. KenoSpots will hold the 80 Keno numbers and
 true or false depending on if they have been drawn or not. The drawn numbers
 holds the the random 20 Keno numbers that are drawn.
 */

package homework;


public class KenoBoard7 {

	private static Spot7 [] kenoSpots;
	private static Spot7 [] drawnSpots;
	
	public KenoBoard7(){
		int i;
		
		kenoSpots = new Spot7[KenoGame.MAX_KENO_NUMBER+1];
		drawnSpots = new Spot7[KenoGame.DRAWN_NUMBERS];
		for(i=0;i<kenoSpots.length;i++){
			kenoSpots[i] = new Spot7(i);
		}
	}
	public void resetSpots(){
		int i;
		
		for(i=0;i<KenoGame.MAX_KENO_NUMBER+1;i++){
			kenoSpots[i].setChosen(false);
		}
		for(i=0;i<KenoGame.DRAWN_NUMBERS;i++){
			drawnSpots[i] = null;
		}
	}
	public Spot7 getkenoSpots(int index){
		if(index<=KenoGame.MAX_KENO_NUMBER && index>0){
			return kenoSpots[index];
		}
		return null;
	}
	public void chooseKenoSpots(){
		int index;
		int i = 0;
		boolean choseSpot;
		
		while(i<drawnSpots.length){
			index = (int)(Math.random() * (KenoGame.MAX_KENO_NUMBER-1+1) ) + 1;
			choseSpot = kenoSpots[index].getChosen();
			if(choseSpot!=true){
			drawnSpots[i] = kenoSpots[index];
			kenoSpots[index].setChosen(true);
			i++;
			}
		}
	}
	public int getdrawnSpots(int index){
		return drawnSpots[index].getValue();
	}
	
	public String toString(){
		StringBuilder printString = new StringBuilder("\nKeno Board spots: ");
		int i;
		int num;
		
		for(i=0;i<drawnSpots.length;i++){
			num = drawnSpots[i].getValue();
			printString.append(Integer.toString(num)+" ");
		}
		printString.append("\n");
		return printString.toString();
	}
	
}
/*
-------------------------------------------------------------
KenoBoard (UML)
-------------------------------------------------------------
-kenoSpots:Spot[]
-drawnSpots:Spot[]
-------------------------------------------------------------
+KenoBoard()
<<constructor>>
+resetSpots()
+getKenoSpots(index:int):Spot
+chooseKenoSpots()
+toString():String
-------------------------------------------------------------
 */
