//Evan Chen
//CIS35A
//Exercise3.1

package exercises;

public class MyMath {
	public static double round100th(double num1) {
		
	num1 = num1*100;
	num1 = Math.round(num1);
	num1 = num1/100;
	return(num1);
	}
}


