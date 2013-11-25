//Evan Chen
//CIS35A
//Exercise2.1


package exercises;

public class Exercise2_1 {
	public static void main(String[] args) {
	short num1,num2,mask;
	
	num1 = 0x0A5C; /*hex. for 0000 1010 0101 1100*/
	mask = 0x000F; /*hex for 0000 0000 0000 1111*/
	num2 = (short) (num1 >> 8);
	num2 = (short) (num2 & mask);
	}

}
