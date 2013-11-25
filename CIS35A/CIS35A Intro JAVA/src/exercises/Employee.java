package exercises;

public class Employee {

protected String name;

protected String ssn;

public Employee( String n, String s ){
     name = n; ssn = s;
}

public String getName(){ return name; }

public String getSsn(){ return ssn; }
  // could add mutators

 

public String toString(){

return "Employee: name=" + name +

", SSN= "+ ssn;

}

} // end class Employee
