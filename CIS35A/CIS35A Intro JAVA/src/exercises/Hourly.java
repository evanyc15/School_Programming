//Evan Chen
//Exercise 7.1

package exercises;

public class Hourly extends Employee {
private double hourlyRate;

Hourly(String name,String ssn, double rate){
	super(name,ssn);
	hourlyRate = rate;
}

public void sethourlyRate(double rate){
	hourlyRate = rate;
}

public double gethourlyRate(){
	return hourlyRate;
}

public String toString(){
	return "Hourly Rate" +super.toString()+", Hourly Rate= "+hourlyRate;
}
}


/*UML Diagram
----------------------------------------------------------
	Hourly <<subclass of Hourly>>
----------------------------------------------------------
+Hourly(name:String,ssn:String,rate:double)
+sethourlyRate():double
+gethourlyRate():double
+toString():String
----------------------------------------------------------
*/
