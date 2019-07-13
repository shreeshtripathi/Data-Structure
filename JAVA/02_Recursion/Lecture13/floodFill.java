package Lecture13;

public class floodFill {

	public static void main(String[] args) {
		int[][] arr = {
				{0, 1, 0, 0, 0, 0},
				{0, 1, 0, 1, 1, 0},
				{0, 0, 0, 0, 0, 0},
				{0, 1, 0, 1, 1, 0},
				{0, 1, 0, 0, 0, 0}
		};
		ff(arr, 0, 0, arr.length - 1, arr[0].length - 1, "");
	}
	
	public static void ff(int[][] arr, int cr, int cc, int dr, int dc, String psf) {
		if(cr == dr && cc == dc) {
			System.out.println(psf);
			return;
		}
		if(cr < 0 || cr > dr || cc < 0 || cc > dc ||arr[cr][cc] == 1
				|| arr[cr][cc] == 2) {
			return;
		}

		
		arr[cr][cc] = 2; //mark of visited place
		ff(arr, cr - 1, cc, dr, dc, psf + "t");
		ff(arr, cr, cc - 1, dr, dc, psf + "l");
		ff(arr, cr + 1, cc, dr, dc, psf + "d");
		ff(arr, cr, cc + 1, dr, dc, psf + "r");
		arr[cr][cc] = 0; // make for revisit it
		
	}

}
