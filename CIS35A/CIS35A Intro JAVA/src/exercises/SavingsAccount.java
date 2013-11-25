package exercises;

public class SavingsAccount {

private static double annualIntRate; // default 0.
private double balance; // default 0.

public SavingsAccount(double bal){

if( bal > 0 )

balance = bal;
// else leave as 0

} // end constructor

public SavingsAccount(){ }//default const.

public double getBalance(){ return balance; }

public boolean transaction(double amount){

if( balance + amount >= 0 ){

balance += amount;
return true;

}// end if
return false;

} // end transaction

public double addMonthlyInterest(){

double interest;

interest = balance*annualIntRate/12.;
// should be rounded to nearest 100th
balance += interest;
return interest;

} // end addMonthlyInterest

public static boolean modifyIntRate(double newRate){

if( newRate >= 0 ){

annualIntRate= newRate;
return true;

}// end if

return false;

} // end modifyIntRate

public static double getAnnualIntRate(){

return annualIntRate;

} // end getAnnualIntRate

} // end SavingsAccount


