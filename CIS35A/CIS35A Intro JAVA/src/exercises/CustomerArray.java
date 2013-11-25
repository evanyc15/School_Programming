//Evan Chen
//Exercise 5.4

package exercises;
import java.util.Scanner;

public class CustomerArray {
	static Scanner scanner = new Scanner(System.in);
	public static void main(String[] args) {
		CustomerArray [] Customers;
		Customers = customerInfo();

	}
	
	public CustomerArray(String name, long accountNum, double savingBalance){
		CustomerArray Customers = new CustomerArray(name,accountNum,savingBalance);
	}

	static CustomerArray[] customerInfo()
	{	
		CustomerArray[] temp = null;
		int customerNum;
		int i;
		String name;
		long accountNum;
		double savingBalance;
		
		System.out.print("Please enter how many customers: ");
		customerNum = scanner.nextInt();
		for(i=0;i<customerNum;i++){
			System.out.print("Please enter the name: ");
			name = scanner.nextLine();
			System.out.print("Please enter the account number: ");
			accountNum = scanner.nextLong();
			System.out.print("Please enter the saving's balance: ");
			savingBalance = scanner.nextDouble();
			temp[i] = new CustomerArray(name,accountNum,savingBalance);
		}
		
		return temp;
	}

}


