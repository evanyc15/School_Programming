//Evan Chen
//Exercise 9_4

package exercises;

import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class Exercise9_4 extends JApplet
		implements ActionListener {
	private JCheckBox chBoxA= new JCheckBox("A");
	private JCheckBox chBoxB= new JCheckBox("B");
	private JCheckBox chBoxC= new JCheckBox("C");
	private JCheckBox chBoxD= new JCheckBox("D");
	private JLabel labelA=new JLabel("A is ON ");
	private JLabel labelB=new JLabel("B is ON ");
	private JLabel labelC=new JLabel("C is ON");
	private JLabel labelD=new JLabel("D is ON");


	public void init(){
		setLayout(new FlowLayout()); // sets JFrame layout
		chBoxA.addActionListener(this);
		chBoxB.addActionListener(this);
		chBoxC.addActionListener(this);
		chBoxD.addActionListener(this);
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
	}
	public void actionPerformed(ActionEvent e){
		Object source = e.getSource();
		if( source == (Object) chBoxA){
			labelA.setVisible(true);
		}
		if( source == (Object) chBoxB){
			labelB.setVisible(true);
		}
		if( source == (Object) chBoxC){
			labelC.setVisible(true);
		}
		if( source == (Object) chBoxD){
			labelD.setVisible(true);
		}
	}
	}