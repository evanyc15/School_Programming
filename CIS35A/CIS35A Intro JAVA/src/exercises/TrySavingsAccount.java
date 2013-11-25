package exercises;

public class TrySavingsAccount {

public static void main( String [] args ){

SavingsAccount saver1, saver2; // no instances yet!

saver1=new SavingsAccount(1000.);// instantiate for saver1
saver2=new SavingsAccount(2000.);// instantiate for saver2
SavingsAccount.modifyIntRate(0.01);//NOT 1
// NOT saver1.modifyIntRate(0.01);
// NOT twice saver2.modifyIntRate(0.01);

double interest1= saver1.addMonthlyInterest();
// optional to save the interest
double interest2 = saver2.addMonthlyInterest();

System.out.printf("The new balance for saver1 after adding %.2f in interest is $%.2f\n", interest1, saver1.getBalance() );
System.out.printf("The new balance for saver2 after adding %.2f in interest is $%.2f\n", interest2, saver2.getBalance() );

if( saver1.transaction(500.0) )

System.out.printf("After making a deposit, saver1 has %.2f\n", saver1.getBalance() );

else

System.out.println("Error in SavingsAccount code-- unable to make deposit");

if( saver2.transaction(-200.0) )

System.out.printf("After withdrawing money, saver2 has %.2f\n", saver2.getBalance() );

else

System.out.println("Error in SavingsAccount code-- unable to make valid withdrawal");

if( saver1.transaction(-2000.0) )

System.out.printf("After attempting to withdraw too much money, saver1 has %.2f\n", saver1.getBalance() );

else

System.out.println("Error in SavingsAccount code-- allowed to make invalid withdrawal");

} // end main

} // end TrySavingsAccount
