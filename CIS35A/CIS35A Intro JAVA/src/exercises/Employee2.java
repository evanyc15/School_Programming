package exercises;

public abstract class Employee2 {

protected String name;

protected String ssn;

public Employee2( String n, String s ){
     name = n; ssn = s;
}

public String getName(){ return name; }

public String getSsn(){ return ssn; }
  // could add mutators

public abstract double computePay();

} // end abstract class Employee

 // in another class and file: