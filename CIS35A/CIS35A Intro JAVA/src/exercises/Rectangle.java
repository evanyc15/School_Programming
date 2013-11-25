//Evan Chen
//Exercise 5.1

package exercises;

public class Rectangle {
	
	private int length;
	private int width;
	private int area;
	private int perimeter;
	
	public Rectangle(int x, int y){
		if(x<=0 || y<=0){
		length = 1;
		width = 1;
		}
		if(x>0 && y>0){
		length = x;
		width = y;
		}
	}
	
	public void setLength(int x){
		if(x>0)
			length = x;
	}
	
	public void setWidth(int y){
		if(y>0)
			width = y;
	}
	
	public int Area(int x, int y){
		return x*y;
	}
	public int Perimeter(int x, int y){
		return x+x+y+y;
	}

}




/*UML Diagram for Rectangle class:
 ---------------------------------------------------------
-length:int
-width: int
-perimeter:int
-area:int
----------------------------------------------------------
+Rectangle(x:int, y:int)
<<constructor>>
+setLength(x:int)
+setWidth(y:int)
+area(x:int,y:int):int
+perimeter(x:int,y:int):int 
 */

