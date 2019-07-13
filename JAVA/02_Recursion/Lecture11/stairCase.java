package Lecture11;

import java.util.*;

public class stairCase {

	private static ArrayList<String> climbStairs(int n) {
		if (n < 0) {
			ArrayList<String> bres = new ArrayList<>();
			return bres;
		}
		if (n == 0) {
			ArrayList<String> bres = new ArrayList<>();
			bres.add("");
			return bres;
		}
		ArrayList<String> mres = new ArrayList<>();
		if (n >= 3) {
			ArrayList<String> rres = climbStairs(n - 3);
			for (int i = 0; i < rres.size(); i++) {
				mres.add('3' + rres.get(i));

			}
		}
		if (n >= 2) {

			ArrayList<String> rres = climbStairs(n - 2);
			for (int i = 0; i < rres.size(); i++) {
				mres.add('2' + rres.get(i));
			}
		}
		if (n >= 1) {
			ArrayList<String> rres = climbStairs(n - 1);
			for (int i = 0; i < rres.size(); i++) {
				mres.add('1' + rres.get(i));
			}
		}
		return mres;
	}

	public static void main(String[] args) {
		ArrayList<String> ans = climbStairs(4);
		System.out.println(ans);
	}

}
