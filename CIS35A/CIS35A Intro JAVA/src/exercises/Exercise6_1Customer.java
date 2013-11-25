//Evan Chen
//Exercise 6.1

package exercises;

public class Exercise6_1Customer {
	StringBuilder lastName = new StringBuilder();
	StringBuilder firstName = new StringBuilder();
    private long acctNum; // default 0
    private SavingsAccount savings;//null

    public Exercise6_1Customer(String nm,
                            long ac,
                            SavingsAccount sav){
          setName(nm); // or leave with "No Name"
          if( ac > 0 )
                acctNum = ac;
          if( sav != null )
                savings = sav;
          else
                savings = new SavingsAccount();
    } // end constructor #1

    public Exercise6_1Customer(String nm,
                            long ac,
                            double bal){
          this(nm, ac, new SavingsAccount(bal));
    } // end constructor#2

    public String getName(){
    	String first;
    	String last;
    	String name;
    	
    	first = firstName.toString();
    	last = lastName.toString();
    	name = (last+", "+first);
    	return name;
    }

    /*public long getAcct(){ return acct; }

//NOT SAFE, BUT EASIER FOR NOW
//If this wasn't included, would need add methods
// to this class to operate on the SavingsAccount
    public SavingsAccount getSavings(){
          return savings; 
    }*/

    public boolean setName(String name){
    	String[]tokens = name.split(",");
    
    	if(name!= null && name.length() > 0 ){
            lastName.append(tokens[0]);
            firstName.append(tokens[1]);
            return true;
      } // end if-- DON'T CHANGE TO "No Name"
      return false;

    	
  
    } // end setName

    /*public void display(){
          System.out.println("Customer: name= "+
                name + ", Acct#= " + acctNum +
                ", savings balance= " +
                savings.getBalance() );
    } //end display*/
} // end class Customer
