package Lecture11;
import java.util.*;
public class subSequence {

	public static void main(String[] args) {
		ArrayList<String> ans = gss("abc");
		System.out.println(ans);

	}
	
	private static ArrayList<String> gss(String s){
		if(s.length() == 0) {
			ArrayList<String> bres = new ArrayList<>();
			bres.add("");
			return bres;
		}
		
		char ch = s.charAt(0);
		ArrayList<String> rres = gss(s.substring(1, s.length()));
		ArrayList<String> mres = new ArrayList<>();
		for(int i = 0; i < rres.size(); i++) {
			mres.add('-' + rres.get(i));
			mres.add(ch + rres.get(i));
			
		}
		return mres;
	}

}
