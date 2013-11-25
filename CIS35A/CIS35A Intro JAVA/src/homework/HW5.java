 /*
 Program Name: Programming HW #5: Pets
 Programmer Name: Evan Chen
 Date: March 10, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 5 Driver: This is the main part of the program. This part of the program first 
 declares an array of Pet objects. The program will then prompt the user for a number of
 pets and then ask for their information (type,name,birthYear,etc). It will then assign each
 of the sets of information into each element of the array of Pet objects and then sort it
 by name. The program will also find out how many large dogs there are. Lastly, the program
 will then display the following information according to the pet type:
 Cat: name, birthYear, Indoor or Outdoor, Age in Human Years, and Life expectancy
 Dog: name, birthYear, # of tricks, size, Age in Human Years, and Life expectancy
 It will then display if there were either no dogs or how many large dogs
 */

package homework;

import java.util.*;

public class HW5 {
	static Scanner scanner = new Scanner(System.in);
	public static void main(String[] args) {
		Pet [] petObject;
		int largeDogs;
		
		petObject = createPetObjects();
		sortPetArray(petObject);
		printResults(petObject);
		largeDogs = largeDogs(petObject);
		if(largeDogs == -1){
			System.out.print("\nNo Dogs in the list");
		}
		if(largeDogs!= -1){
		System.out.print("\nThere is/are "+largeDogs+" large dog(s)");
		}
	}
	
	public static Pet[] createPetObjects(){
		int arraySize;
		Pet [] petObject;
		int i;
		String bufferTemp;
		
		System.out.print("Enter number of pets: ");
		arraySize = scanner.nextInt();
		bufferTemp = scanner.nextLine();
		while((arraySize<1)||(arraySize>20)){
			System.out.print("Please enter number of pets between 1 and 20: ");
			arraySize = scanner.nextInt();
			bufferTemp = scanner.nextLine();
		}
		petObject = new Pet[arraySize];
		for(i=0;i<arraySize;i++){
			petObject[i] = expectedType();
		}
		return petObject;
	}
	public static void sortPetArray(Pet[] inputArray){
		int i,j;
		String name1;
		String name2;
		boolean flag = true;
		Pet temp;
		
		while(flag){
			flag = false;
			for(i=0;i<inputArray.length-1;i++){
				name1 = inputArray[i].getName();
				name2 = inputArray[i+1].getName();
				if((name1.compareToIgnoreCase(name2))>0){
					temp = inputArray[i];
					inputArray[i] = inputArray[i+1];
					inputArray[i+1]=temp;
					flag = true;
				}
			}
		}
	}
	public static void printResults(Pet[] inputArray){
		int convYears,lifeExp;
		
		System.out.print("\n");
		for(Pet element:inputArray){
			convYears = element.convertYears();
			lifeExp = element.lifeExpectancy();
			System.out.printf(element.toString()+" Human Years = "+convYears+","+" Life Expectancy = "+lifeExp+"\n");
		}
	}
	//A
	public static Pet expectedType(){
		String catDog,str,name;
		int birthYear,numTricks;
		char size;
		boolean inOut;
		Pet userPet = null;

		System.out.print("Enter pet info: ");
		str = scanner.nextLine();
		String [] parts = str.split(",");
		catDog = parts[0];
		if((catDog.equalsIgnoreCase("Cat"))==true){
			name = parts[1];
			birthYear = Integer.parseInt(parts[2]);
			inOut = Boolean.valueOf(parts[3]);
			userPet = new Cat(name,birthYear,inOut);
		}
		if((catDog.equalsIgnoreCase("Dog"))==true){
			name = parts[1];
			birthYear = Integer.parseInt(parts[2]);
			numTricks = Integer.parseInt(parts[3]);
			size = parts[4].charAt(0);
			userPet = new Dog(name,birthYear,numTricks,size);
		}
		return userPet;
	}
	//B
	public static int largeDogs(Pet[] inputArray){
		int i;
		int largeDogs = 0;
		int dogs = 0;
		char size;
		
		for(i=0;i<inputArray.length;i++){
			if(((inputArray[i]) instanceof Dog)){
				dogs++;
				size = ((Dog)(inputArray[i])).getSize();
				if(size == 'L'){
					largeDogs++;
				}
			}
		}
		if(dogs==0){
			return -1;
		}
		return largeDogs;
	}
	
}

/*OUTPUT
Enter number of pets: 8
Enter pet info: dog,Titan Great Dane,2005,5,L
Enter pet info: Dog,Tuffy Terrier,2006,4,s
Enter pet info: Cat,PURR Kitten,2001,true
Enter pet info: DOG,Bernie St. Bernard,2006,5,L
Enter pet info: Cat,Zip Cat,2005,false
Enter pet info: Cat,Amber Tabby,2000,true
Enter pet info: dog,Fetch Retriever,2007,10,L
Enter pet info: Cat,Debo Cat,2004,false

Cat Pet: name=Amber Tabby, birth year=2000, Indoor, Human Years = 68, Life Expectancy = 16
Dog Pet: name=Bernie St. Bernard, birth year=2006, # tricks= 5, size = L Human Years = 51, Life Expectancy = 10
Cat Pet: name=Debo Cat, birth year=2004, Not Indoor, Human Years = 52, Life Expectancy = 4
Dog Pet: name=Fetch Retriever, birth year=2007, # tricks= 10, size = L Human Years = 44, Life Expectancy = 10
Cat Pet: name=PURR Kitten, birth year=2001, Indoor, Human Years = 64, Life Expectancy = 16
Dog Pet: name=Titan Great Dane, birth year=2005, # tricks= 5, size = L Human Years = 58, Life Expectancy = 10
Dog Pet: name=Tuffy Terrier, birth year=2006, # tricks= 4, size = s Human Years = 51, Life Expectancy = 16
Cat Pet: name=Zip Cat, birth year=2005, Not Indoor, Human Years = 48, Life Expectancy = 4

There is/are 3 large dog(s)
*/
