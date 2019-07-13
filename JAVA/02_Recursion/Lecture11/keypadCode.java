package Lecture11;
import java.util.*;
public class keypadCode {
	
	static String[] codes = {".;", "abc", "def", "ghi", "jkl",
			"mno", "pqrs", "tuv", "wx", "yz"};
	
	private static ArrayList<String> gkpc(String s){
		if(s.length() == 0) {
			ArrayList<String> bres = new ArrayList<>();
			bres.add("");
			return bres;
		}
		
		char ch = s.charAt(0);
		int c = (int)ch - 48;
		String ros = s.substring(1, s.length());
		ArrayList<String> rres = gkpc(ros);
		ArrayList<String> mres = new ArrayList<>();
		for(int i = 0; i < rres.size(); i++) {
			for(int j = 0; j < codes[c].length(); j++) {
				mres.add(codes[c].charAt(j) + rres.get(i));
			}
			
		}
		return mres;
	}
	
	
	public static void main(String[] args) {
		ArrayList<String> ans = gkpc("682");
		System.out.println(ans);
	}

}
