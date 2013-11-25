//Evan Chen
//Exercise11_2;

package exercises;

import java.io.*;

public class Exercise11_2 {
	public static void main(String[] args) throws UnsupportedEncodingException {
		int num1,num2,num3;
		String str1,str2,str3;
		int average;
		int largest;
		
		FileInputStream inFile = null;
		try{
			inFile = new FileInputStream("input.txt");
		}catch(FileNotFoundException e){
			System.err.println(e);
			return;
		}//end catch
		InputStreamReader inStrRdr = 
			     new InputStreamReader(inFile, "8859_1");
		BufferedReader reader = new BufferedReader(inStrRdr);
		try{
			str1 = reader.readLine();
			str2 = reader.readLine();
			str3 = reader.readLine();
			
			num1 = Integer.parseInt(str1);
			num2 = Integer.parseInt(str2);
			num3 = Integer.parseInt(str3);
			
			average = averageNum(num1,num2,num3);
			largest = largestNum(num1,num2,num3);
			
			System.out.println("The average is " +average);
			System.out.println("The largest number is " +largest);
		}
		catch (IOException ie){
			System.err.println("Error in input:" +ie);
		}
		catch (NumberFormatException ne){
			System.err.println("Error in input: "+ne);
		}
	}
	
	public static int averageNum(int num1,int num2,int num3){
		int average;
		
		average = (num1+num2+num3)/3;
		average = Math.round(average);
		
		return average;
	}
	
	public static int largestNum(int num1,int num2,int num3){
		int temp;
		
		temp = num1;
		if(temp<=num2)
			temp = num2;
		if(temp<=num3)
			temp = num3;
		
		return temp;
	}
}

/*Output
The average is 59
The largest number is 79
*/