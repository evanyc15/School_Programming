//Evan Chen
//Exercise 11.1

package exercises;

import java.io.*;
public class Exercise11_1 {
	public static void main(String[] args) {
		
		FileOutputStream outFile = null;
		try{
			outFile = new FileOutputStream("info.txt");
		}catch(FileNotFoundException e){
			System.err.println(e);
			return;
		}//end catch
		
		PrintWriter prtWriter = new PrintWriter(outFile,true);

		prtWriter.println("1. A Java method is called what in C/C++?\n");
		prtWriter.println("Answer #1: function\n");
		prtWriter.println("2. Java is compiled into___\n");
		prtWriter.println("Answer #2: .class file\n");
		prtWriter.println("The Java interpreter is called the____\n");
		prtWriter.println("Answer #3: Java Virtual Machine (JVM)\n");
		prtWriter.close();
	}

}


