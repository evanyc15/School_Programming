//Evan Chen
//Exercise 7.4

package exercises;

import java.util.Scanner;
import java.lang.Object;

public class Node {
	static Scanner scanner = new Scanner(System.in);
	private static Integer data; // instead of C/C++ void*
	private Node next;

	public Node(Integer o, Node n ){
			          data = o;  next = n;
	}
	
	public static Integer getData(){
		return data;
	}
	
	public void setNode(Integer temp){
		data = temp;
	}
	
	public void setNext(Node temp){
		next = temp;
	}
	
	public static Node userNode(){
		Integer temp;
		
		System.out.print("Please enter a number: ");
		temp = scanner.nextInt();
		Node node1 = new Node(temp,null);
		return node1;
	}
	
	public static void main(String[] args) {
		Node tempNode;
		Integer tempData;
		
		tempNode = userNode();
		tempData = getData();
		System.out.print("Inputed number: "+tempData+"\n");
		tempData = 2 * tempData;
		Node node2 = new Node(tempData,tempNode);
		System.out.print("Calculated number: "+(node2.getData()));
	}
	
	}

/*OUTPUT
Please enter a number: 5
Inputed number: 5
Calculated number: 10
*/