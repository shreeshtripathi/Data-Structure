package Lecture14;

import java.util.*;

public class targetSum {

	public static void main(String[] args) {
		int[] arr = { 10, 20, 30, 40, 50, 60, 70 };
		ArrayList<ArrayList<Integer>> ans = tarSum(arr, 70, 0);

		System.out.println(ans);
	}

	// s p = starting point
	public static ArrayList<ArrayList<Integer>> tarSum(int[] arr, int tar, int sp) {

		if (sp == arr.length) {
			ArrayList<ArrayList<Integer>> bres = new ArrayList<ArrayList<Integer>>();
			if (tar == 0) {
				ArrayList<Integer> vk = new ArrayList<Integer>();
				bres.add(vk);
				return bres;
			}
			return bres;
		}

		ArrayList<ArrayList<Integer>> mres = new ArrayList<ArrayList<Integer>>();
		ArrayList<ArrayList<Integer>> rres1 = tarSum(arr, tar, sp + 1);
		ArrayList<ArrayList<Integer>> rres2 = tarSum(arr, tar - arr[sp], sp + 1);

		for (int j = 0; j < rres1.size(); j++) {
			mres.add(rres1.get(j));
		}
		for (int j = 0; j < rres2.size(); j++) {
			rres2.get(j).add(arr[sp]);
			mres.add(rres2.get(j));
		}

		return mres;

	}

}
