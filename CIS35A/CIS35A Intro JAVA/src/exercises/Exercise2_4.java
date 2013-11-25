package exercises;

public class Exercise2_4 {

	public static void main(String[] args) {
	int num = 2;
	double squares, cubes;
	
	for(int i=1;i<20;i++){
	squares = num*num;
	cubes = num*num*num;
	System.out.printf("%4d\t%4.2f\t%4.2f\n",num,squares,cubes);
	num++;
	}
	}
}
