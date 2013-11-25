//Evan Chen
//Exercise 7.2

package exercises;

public class Hourly2 extends Employee2 {
private double hoursWorked;
private double hourlyRate;
Employee2 [] empArray= new Employee2[] {

		new Hourly2("Donald Duck", "123-45-6789", 20., 30.),

		new Salaried("Mickey Mouse", "987-65-4321", 100000.),

		new Salaried("Bugs Bunny", "121-21-2121", 90000.),

		new Hourly2("Elmer Fudd", "343-43-4343", 10., 15.) };

Hourly2(String name, String ssn, double worked, double rate){
	super(name,ssn);
	hoursWorked = worked;
	hourlyRate = rate;
	}

public double getPay(){
	int i;
	
	for(i=0;i<empArray.length;i++){
		System.out.print(empArray[i].toString());
		return empArray[i].computePay();
	}
	return computePay();
}
	

public double computePay() {
	return Math.round((hoursWorked*hourlyRate)*100.)/100.;
}

public String toString(){
    return "Salaried: name=" + name +
         ", SSN=" + ssn;
}
	
	
	
	
	
}
