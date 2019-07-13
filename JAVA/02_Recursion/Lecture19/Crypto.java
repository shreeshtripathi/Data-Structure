package Lecture19;

import java.util.Arrays;

public class Crypto {

	public static void main(String[] args) {
		String str1 = "send", str2 = "more", str3 = "money";
		String qs = "", ts = str1 + str2 + str3;
		boolean[] qstr = new boolean[26];
		for(int i = 0; i < ts.length(); i++) {
			if(qstr[(int)(ts.charAt(i) - 'a')] == false) {
				qs = qs + ts.charAt(i);
			}
			qstr[(int)(ts.charAt(i) - 'a')] = true;
		}
		System.out.println(qs);
		boolean[] dusf = new boolean[10];
		int[] map = new int[26];
//		for(int i = 0; i < 26; i++) {
//			map[i] = -1;
//		}
		Arrays.fill(map, -1);
		
		crypt(str1, str2, str3, qs, map, dusf);
	}
	//(int)(qs.charAt(i) - 'a')
	public static int gnas(String s, int[] map) {
		int ans = 0;
		int p = 1;
		for(int i = s.length() - 1; i >= 0; i--) {
			ans += map[s.charAt(i) - 'a'] * p;
			p *= 10;
		}
		
		return ans;
	}
	
	
	public static void crypt(String s1, String s2, String s3, String qs, int[] map, boolean[] dusf) {
		if(qs.length() == 0) {
			int val1 = gnas(s1, map);
			int val2 = gnas(s2, map);
			int val3 = gnas(s3, map);
			if(val1 + val2 == val3) {
				System.out.println("--------");
				System.out.println(val1);
				System.out.println("+" + val2);
				System.out.println("_____");
				System.out.println(val3);
				System.out.println("--------");
			}
			
			return;
		}
		
		
		
		char ch = qs.charAt(0);
		String ros = qs.substring(1);
		
		for(int d = 0; d <= 9; d++) {
			if(dusf[d] == false) {
				dusf[d] = true;
				map[ch - 'a'] = d;
				crypt(s1, s2, s3, ros, map, dusf);
				map[ch - 'a'] = -1;
				dusf[d] = false;
			}
		}
		
	}

}
