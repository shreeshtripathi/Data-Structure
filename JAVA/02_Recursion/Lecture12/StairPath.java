package Lecture12;

import java.util.*;

public class StairPath {

	public static void main(String[] args) {
		ArrayList<String> ans = gsp(4);
		System.out.println(ans);
		System.out.println();
		psp(4, "");

	}

	public static void psp(int n, String psf) {
		if (n == 0) {
			System.out.println(psf);
			return;
		}

		if (n >= 3) {
			psp(n - 3, psf + "3");
		}
		if (n >= 2) {
			psp(n - 2, psf + "2");
		}
		if (n >= 1) {
			psp(n - 1, psf + "1");
		}
	}

	public static ArrayList<String> gsp(int n) {
		if (n == 0) {
			ArrayList<String> bres = new ArrayList<>();
			bres.add("");
			return bres;
		}
		ArrayList<String> mres = new ArrayList<>();
		if (n >= 3) {
			ArrayList<String> rres = gsp(n - 3);
			for (int i = 0; i < rres.size(); i++) {
				mres.add('3' + rres.get(i));

			}
		}
		if (n >= 2) {

			ArrayList<String> rres = gsp(n - 2);
			for (int i = 0; i < rres.size(); i++) {
				mres.add('2' + rres.get(i));
			}
		}
		if (n >= 1) {
			ArrayList<String> rres = gsp(n - 1);
			for (int i = 0; i < rres.size(); i++) {
				mres.add('1' + rres.get(i));
			}
		}
		return mres;
	}

}
