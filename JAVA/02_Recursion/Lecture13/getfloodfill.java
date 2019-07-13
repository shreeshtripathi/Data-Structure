package Lecture13;

import java.util.*;
public class getfloodfill {
	
	public static ArrayList<String> gff(int[][] arr, int cr, int cc, int dr, int dc){
		
		if(cr == dr && cc == dc) {
			ArrayList<String> bres = new ArrayList<String>();
			bres.add("");
			return bres;
		}
		
		if(cr > dr || cc > dc || cr < 0 || cc < 0 || arr[cr][cc] == 1 || arr[cr][cc] == 2) {
			ArrayList<String> fail = new ArrayList<String>();
			return fail;
		}
		
		
		arr[cr][cc] = 2;
		ArrayList<String> left = gff(arr, cr, cc - 1, dr, dc);
		ArrayList<String> down = gff(arr, cr + 1, cc, dr, dc);
		ArrayList<String> right = gff(arr, cr, cc + 1, dr, dc);
		ArrayList<String> top = gff(arr, cr - 1, cc, dr, dc);
		ArrayList<String> ans = new ArrayList<>();
		arr[cr][cc] = 0;
		for(int i = 0; i < left.size(); i++) {
			ans.add("L" + left.get(i));
		}
		for(int i = 0; i < down.size(); i++) {
			ans.add("D" + down.get(i));
		}
		for(int i = 0; i < right.size(); i++) {
			ans.add("R" + right.get(i));
		}
		for(int i = 0; i < top.size(); i++) {
			ans.add("T" + top.get(i));
		}
		
		return ans;
		
	}

	public static void main(String[] args) {
		int[][] arr = {
				{0, 1, 0, 0, 0, 0},
				{0, 1, 0, 1, 1, 0},
				{0, 0, 0, 0, 0, 0},
				{0, 1, 0, 1, 1, 0},
				{0, 1, 0, 0, 0, 0}
		};
		ArrayList<String> ans = gff(arr, 0, 0, arr.length - 1, arr[0].length - 1);
		System.out.println(ans);
	}

}
