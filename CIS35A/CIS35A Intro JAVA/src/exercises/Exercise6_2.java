//Evan Chen
//Exercise 6.2

package exercises;

import java.util.*;

public class Exercise6_2 {
	public boolean setName(String name){
	    	StringTokenizer strTok = new StringTokenizer(name,",");
	    	
	    	if(name!= null && name.length() > 0 ){
	//commented to prevent HW errors(disable when needed            lastName.append(strTok.nextToken());
	//same as above          firstName.append(strTok.nextToken());
	            return true;
	      } // end if-- DON'T CHANGE TO "No Name"
	    	return false;

}
}
