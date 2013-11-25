 /*
 Program Name: Programming HW #5: Pets
 Programmer Name: Evan Chen
 Date: March 10, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 5 Cat subclass : The UML diagram is in comments at the bottom of this class.
 The cat subclass will be used if the user enters a cat and its information. This subclass
 will find out if the cat is indoor or not indoor. It will then implement the convertYears 
 abstract method to find the current cat's age in Human Years and also the lifeExpectancy 
 abstract method to find the life expectancy depending if the cat is indoors or not. Lastly, 
 it will also return the indoor or not indoor for printing.
 */

package homework;

public class Cat extends Pet{
	private boolean indoor = true;
	
	public Cat(String name,int birthYear,boolean inOut){
		super(name,birthYear);
		this.indoor = inOut;
	}
	
	public Cat(int birthYear,boolean inOut){
		super(birthYear);
		this.indoor = inOut;
	}
	public boolean getIndoor(){
		return indoor;
	}
	public void setIndoor(boolean temp){
		this.indoor = temp;
	}
	//implements
	public int convertYears(){
		int currentAge;
		int temp;
		int i;
		
		currentAge = super.calcAge();
		if(currentAge==1){
			currentAge = 15;
		}
		if(currentAge==2){
			currentAge = 24;
		}
		if(currentAge>2){
			temp = 24;
			for(i=2;i<currentAge;i++){
				temp = temp + 4;
			}
			currentAge = temp;
		}
		return currentAge;
	}
	//implements
	public int lifeExpectancy(){
		if(indoor==true){
			return 16;
		}
		return 4;
	}
	
	public String toString(){
		String superClassString;
		String indoorOut = null;
		if(this.indoor==true){
			indoorOut = "Indoor";
		}
		if(this.indoor==false){
		indoorOut = "Not Indoor";
		}
		
		superClassString = super.toString();
		return(superClassString+", "+indoorOut+",");
	}
}

/*
-------------------------------------------------------------
Cat<<subclass>>
-------------------------------------------------------------
-indoor:boolean
-------------------------------------------------------------
+Cat(name:String,birthYear:int,inOut:boolean)
+Cat(birthYear:int,inOut:boolean)
<<constructor>>
+getIndoor():boolean
+setIndoor(temp:boolean)
+convertYears():int <<implements abstract>>
+lifeExpectancy():int <<implements abstract>>
+toString():String
-------------------------------------------------------------
 */
