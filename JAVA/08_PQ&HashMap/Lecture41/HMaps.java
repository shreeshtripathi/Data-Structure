package Lecture41;

import java.util.*;

public class HMaps<K, V> {
	// Private section
	private class Pair {
		K key;
		V value;
		
		Pair(K key, V value){
			this.key = key;
			this.value = value;
		}
	}
	
	private LinkedList<Pair>[] buckets;
	
	private int size = 0;
	
	private int hashFunction(K key) {
		int hc = key.hashCode();
		int bi =  Math.abs(hc) % buckets.length;
		return bi;
	}
	
	private int findWithinBucket(K key, int bi) {
		int di = 0;
		for(Pair p : buckets[bi]) {
			if(p.key.equals(key)) {
				return di;
			}
			di++;
		}
		return -1;
	}
	
	@SuppressWarnings("unchecked")
	private void rehash() {
		LinkedList<Pair>[] obuckets = buckets;
		buckets = new LinkedList[obuckets.length * 2];
		size = 0;
		for(int i = 0; i < buckets.length; i++) {
			buckets[i] = new LinkedList<Pair>();
		}
		
		for(int i = 0; i < obuckets.length; i++) {
			for(Pair p : obuckets[i]) {
				put(p.key, p.value);
			}
		}
	}
	
	// Public section
	@SuppressWarnings("unchecked")
	public HMaps() {
		buckets = new LinkedList[4];
		for(int i = 0; i < buckets.length; i++) {
			buckets[i] = new LinkedList<Pair>();
		}
		size = 0;
	}
	
	public boolean containsKey(K key) {
		int bi = hashFunction(key);
		int di = findWithinBucket(key, bi);
		
		if(di == -1) {
			return false;
		} else {
			return true;
		}
	}
	
	public void put(K key, V value) {
		int bi = hashFunction(key);
		int di = findWithinBucket(key, bi);
		if(di == -1) {
			Pair p2a = new Pair(key, value); // p2a = pair to add
			buckets[bi].add(p2a);
			size++;
		} else {
			Pair p2u = buckets[bi].get(di); // p2u = pair to update
			p2u.value = value;
		}
		
		double lambda = size * 1.0 / buckets.length;
		if(lambda > 2.0) {
			rehash();
		}
	}
	
	public V remove(K key) {
		int bi = hashFunction(key);
		int di = findWithinBucket(key, bi);
		if(di == -1) {
			return null;
		} else {
			Pair rem = buckets[bi].remove(di);
			size--;
			return rem.value;
		}
	}
	
	public V get(K key) {
		int bi = hashFunction(key);
		int di = findWithinBucket(key, bi);
		
		if(di == -1) {
			return null;
		} else {
			Pair p = buckets[bi].get(di);
			return p.value;
		}
	}
	
	public ArrayList<K> keySet() {
		ArrayList<K> keys = new ArrayList<>();
		for(int i = 0; i < buckets.length; i++) {
			for(Pair p : buckets[i]) {
				keys.add(p.key);
			}
		}
		return keys;
	}
	
	public void display() {
		System.out.println("---------------------------------------");
		for(int i = 0; i < buckets.length; i++) {
			System.out.print("bucket " + i + ":");
			for(Pair p : buckets[i]) {
				System.out.print("[" + p.key + "->" + p.value + "] ");
			}
			System.out.println();
		}
		System.out.println("---------------------------------------");
	}
}
