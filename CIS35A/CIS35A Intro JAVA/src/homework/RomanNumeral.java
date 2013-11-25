 /*
 Program Name: Programming HW #4: RomanNumerals 
 Programmer Name: Evan Chen
 Date: March 2nd, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 4 Object: The UML diagram is in comments at the bottom of this class. This section of the program will first 
 create the array of objects, instance variable string, and instance variable int. The array of objects will be initialized
 to various Roman Numerals, the instance variable string will be initialized to "" and the instance variable int will 
 be initialized to 0. The main purpose of this class/object will to return the values (int) of two of the user's inputted
 Roman Numerals. It will then add them up and return the value of the sum. 
 */

package homework;

public class RomanNumeral {
	static RomanNumeral[] romanArray = {
			new RomanNumeral("M"),
			new RomanNumeral("CM"),
			new RomanNumeral("D"),
			new RomanNumeral("CD"),
			new RomanNumeral("C"),
			new RomanNumeral("XC"),
			new RomanNumeral("L"),
			new RomanNumeral("XL"),
			new RomanNumeral("X"),
			new RomanNumeral("IX"),
			new RomanNumeral("IV"),
			new RomanNumeral("I")
	};
	private String romNumStr = "";
	private int value = 0;
	
	RomanNumeral(String str){
		setromNumStr(str); //A
	}
	RomanNumeral(int num){
		setValue(num);
	}
	RomanNumeral(){
		if(romNumStr==null)
			romNumStr = "";
		value = 0;
	}
	//A
	public void setromNumStr(String input){
		if(input != null){
		romNumStr = input;
		romNumStr = romNumStr.trim();
		romNumStr = romNumStr.toUpperCase();
		calcIntValue(); //C
		}
	} 
	//B
	public void setValue(int input){
		if(input>0){
			value = input;
			assignRomanNumeral(); //F
		}
	}
	//C
	private int calcIntValue(){ 
		int i;
		value = 0;
		char currentChar;
		int [] digitValues = new int[romNumStr.length()];
		for(i=0;i<romNumStr.length();i++){
			currentChar = romNumStr.charAt(i);
			switch(currentChar){
			case 'M': digitValues[i] = 1000;
					  break;
			case 'D': digitValues[i] = 500;
					  break;
			case 'C': digitValues[i] = 100;
					  break;	
			case 'L': digitValues[i] = 50;
				      break;
			case 'X': digitValues[i] = 10;
					  break;
			case 'V': digitValues[i] = 5;
					  break;
			case 'I': digitValues[i] = 1;
					  break;
			default: digitValues[i] = 0;
					  break;
			}
		}
		for(i=0;i<digitValues.length;i++){
			if(digitValues[i]==0){
				romNumStr = "";
				value = 0;
				return value;
			}
		}
		for(i=0;i<((digitValues.length)-1);i++){
			if(digitValues[i]>=digitValues[i+1]){
				value = value + digitValues[i];
			}
			if(digitValues[i]<digitValues[i+1]){
				value = value - digitValues[i];
			}
		}
		value = value + digitValues[(digitValues.length)-1];
		return value;
	}
	//D
	public String getromNumStr(){
		return romNumStr;
	}
	//E
	public int getValue(){
		return value;
	}
	//F
	private void assignRomanNumeral(){
		StringBuilder sb1 = new StringBuilder();
		int val = this.value; 
		int index;
		int tempVal;
		String tempStr;
		
		for(index=0;index<romanArray.length;index++){
		tempVal = romanArray[index].getValue();
		tempStr = romanArray[index].getromNumStr();
		while((val-tempVal)>=0){
		sb1.append(tempStr);
		val = val - tempVal;
		}
		}
		this.romNumStr = sb1.toString();
	}
	//G
	public RomanNumeral addRomanNumeral(RomanNumeral temp){
		int num = 0;
		
		if(temp!=null){
			num = temp.value + this.value;
		}
		return new RomanNumeral(num);
	}
	//H
	public String toString(){
		StringBuilder sb = new StringBuilder("RomanNumeral: ");
		
		sb.append(romNumStr+" = "+value);
		return sb.toString();
	}
	
}

/*
-------------------------------------------------------------
RomanNumeral
-------------------------------------------------------------
-romanArray:array of objects
-romNumStr:String
-value:int
-------------------------------------------------------------
+RomanNumeral(str:String)
+RomanNumeral(num:int)
+RomanNumeral()
<<constructor>>
+setromNumStr(input:String)
+setValue(input int)
+calcIntValue():int
+getromNumStr():String
+getValue():int
+assignRomanNumeral()
+addRomanNumeral(temp:RomanNumeral):RomanNumeral
+toString():String
-------------------------------------------------------------
 */

