package Lecture11;
import java.util.*;
public class arrayList {

	public static void main(String[] args) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(10);
		list.add(20);
		list.add(2,30);
		int l = list.size();
		System.out.println(list.get(1));
		System.out.println(l);
		System.out.println(list);
		list.set(1, 500);
		System.out.println(list);
	}

}
