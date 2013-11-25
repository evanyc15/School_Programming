package exercises;

public class Exercise2_3 {
	public static void main(String[] args) {
	int inum1=10, inum2;
		
	inum2 = inum1;
	for(int i=0; i < inum2; ++i, --inum2){
	System.out.println("i = " + i);
	} // end for
	System.out.println("The last value of inum2 = "+inum2);
	}
}
