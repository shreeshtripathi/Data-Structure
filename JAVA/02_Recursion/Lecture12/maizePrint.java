package Lecture12;

public class maizePrint {

	public static void main(String[] args) {
	//	pmp1(0, 0, 3, 3, "");
		pmp2(0, 0, 2, 2, "");
	}

	public static void pmp1(int cr, int cc, int dr, int dc, String psf) {
		if(cr == dr && cc == dc) {
			System.out.println(psf);
		}
		if(cr > dr || cc > dc) {
			return;
		}
		
		pmp1(cr, cc + 1, dr, dc, "v" + psf);
		pmp1(cr +1, cc, dr, dc, "h" + psf);
	}

	public static void pmp2(int cr, int cc, int dr, int dc, String psf) {
		if(cr == dr && cc == dc) {
			System.out.println(psf);
			return;
		}
		for(int i = 1; i <= dc -cc; i++) {
			pmp2(cr, cc + i, dr, dc, psf + "h" + i);
		}
		for(int i = 1; i <= dr -cr; i++) {
			pmp2(cr + i, cc, dr, dc,psf +  "v" + i);
		}
		for(int i = 1; i <= dc -cc && i <= dr - cr; i++) {
			pmp2(cr + i, cc + i, dr, dc,psf + "d" + i);
		}
	}

}
