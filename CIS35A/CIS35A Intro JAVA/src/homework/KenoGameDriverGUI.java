 /*
 Program Name: Programming HW #7: KenoGameDriverGUI
 Programmer Name: Evan Chen
 Date: March 25, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 7 Spot: This is the Driver GUI class for the Keno Game. It contains the main method and 
 the various GUI components needed to display and play a GUI version of Homework 6's Keno Game.
 The class consists of a constructor that first initiates the JFrame. It will then initiate the
 top JPanel that will hold the JLabels, the JComboBox for number of spots, the JTextField for 
 the user's bet, and the JButton for the play Keno start button. The JComboBox will be assigned
 to an ItemListener. The JButton will be assigned to an actionListener. Next, the constructor will
 initiate the middle pannel which contains an array of 8x10 JButtons. The JButtons will be
 assigned to an actionlistener that will store the buttons that the user clicks on when
 the game asks for the user's guesses. The buttons will also change color, starting at
 yellow by default, cyan/blue for the random 20 keno numbers drawn, and then green if
 the player matched any after guessing. Finally, the constructor will initiate the bottom panel
 which holds the JLabel displaying the results and the JButton for playing another game.
 After the results display, if the user wishes to play again, he can click the play another game
 button and then it will restart the game.
 */

package homework;

