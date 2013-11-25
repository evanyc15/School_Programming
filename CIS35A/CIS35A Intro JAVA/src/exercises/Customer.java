//Evan Chen
//Exercise 5.3

package exercises;
	
public class Customer implements Comparable{
	private String accountName;
	private long accountNum;
	private double Savings;
	
	public Customer(String name, long acNum, double var3){
		SavingsAccount Savings = new SavingsAccount(var3);
		accountName = name;
		accountNum = acNum;	
	}
	
	public String getName(){
	return accountName;
	}
	
	public long getAccount(){
	return accountNum;
	}
	
	public boolean setName(String name){
	this.accountName = name;
	return true;
	}
	
	public double getAccountBalance(){
		return Savings;
	}

	public int compareTo(Object temp) {
		int num;
		num = accountName.compareToIgnoreCase(this.accountName);
		if(num!=0){
			return num;
		}
		if(accountNum!=this.accountNum){
			if(this.accountNum<accountNum){
				return -1;
			}
			return 1;
		}
		if(Savings==this.Savings){
			return 0;
		}
		if(this.Savings<Savings){
			return -1;
		}
		return 1;
	}
	
	
}

/*UML

---------------------------------------
Customer
-accountName:String
-accountNum:long
-Savings:double
----------------------------------------
+Customer(String,long,double)
+getName():String
+getAccount():long
+setName(String):Boolean
+getAccountBalance():ObjectReference
----------------------------------------

*/
