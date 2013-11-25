package exercises;

public class test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		int num;
		String str = "a+b/(c-d)";
		String [] strArray = str.split("[+-/()]");
		num = strArray.length;
		System.out.print(num);
	}

}