import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class KenoGameDriverGUI{
	
	private static KenoGame7 player;
	private int SpotNumber;
	private int bet;
	private int counter;
	private int spotStatus;
	private String results;
	private JFrame frame;
	private int userIndex;
	private JButton playKeno;
	private JButton playAnotherGame;
	private JTextField betBox;
	private JComboBox numSpots;
	private JPanel topPanel,gameGrid,bottomPanel;
	private JLabel bottomInstructions;
	private JButton[][] backGrid;
	private int [] kenoNum;
	int [] userClick;
	
	public KenoGameDriverGUI(String input){
		String[] numberOfSpots = {"1","2","3","4","5","6","7","8",
				"9","10","11","12","13","14","15"};
		int i,j;
		int num = 0;
		String cellNumber;
		SpotNumber = 0;
		bet = 0;
		counter = 0;
		userIndex = 0;
	
		player = new KenoGame7();
		kenoNum = new int[20];
		userClick = new int[15];
		
		player.drawNumbers();
		
		frame = new JFrame(input);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(1024,800);
		
		//Top Panel of Frame
		topPanel = new JPanel();
		JLabel choose = new JLabel("Choose how many spots to play");
		numSpots = new JComboBox(numberOfSpots);
		JLabel enterBet = new JLabel("Enter the bet");
		betBox = new JTextField(10);
		playKeno = new JButton("Play Keno");
		topPanel.add(choose);
		topPanel.add(numSpots);
		topPanel.add(enterBet);
		topPanel.add(betBox);
		topPanel.add(playKeno);
		
		numSpots.setEnabled(true);
		betBox.setEnabled(true);
		playKeno.setEnabled(true);
		numSpots.addItemListener(new ComboBoxHandler());
		playKeno.addActionListener(new playKenoHandler());
	
		//Center Panel of Frame
		gameGrid = new JPanel();
		gameGrid.setLayout(new GridLayout(8,10,3,3));
		gameGrid.setBorder(BorderFactory.createEmptyBorder(1,1,1,1));
		backGrid = new JButton[8][10];
		
		for(i=0;i<backGrid.length;i++){
			for(j=0;j<backGrid[i].length;j++){
				num++;
				cellNumber = (Integer.toString(num));
				backGrid[i][j] = new JButton(cellNumber);
				backGrid[i][j].setBackground(Color.YELLOW);
				backGrid[i][j].setOpaque(true);
				backGrid[i][j].setBorderPainted(false);
				backGrid[i][j].setEnabled(false);
				backGrid[i][j].addActionListener(new playerInputHandler());
				gameGrid.add(backGrid[i][j]);
			}
		}
		
		//Bottom Panel of Frame
		bottomPanel = new JPanel();
		playAnotherGame = new JButton("Play Another Game");
		bottomInstructions = new JLabel("Placeholder");
		bottomPanel.add(bottomInstructions);
		bottomPanel.add(playAnotherGame);
		bottomInstructions.setVisible(false);
		playAnotherGame.setEnabled(false);
		
		frame.getContentPane().add(BorderLayout.NORTH,topPanel);
		frame.getContentPane().add(BorderLayout.CENTER,gameGrid);
		frame.getContentPane().add(BorderLayout.SOUTH,bottomPanel);
		frame.setVisible(true);
	}
	
	public static void main( String[] args ){
        KenoGameDriverGUI gui = new KenoGameDriverGUI("CIS35A Keno Game");
   } // end main 
	
	public class ComboBoxHandler implements ItemListener{
	    public void itemStateChanged(ItemEvent event) {
	       if (event.getStateChange() == ItemEvent.SELECTED) {
	          String item = (String)event.getItem();
	          SpotNumber = Integer.parseInt(item);
	          bottomInstructions.setText("Click on "+SpotNumber+" button(s) to choose numbers");
	       }
	    }       
	}
	public class playKenoHandler implements ActionListener{
		public void actionPerformed(ActionEvent e) { 
			Object click = e.getSource();
			int i,j;
			 
			if(click == playKeno){
				counter = 0;
				numSpots.setEnabled(false);
				betBox.setEnabled(false);
				playKeno.setEnabled(false);
				
				try{
					String betInput = betBox.getText();
					bet = Integer.parseInt(betInput);
					player.initKenoPlayer(SpotNumber,bet);
					}
					catch(NumberFormatException eg){
					JOptionPane.showMessageDialog(null,"Not a Number"); 
			        betBox.setText("");
					}
				
				for(i=0;i<backGrid.length;i++){
					for(j=0;j<backGrid[i].length;j++){
						backGrid[i][j].setEnabled(true);
					}
				}
			bottomInstructions.setVisible(true);
			}
		}
	}		 
	public class playerInputHandler implements ActionListener{
		public void actionPerformed(ActionEvent e){
			 Object click = e.getSource();
			 int index,i,j,row,column;
			 int kenoIndex = 0;
			 int num1 = 0;
			 int num2 = 0;
			 boolean status = true;
 
			 counter ++;
			 userIndex ++;
			
			 if(counter < SpotNumber){
				 OUTER: for(i=0;i<backGrid.length;i++){
						for(j=0;j<backGrid[i].length;j++){
							if(click.equals(backGrid[i][j])){
								index = (i*10)+(j+1);
								userClick[userIndex-1] = index;
								backGrid[i][j].setBackground(Color.GRAY);
								backGrid[i][j].setEnabled(false);
								spotStatus = player.setKenoPlayerSpot(index);
								break OUTER;
							}
						}
					}
			 }
			 if(counter == SpotNumber){
				 OUTER: for(i=0;i<backGrid.length;i++){
						for(j=0;j<backGrid[i].length;j++){
							if(click.equals(backGrid[i][j])){
								index = (i*10)+(j+1);
								userClick[userIndex-1] = index;
								backGrid[i][j].setBackground(Color.GRAY);
								spotStatus = player.setKenoPlayerSpot(index);
								break OUTER;
							}
						}
					}
				for(i=0;i<backGrid.length;i++){
					 	for(j=0;j<backGrid[i].length;j++){
						backGrid[i][j].setEnabled(false);
					}
				} 
				for(i=0;i<kenoNum.length;i++){
						kenoNum[i] = player.getdrawnSpots(i);
					}
				player.getResults();
				 		
				while((status==true)&&(kenoIndex<20)){
				OUTERMOST: for(i=0;i<backGrid.length;i++){
					for(j=0;j<backGrid[i].length;j++){
					status = false;
					if(((i*10)+(j+1))==kenoNum[kenoIndex]){
						backGrid[i][j].setBackground(Color.CYAN);
						kenoIndex++;
						status = true;
						break OUTERMOST;
					}
					}
				}
				}
				userIndex = 0;
				while(userIndex<SpotNumber){
					OUTER: for(i=0;i<20;i++){
						num1 = userClick[userIndex];
						num2 = kenoNum[i];
						if(num1==num2){
							row = num1/10;
							column = (num2%10)-1;
							backGrid[row][column].setBackground(Color.GREEN);
							break OUTER;
						}
					}
				userIndex++;
				}
				results = player.displayResults();
				bottomInstructions.setText(results);
				playAnotherGame.setEnabled(true);
				playAnotherGame.addActionListener(new anotherGameHandler());
			 }
	}
	public class anotherGameHandler implements ActionListener{
		public void actionPerformed(ActionEvent e){
			Object click = e.getSource();
			if(click == playAnotherGame){
				int i;
				int j;
				SpotNumber = 0;
				bet = 0;
				counter = 0;
				userIndex = 0;
				
				player.drawNumbers();
				
				numSpots.setEnabled(true);
				betBox.setEnabled(true);
				playKeno.setEnabled(true);
				numSpots.setSelectedIndex(-1);
				betBox.setText("");
				
				for(i=0;i<backGrid.length;i++){
					for(j=0;j<backGrid[i].length;j++){
						backGrid[i][j].setBackground(Color.YELLOW);
					}
				}
				bottomInstructions.setVisible(false);
				playAnotherGame.setEnabled(false);

			}
		}
	}
	}			 
}
		


