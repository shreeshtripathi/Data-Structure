// Trie - data Structure

package Lecture42;

import java.util.ArrayList;
import java.util.HashMap;

public class Trie {
	
	static class Node{
		char data;
		boolean eow;
		HashMap<Character, Node> cmap = new HashMap<>();
		Node(char data, boolean eow){
			this.data = data;
			this.eow = eow;
		}
	}
	
	static void addWord(Node root, String word) {
		if(word.length() == 0) {
//			System.out.println("Inside");
			root.eow = true;
			return;
		}
		char ch = word.charAt(0);
		String row = word.substring(1);
		if(root.cmap.containsKey(ch) == true) {
			Node child = root.cmap.get(ch);
			addWord(child, row);
		} else {
			Node child = new Node(ch, false);
			root.cmap.put(ch, child);
			addWord(child, row);
		}
	}
	
	static void removeWord(Node root, String word) {
		if(word.length() == 0) {
			root.eow = false;
			return;
		}
		char ch = word.charAt(0);
		String row = word.substring(1);
		Node child = root.cmap.get(ch);
		removeWord(child, row);
		
		if(child.eow == false && child.cmap.size() == 0) {
			root.cmap.remove(ch);
		}
		
		
	}
	
	static void displayWord(Node root, String asf) {
		if(root.eow == true) {
			System.out.print(asf + ", ");
		}
		ArrayList<Character> ans = new ArrayList<>(root.cmap.keySet());
		for(int i = 0; i < ans.size(); i++) {
			Node child = root.cmap.get(ans.get(i));
			displayWord(child, asf + ans.get(i));
		}
	}
	
	static void displayTrie(Node root) {
		System.out.print("[" + root.data + " " + root.eow  + "] -> ");
		ArrayList<Character> child = new ArrayList<>(root.cmap.keySet());
		for(int i = 0; i < child.size(); i++) {
			System.out.print(child.get(i) + ", ");
		}
		System.out.println(".");
		for(int i = 0; i < child.size(); i++) {
			Node cd = root.cmap.get(child.get(i));
			displayTrie(cd);
		}
	}
	
	static boolean searchWord(Node root, String word) {
		
		return false;
	}
	
	public static void main(String[] args) {
		Node root = new Node('$', false);
		addWord(root, "an");
		addWord(root, "and");
		addWord(root, "ant");
		addWord(root, "are");
		addWord(root, "as");
		addWord(root, "ask");
		addWord(root, "see");
		addWord(root, "sea");
		addWord(root, "seen");
		System.out.print("[");
		displayWord(root, "");
		System.out.println("]");
		displayTrie(root);
		System.out.println("~~~~~~~~~~~~~~~~~~~");
		removeWord(root, "as");
		displayTrie(root);
		System.out.println("~~~~~~~~~~~~~~~~~~~");
		removeWord(root, "ask");
		displayTrie(root);
		System.out.println("~~~~~~~~~~~~~~~~~~~");
	}
}
