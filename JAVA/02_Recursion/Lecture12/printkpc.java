package Lecture12;

public class printkpc {

	static String[] codes = {".;", "abc", "def", "ghi", "jkl",
			"mno", "pqrs", "tuv", "wx", "yz"};
	public static void main(String[] args) {
		pkpc("682","");
	}

	public static void pkpc(String ques, String ans) {
		if(ques.length() == 0) {
			System.out.println(ans);
			return;
		}
		
		
		char ch = ques.charAt(0);
		String roq = ques.substring(1);
		int test = codes[ch - '0'].length();
		for(int i = 0; i < test; i++) {
			pkpc(roq, ans + codes[ch - '0'].charAt(i));
		}
	}
}
