package exercises;

import javax.swing.JFrame;

public class TryGUIExample {

	public static void main( String[] args ){
        String [] strs=
            {"Name", "Company", "Email Address", "Phone"};
        GUIExample gui = new GUIExample(strs);
        gui.setSize(400,200);
        gui.setVisible(true);
        gui.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   } // end main

} // end class TryGUIExample
