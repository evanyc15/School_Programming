//Evan Chen
//CIS35A
//Exercise3.1

package exercises;

public class TryMyMath {
	public static void main(String[] args) {
		
		printRound(Math.E);
	}
	
	public static void printRound(double num1) {
	
	System.out.println(MyMath.round100th(num1));
	System.out.println(MyMath.round100th(num1*num1));
	System.out.println(MyMath.round100th(num1*num1*num1));
	}
}

/*OUTPUT

2.72
7.39
20.09


*/