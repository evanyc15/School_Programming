 /*
 Program Name: Programming HW #6: KenoGame
 Programmer Name: Evan Chen
 Date: March 21, 2013
 OS & Compiler: MS Windows 7 x64Bit Ultimate & Eclipse Juno Service Release 1
 Description: 
 Homework 6 KenoGameDriver: This is the driver class. This class will 
 instantiate a new KenoGame and then ask the user for how many spots they
 wish to choose and the spot numbers. It will then send the inputs to the
 other objects so that the matches and winnings can be calculated. It will
 also print out if the inputed numbers were out of bounds or already chosen.
 Afterwards, it will ask if the player wishes to play again.
 */

package homework;

import java.util.Scanner;

public class KenoGameDriver {
	static Scanner scanner = new Scanner(System.in);
	public static void main(String[] args) {
		KenoGame player = new KenoGame();
		boolean playing = true;
		String anotherPlay;
	
		while(playing == true){
			player.drawNumbers();
			playKeno(player);
			player.getResults();
			player.displayResults();
			System.out.print("Play another game? (y for yes): ");
			anotherPlay = scanner.nextLine();
			playing = playAgain(anotherPlay);
			System.out.print("\n");
		}
		System.out.print("Thank you for playing Keno");
	}
	
	public static void playKeno(KenoGame input){
		int numSpots, playBet;
		int playerIndex;
		int spotStatus;
		int counter = 1;
		System.out.print("How many spots do you want to choose? (max. 15): ");
		numSpots = scanner.nextInt();
		scanner.nextLine();
		System.out.print("What is your bet (at least $1): ");
		playBet = scanner.nextInt();
		scanner.nextLine();
		
		if(numSpots < 1 || numSpots >= KenoGame.payoffAmounts.length){
			numSpots = 1;
		}
		if(playBet<=0){
			playBet = 1;
		}
		input.initKenoPlayer(numSpots,playBet);
		
		while(counter <= numSpots){
			System.out.print("Enter number #"+counter+
					" (between 1 and "+KenoGame.MAX_KENO_NUMBER+"): ");
			playerIndex = scanner.nextInt();
			scanner.nextLine();
			spotStatus = input.setKenoPlayerSpot(playerIndex);
			if(spotStatus == (-1)){
				System.out.print("Number is out of range!\n");
			}
			if(spotStatus == 1){
				System.out.print("You already chose that number!\n");
			}
			if(spotStatus == 0){
				counter++;
			}
		}
	}
	public static boolean playAgain(String input){
		char userInput;
		char lower;
		userInput = input.charAt(0);
		lower = Character.toLowerCase(userInput);
		if(lower == 'y'){
		return true;
		}
		return false;
	}
}
