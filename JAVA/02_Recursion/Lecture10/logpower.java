package Lecture10;

public class logpower {

	public static void main(String[] args) {
		int val = power(5,4);
		System.out.println(val);
	}
	public static int power(int num, int pow) {
		if(pow == 0) {
			return 1;
		}
		int half = power(num, pow/2);
		if(pow % 2 == 1) {
			return num * half * half;
		}
		return half * half;
		//Warning
//		fake better
//		if(pow % 2 == 0) {
//			return power(num, pow / 2) * power(num, pow / 2);
		
		//this is not a good approach
		//because of 2 calls
//		}
	}

}
