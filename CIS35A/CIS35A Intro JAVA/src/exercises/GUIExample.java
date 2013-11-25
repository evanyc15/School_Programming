//Evan Chen
//Exercise 9.3

package exercises;

import java.awt.*; 
import java.awt.event.*;
import javax.swing.*; 

public class GUIExample extends JFrame                    
            implements ActionListener, ItemListener{      
      private JCheckBox[] cbs; 
      private String [] boxNames;
      private int arrSize;
      private JTextField[] tfs;
      private JButton displayBtn, clearBtn; 
      private JTextArea display;
      
      public GUIExample(String [] names){
            arrSize = names.length;
            boxNames = names;
            setLayout(new BorderLayout());// set layout for JFrame
            // Create panel with Checkboxes
            JPanel p1= new JPanel(
                  new GridLayout(arrSize, 1, 5, 5));
            cbs = new JCheckBox[arrSize];
            for( int i=0 ; i<arrSize ; ++i ){
                  cbs[i] = new JCheckBox(boxNames[i]);
                  p1.add(cbs[i]);
                  cbs[i].addItemListener(this );
            } // end for
            // Create panel with TextFields
            JPanel p2 = new JPanel(
                  new GridLayout(arrSize, 1, 5, 5));              
            tfs = new JTextField[arrSize];
            for( int i=0; i<arrSize ; ++i ){
                  tfs[i] = new JTextField(18);
                  p2.add(tfs[i]);
            } // end for
            // Create panel with a buttons
            JPanel p3 = new JPanel();
            displayBtn = new JButton("Display Selected");
            p3.add(displayBtn);
            displayBtn.addActionListener(this);
            clearBtn = new JButton("Clear Text Fields");
            p3.add(clearBtn);
            clearBtn.addActionListener(this);

            add(p1, BorderLayout.WEST); // checkboxes in WEST
            add(p2, BorderLayout.EAST); // textfields in EAST
            add(p3, BorderLayout.SOUTH); // buttons in SOUTH
      } // end constructor
      
      public void actionPerformed( ActionEvent e ){
            Object obj=e.getSource();
            String s;
            display = new JTextArea("",5,10);
            JFrame frame = new JFrame("User Information");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            display.setLineWrap(true);
            
            if( obj  == displayBtn ){ // Display Selected clicked
                  for( int i=0 ; i<arrSize ; ++i ){
                        if( cbs[i].isSelected() && //check box selected?
                             !(s=tfs[i].getText()).equals("") )//has text?
                        	display.append(s);
                        	display.append("  ");
                  } // end for
            frame.add(display);
            frame.pack();
            frame.setVisible(true);
            } // end if
            else if( obj == clearBtn ){// Clear Textfields clicked
                        for( int i=0 ; i < arrSize; ++i )
                             tfs[i].setText("");
            } // end else
      } // end actionPerformed

      public void itemStateChanged( ItemEvent e ){
            JCheckBox cb= (JCheckBox) e.getSource();
            String s;
            
            //display ONLY if a check box was selected
            if( e.getStateChange() == ItemEvent.SELECTED ){
                  for( int i=0 ; i<arrSize ; ++i ){
                        if( cbs[i]== cb ){ // found Checkbox
                             if(!(s=tfs[i].getText()).equals("") )
                            	 	JOptionPane.showMessageDialog(cb,s);
                             break ;
                         } // end if cbs 
                  } // end for
            } // end if
      } // end ItemStateChanged()
      
} // end class GUIExample


 