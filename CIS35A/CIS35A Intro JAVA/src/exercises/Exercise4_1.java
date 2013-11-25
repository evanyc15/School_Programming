//Evan Chen

package exercises;

public class Exercise4_1 {

	public static void main(String[] args) {
		float array1[];

		array1 = createArray(8,(float) 10.0);
		displayArray(array1);
	}
	
	public static float[] createArray(int numElems, float num1){
		float [] newArray; 
		newArray = new float[numElems];
		
		for(int i=0;i<numElems;i++){
			newArray[i] = num1*i;
		}
		return newArray;
	}
	
	public static void displayArray(float array1[]){
		int i, numElems;
		numElems=array1.length;
		
		for(i = numElems-1;i>=0;--i){
			System.out.print("    "+array1[i]);
		}
	}
}


/*OUTPUT

70.0    60.0    50.0    40.0    30.0    20.0    10.0    0.0

*/