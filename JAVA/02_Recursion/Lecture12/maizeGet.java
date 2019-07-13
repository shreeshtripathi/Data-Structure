package Lecture12;

import java.util.*;

public class maizeGet {

	public static void main(String[] args) {

		ArrayList<String> ans1 = gmp1(0, 0, 2, 2);
		System.out.println(ans1);
		ArrayList<String> ans2 = gmp2(0, 0, 2, 2);
		System.out.println(ans2);

	}

	public static ArrayList<String> gmp1(int cr, int cc, int dr, int dc) {
		if(cr == dr && cc == dc) {
			ArrayList<String> bres = new ArrayList<String>();
			bres.add("");
			return bres;
		}
		if(cr > dr || cc > dc) {
			ArrayList<String> bres = new ArrayList<String>();
			return bres;
		}
		ArrayList<String> rres1 = gmp1(cr + 1, cc, dr, dc);
		ArrayList<String> rres2 = gmp1(cr, cc + 1, dr, dc);
		ArrayList<String> ans = new ArrayList<>();
		for(int i = 0; i < rres1.size(); i++) {
			ans.add("h" + rres1.get(i));
		}
		for(int i = 0; i < rres2.size(); i++) {
			ans.add("v" + rres2.get(i));
		}
		return ans;
	}

	public static ArrayList<String> gmp2(int cr, int cc, int dr, int dc) {
		if(cr == dr && cc == dr) {
			ArrayList<String> bres = new ArrayList<>();
			bres.add("");
			return bres;
		}
		
		ArrayList<String> mres = new ArrayList<>();
		for(int i = 1; i <= dc - cc; i++) {
			ArrayList<String> rr = gmp2(cr, cc + i, dr, dc);
			for(int j = 0; j < rr.size(); j++) {
				mres.add("h" + i + rr.get(j));
			}
		}
		for(int i = 1; i <= dr - cr; i++) {
			ArrayList<String> rr = gmp2(cr + i, cc, dr, dc);
			for(int j = 0; j < rr.size(); j++) {
				mres.add("v" + i + rr.get(j));
			}
		}
		for(int i = 1; i <= dc - cc && i <= dr - cr; i++) {
			ArrayList<String> rr = gmp2(cr + i, cc + i, dr, dc);
			for(int j = 0; j < rr.size(); j++) {
				mres.add("d" + i + rr.get(j));
			}
		}
		return mres;
		}

}
