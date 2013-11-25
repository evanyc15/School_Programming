package exercises;

public class Salaried extends Employee2 {

private double salary;
private static int payPeriods = 12;

public Salaried( String name, String ssn, double s){
     super(name, ssn);
     salary = s;
}
public void setSalary( double sal ){ salary = sal; }

public double getSalary(){ return salary; }

public double computePay(){
     return Math.round(salary/payPeriods*100.)/100.;
}

public String toString(){
     return "Salaried: name=" + name +
          ", SSN=" + ssn + ", Salary=" + salary;
}

} // end class Salaried