 /*
 Program Name: Programming HW #5: Pets
 Programmer Name: Evan Chen
 Date: March 10, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 5 Dog subclass: The UML diagram is in comments at the bottom of this class.
 The dog subclass will be used if the user enters a dog and its information. This subclass
 will get the # of tricks and size of the dog. It will then implement the convertYears abstract
 method to find the current dog's age in Human Years and also the lifeExpectancy abstract method
 to find the life expectancy depending on the size of the dog. Lastly, it will also return
 the # of tricks and size for printing.
 */

package homework;

public class Dog extends Pet{
	private int numTricks = 0;
	private char size = 'S';
	
	public Dog(String name,int birthYear,int tricks,char typeSize){
		super(name,birthYear);
		this.numTricks = tricks;
		this.size = typeSize;
	}
	public Dog(int birthYear,int tricks, char typeSize){
		super(birthYear);
		this.numTricks = tricks;
		this.size = typeSize;
	}
	public int getnumTricks(){
		return numTricks;
	}
	public char getSize(){
		return size;
	}
	public void setnumTricks(int num){
		this.numTricks = num;
	}
	public void setSize(char temp){
		this.size = temp;
	}
	//implements
	public int convertYears(){
		int currentAge;
		int temp;
		int i;
		
		currentAge = super.calcAge();
		if(currentAge==1){
			currentAge = 9;
		}
		if(currentAge>1){
			temp = 9;
			for(i=1;i<currentAge;i++){
				temp = temp + 7;
			}
			currentAge = temp;
		}
		return currentAge;
	}
	//implements
	public int lifeExpectancy(){
		if(size=='S'||size=='s'){
			return 16;
		}
		if(size=='M'||size=='m'){
			return 12;
		}
		return 10;
	}
	
	public String toString(){
		String superClassString;
		
		superClassString = super.toString();
		return(superClassString+","+" # tricks= "+this.numTricks+","+" size = "+this.size);
	}
}

/*
-------------------------------------------------------------
Dog<<subclass>>
-------------------------------------------------------------
-numTricks:int
-size:char
-------------------------------------------------------------
+Dog(name:String,birthYear:int,tricks:int,typeSize:char)
+Dog(birthYear:int,tricks:int,typeSize:char)
<<constructor>>
+getNumTricks():int
+getSize():char
+setnumTricks(num:int)
+setSize(temp:char)
+convertYears():int <<implements abstract>>
+lifeExpectancy():int <<implements abstract>>
+toString():String
-------------------------------------------------------------
 */
