 /*
 Program Name: Programming HW #7: KenoGame
 Programmer Name: Evan Chen
 Date: March 25, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 7 Spot: This object represents the spots in the Keno Game. The object contains
 an int and boolean variable. The int variable will hold the number in the Keno game
 (1-80) while the boolean variable will be true if the spot is chosen by the user.
 */

package homework;

public class Spot7 {

	private int value = 0;
	private boolean chosen = false;
	
	public Spot7(int inValue){
		if(inValue >0){
			this.value = inValue;
		}
	}
	public Spot7(){
		this.value = 0;
		this.chosen = false;
	}
	public int getValue(){
		return this.value;
	}
	public boolean getChosen(){
		return this.chosen;
	}
	public void setChosen(boolean inChosen){
		this.chosen = inChosen;
	}
}

/*
-------------------------------------------------------------
Spot (UML)
-------------------------------------------------------------
-value:int
-chosen:boolean
-------------------------------------------------------------
+Spot()
<<constructor>>
+getValue():int
+getChosen:boolean
+setChosen(inChosen:boolean)
-------------------------------------------------------------
 */



