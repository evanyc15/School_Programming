//Evan Chen
//Exercise 5.2 (This class is using the corrected 5.1 exercise)

package exercises;

public class Rectangle2 {
	 private double length=1.;
     private double width=1.;
     private double perimeter=4.;
     private double area=1.;
     
     public static void main(String[] args){
  	   Rectangle2 r1 = new Rectangle2();
  	   Rectangle2 r2 = new Rectangle2();
  	   
  	   r1.setLength(50.);
  	   r2.setLength(81.);
  	   r1.setWidth(26.);
  	   r2.setWidth(43.);
  	   r1.display();
  	   r2.display();
     }

     public Rectangle2(double len, 
                          double wid){
            if(len > 0){
                   length = len;
                   calcAreaAndPerimeter();
            }
            // else leave at 1
    
            // another way to do this:
            setWidth(wid);//if didn't work, leave as 1            
     } // end constructor

     public Rectangle2(){ }// does nothing

     private void calcAreaAndPerimeter(){
            perimeter = 2.*(length+width);
            area = length * width;
     } // end calcAreaAndPerimeter

     public double getLength(){ return length; }

     public double getWidth(){ return width; }

     public double getPerimeter(){ return perimeter; }

     public double getArea(){ return area; }

     public boolean setLength(double len){
            if( len > 0 ){
                   length= len;
                   calcAreaAndPerimeter();
                   return true;
            }// end if
            // DON'T print an error message
            return false;
     } // end setLength

     public boolean setWidth(double wid){
            if( wid > 0 ){
                   width = wid;
                   calcAreaAndPerimeter();
                   return true;
            }// end if
            return false;
     } // end setWidth

     public void display(){
          System.out.println("Rectangle: length= "+
                length + ", width= " + width +
                ", perimeter= "+ perimeter +
                ", area= " + area);
    } // end display
} // end class Rectangle


/*
-------------------------------------
Rectangle
-length: double
-width: double
-perimeter: double
-area: double
-------------------------------------
+Rectangle(len: double, wid: double)
+Rectangle()
-calcAreaAndPerimeter()
+getLength(): double
+getWidth(): double
+getPerimeter():double
+getArea(): double
+setLength(len:double):boolean
+setWidth(wid:double):boolean
+display()
-------------------------------------
*/


/*OUTPUT
 
Rectangle: length= 50.0, width= 26.0, perimeter= 152.0, area= 1300.0
Rectangle: length= 81.0, width= 43.0, perimeter= 248.0, area= 3483.0

*/