 /*
 Program Name: Programming HW #4: RomanNumerals 
 Programmer Name: Evan Chen
 Date: March 2nd, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 4 MAIN: This is the main section of the program. It will first start with declaring three RomanNumeral objects
 which be created in the constructor of the RomanNumeral object. It will then ask the user to input two Roman Numeral strings.
 With the two strings, it will pass them to the RomanNumeral object so that it can receive the int value of the RomanNumerals
 and display it to the user. It will also use the third RomanNumeral object and display the sum of the two inputted Roman Numerals.
 */

package homework;

import java.util.Scanner;

public class HW4 {
	static Scanner scanner = new Scanner(System.in);
	public static void main(String[] args) {
		RomanNumeral roman1 = new RomanNumeral(null);
		RomanNumeral roman2 = new RomanNumeral(null);
		RomanNumeral roman3 = new RomanNumeral(null);
		
		roman1 = getRomanNumeral();
		roman2 = getRomanNumeral();
		roman3 = roman1.addRomanNumeral(roman2);
		printRomanValues(roman1,roman2,roman3);
		changeRomanNumeral(roman1,2);
		changeRomanNumeral(roman2,10);
		roman3 = roman1.addRomanNumeral(roman2);
		printRomanValues(roman1,roman2,roman3);
	}
	public static void printRomanValues(RomanNumeral roman1, RomanNumeral roman2,
			RomanNumeral roman3){
		
		System.out.print("\nThe sum of:\n");
		System.out.print(roman1.toString()+" and \n");
		System.out.print(roman2.toString()+" equals\n");
		System.out.print(roman3.toString());
		System.out.print("\n");
	}
	//X.
	public static RomanNumeral getRomanNumeral(){
		String str;
		
		System.out.print("Please enter a roman numeral: ");
		str = scanner.nextLine();
		if(str == ""){
			return new RomanNumeral();
		}
		return new RomanNumeral(str);
	}
	//Y.
	public static void changeRomanNumeral(RomanNumeral num,int val){
		int temp;
		
		if(num!=null){
			temp = num.getValue();
			num.setValue(temp*val);
		}
	}
}

/*OUTPUT
Please enter a roman numeral:   MCMXLIX
Please enter a roman numeral: vi

The sum of:
RomanNumeral: MCMXLIX = 1949 and 
RomanNumeral: VI = 6 equals
RomanNumeral: MCMLIVI = 1955

The sum of:
RomanNumeral: MMMDCCCXCIVIV = 3898 and 
RomanNumeral: LX = 60 equals
RomanNumeral: MMMCMLIVIV = 3958


Please enter a roman numeral:       cdxxxiv
Please enter a roman numeral: I

The sum of:
RomanNumeral: CDXXXIV = 434 and 
RomanNumeral: I = 1 equals
RomanNumeral: CDXXXIVI = 435

The sum of:
RomanNumeral: DCCCLXIVIV = 868 and 
RomanNumeral: X = 10 equals
RomanNumeral: DCCCLXXIVIV = 878


Please enter a roman numeral:   LI8ID
Please enter a roman numeral: $C

The sum of:
RomanNumeral:  = 0 and 
RomanNumeral:  = 0 equals
RomanNumeral:  = 0

The sum of:
RomanNumeral:  = 0 and 
RomanNumeral:  = 0 equals
RomanNumeral:  = 0


Please enter a roman numeral: mix
Please enter a roman numeral: MILK

The sum of:
RomanNumeral: MIX = 1009 and 
RomanNumeral:  = 0 equals
RomanNumeral: MIX = 1009

The sum of:
RomanNumeral: MMXIVIV = 2018 and 
RomanNumeral:  = 0 equals
RomanNumeral: MMXIVIV = 2018


Please enter a roman numeral:        XLII
Please enter a roman numeral: 
Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: -1
	at homework.RomanNumeral.calcIntValue(RomanNumeral.java:103)
	at homework.RomanNumeral.setromNumStr(RomanNumeral.java:51)
	at homework.RomanNumeral.<init>(RomanNumeral.java:35)
	at homework.HW4.getRomanNumeral(HW4.java:51)
	at homework.HW4.main(HW4.java:25)
*/
