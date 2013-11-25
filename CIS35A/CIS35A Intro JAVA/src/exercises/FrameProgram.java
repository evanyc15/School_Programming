//Evan Chen
//Exercise 9.2

package exercises;

import java.awt.*;// doesn't include sub-packages
import java.awt.event.*;// need to import for events
import javax.swing.*;

public class FrameProgram extends JFrame {
	private static int TFSIZE = 30;
	private static int TRIMSIZE = 20;
	private JComboBox comboBox; // a drop-down menu
	private JComboBox trimBox;
	private JButton trimBtn;
	private JButton clearBtn;
	private JButton reverseBtn;
	private JTextField outText;
	private StringBuilder outSB= new StringBuilder();

	public FrameProgram(String [] strArray,String[] trimArray){
	       	 super("Frame Program");
	    
	 	// create JComboBox, putting in strings from parameter
        	comboBox = new JComboBox(strArray);
        	comboBox.addActionListener(new JComboBoxHandler()); //make a listener object, register it
        	trimBox = new JComboBox(trimArray);
        	trimBox.addActionListener(new JComboBoxAHandler());
      
        	outText=new JTextField(TFSIZE);// about 30 chars visible
        	outText.setEditable(false); // user can’t change it, program can

		JButtonHandler jbh = new JButtonHandler(); // create listener object using inner class
		trimBtn = new JButton("Trim"); // create a button with "Trim" written on it
		trimBtn.addActionListener(jbh); // register the jbh object as listener on trimBtn
		clearBtn = new JButton("Clear");// create a button with "Clear" written on it
		clearBtn.addActionListener(jbh);// register the jbh object as listener on clearBtn
		reverseBtn = new JButton("Reverse");
		reverseBtn.addActionListener(jbh);
		
       		setLayout(new FlowLayout());//need layout for JFrame
		add(comboBox); // adds JComboBox to JFrame
		add(trimBox);
		add(outText); // adds JTextfield to JFrame
        		add(trimBtn); // adds 1st JButton to JFrame
		add(clearBtn); // adds 2nd JButton to JFrame
		add(reverseBtn);
        } // end constructor


	public static void main( String[] args ){
		FrameProgram fp =new FrameProgram(new String []{
			"First", "Second", "Third", "Fourth", "Fifth"},new String[]{"10","20","30"});
		fp.setSize(400, 200);
		fp.setVisible(true);
		fp.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	} // end main

	class JComboBoxHandler implements ActionListener {
		public void actionPerformed(ActionEvent e){
        		String chosenStr;

			chosenStr = (String) comboBox.getSelectedItem();
			outSB.insert(0, chosenStr);
			outText.setText(outSB.toString());
		} // end actionPerformed
	} // end JComboBoxHandler inner class
	class JComboBoxAHandler implements ActionListener {
		public void actionPerformed(ActionEvent e){
			String chosenStr;
			
			chosenStr = (String) trimBox.getSelectedItem();
			TRIMSIZE = Integer.parseInt(chosenStr);
		}
	}

	class JButtonHandler implements ActionListener {//SAME FOR EACH BUTTON
		// EXAMPLE OF USING ONE LISTENER FOR BOTH BUTTONS
		public void actionPerformed(ActionEvent e){
        		Object source = e.getSource(); // get the object that triggered event

			if( source == trimBtn ){ // if it's the trim button
				outSB.setLength(TRIMSIZE);
				outText.setText(outSB.toString());
			}else // added another if to allow more buttons to handle
				if( source == clearBtn ){ // if it's the clear button
					outSB.setLength(0);
					outText.setText("");
				} // end if clearBtn
				else 
					if( source == reverseBtn ){
						outSB.reverse();
						outText.setText(outSB.toString());
					}
		} // end actionPerformed
	} // end JButtonHandler inner class
} // end class FrameProgram
/*
EXERCISE 9.2 (see due date on Catalyst link Exercise9.2-Upload-Here where you will upload your answer)  

Run the program shown above. 

THEN change it to have another JButton with "Reverse" on the button, which will reverse the StringBuilder and 
put back in the JTextField AND add a JComboBox with "10", "20", and "30" choices for changing the trim size to 10, 20 or 30.  

Be sure to put them in the JFrame, change the JButtonHandler method to have another condition for the Reverse button and add 
a new inner class for handling the JComboBox (see example 1 used in Exercise 1).  

Hint: Use the parseInt static method in the Integer class to convert from a String to an int.  

CLOSE THIS BROWSWER TAB WHEN FINISHED

*/

