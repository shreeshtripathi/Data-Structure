package Lecture41;

public class hmdemo {

	static void demo() {
		HMaps<String, Integer> hm = new HMaps<>();
		hm.put("Shreesh", 20);
		hm.put("Manisha", 22);
		hm.put("Pawan", 25);
		hm.put("Prakash", 22);
		hm.put("Prashant", 23);
		hm.put("Rohit", 21);
		hm.put("Mona", 19);
		hm.display();
//		hm.put("Mona", 20);
//		System.out.println(hm.remove("Prashant"));
//		System.out.println(hm.remove("Prashan"));
		hm.put("sameer", 15);
		hm.put("khyati", 20);
		hm.put("sona", 20);
		hm.display();
		System.out.println(hm.get("Prashant"));
		System.out.println(hm.get("Prasha"));
		System.out.println(hm.keySet());
	}
	
	public static void main(String[] args) {
		demo();
	}

}
