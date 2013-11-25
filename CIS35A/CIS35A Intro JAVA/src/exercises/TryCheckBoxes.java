// EXAMPLE 9.1 JAVA CODE AND EXERICSE 9.1 (SEE BELOW)

package exercises;

import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class TryCheckBoxes extends JFrame  {
	private JCheckBox chBoxA= new JCheckBox("A");
	private JCheckBox chBoxB= new JCheckBox("B");
	private JCheckBox chBoxC= new JCheckBox("C");
	private JCheckBox chBoxD= new JCheckBox("D");
	private JLabel labelA=new JLabel("A is ON ");
	private JLabel labelB=new JLabel("B is ON ");
	private JLabel labelC=new JLabel("C is ON");
	private JLabel labelD=new JLabel("D is ON");

  	public TryCheckBoxes(){
    	super("Try CheckBoxes"); // puts "Try CheckBoxes in title bar of JFrame
   		setLayout(new FlowLayout()); // sets JFrame layout
		chBoxA.addItemListener(new CheckBoxAHandler());
		chBoxB.addItemListener(new CheckBoxBHandler());
		chBoxC.addItemListener(new CheckBoxCHandler());
		chBoxD.addItemListener(new CheckBoxDHandler());
		labelA.setVisible(false); // make label invisible
		labelB.setVisible(false); // make label invisible
		labelC.setVisible(false); // make label invisible
		labelD.setVisible(false); // make label invisible

		// put all components into JFrame
		add(chBoxA);
		add(chBoxB);
		add(chBoxC);
		add(chBoxD);
		add(labelA);
		add(labelB);	
		add(labelC);
		add(labelD);
	 } // end constructor

	public static void main( String [] args ){
      	TryCheckBoxes tcb =new TryCheckBoxes();
		tcb.setSize(800, 640);
		tcb.setVisible(true);
		tcb.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	} // end main

//  inner classes for listener classes
	class CheckBoxAHandler implements ItemListener {
		public void itemStateChanged( ItemEvent e ){
			if( chBoxA.isSelected() )
				labelA.setVisible(true);
			else
				labelA.setVisible(false);
		} // end itemStateChanged for check box A
	} // end CheckBoxAHandler listener class

	class CheckBoxBHandler implements ItemListener {
		public void itemStateChanged( ItemEvent e ){
			if( e.getStateChange() == ItemEvent.SELECTED ) // another way to check if selected
				labelB.setVisible(true);
			else
				labelB.setVisible(false);
		} // end itemStateChanged  for check box B
	} // end CheckBoxBHandler listener class

	class CheckBoxCHandler implements ItemListener {
		public void itemStateChanged( ItemEvent e ){
			labelC.setVisible(chBoxC.isSelected()); // BEST WAY
		} // end itemStateChanged for check box C
	} // end CheckBoxCHandler listener class
	class CheckBoxDHandler implements ItemListener {
		public void itemStateChanged( ItemEvent e ){
			labelD.setVisible(chBoxD.isSelected());
		}
	}

} // end class TryCheckBoxes

/*
EXERCISE 9.1 (see due date on Catalyst link Exercise9.1-Upload-Here where you will upload your answer)  

Run the program above. 

THEN change it to have another JCheckBox for "D", and another JLabel for "D is ON".  

Be sure to put them in JFrame, and add another listener inner class for "D" which makes the "D" JLabel visible or  
invisible depending on the check box.

CLOSE THIS BROWSWER TAB WHEN FINISHED


*/

