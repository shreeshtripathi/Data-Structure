package Lecture45;

import java.util.*;

public class HashMap {
    // assuming key is int, value is string

    class HMNode{
        Integer key;
        String value;
        HMNode(int key, String value){
            this.key = key;
            this.value = value;
        }
    }

    private LinkedList<HMNode>[] buckets;

    private int size;

    private void initbucket(int nob){
        size = 0;
        buckets = new LinkedList[nob];

        for(int i = 0; i < buckets.length; i++){
            buckets[i] = new LinkedList<>();
        }
    }

    private int hashfn(Integer key){
        int hc = key;
        int bi = Math.abs(hc) % buckets.length;
        return bi;
    }

    private int findWithinbucket(int bi, Integer key){
        for(int di = 0; di < buckets[bi].size(); di++){
            HMNode node = buckets[bi].get(di);
            if(node.key.equals(key)){
                return di;
            }
        }

        return -1;
    }

    private void rehash(){
        int onob = buckets.length;
        LinkedList<HMNode>[] obuckets = buckets;

        initbucket(2 * onob);

        for(int bi = 0; bi < onob; bi++){
            for(int di = 0; di < obuckets[bi].size(); di++){
                HMNode node=obuckets[bi].get(di);
                put(node.key, node.value);
            }
        }
    }
    HashMap(){
        initbucket(4);
        size = 0;
    }

    public void put(Integer key, String value){
        int bi = hashfn(key);
        int di = findWithinbucket(bi, key);
        if(di == -1){
            HMNode node = new HMNode(key, value);
            buckets[bi].addLast(node);
            size++;
            double lambda = size * 1.0 / buckets.length;
            if(lambda > 2.0){
                rehash();
            }
        } 
        else{
            HMNode node = buckets[bi].get(di);
            node.value = value;
        }
    }

    public String get(Integer key){
        int bi = hashfn(key);
        int di = findWithinbucket(bi, key);
        if(di == -1){
            return null;
        }
        else{
            HMNode node =  buckets[bi].get(di);
            return node.value;
        }
    }

    public String remove(Integer key){
        int bi = hashfn(key);
        int di = findWithinbucket(bi, key);
        if(di == -1){
            return null;
        }
        else{
            String value = buckets[bi].get(di).value;
            buckets[bi].remove(di);
            size--;
            return value;
        }
    }

    public boolean containsKey(Integer key){
        int bi = hashfn(key);
        int di = findWithinbucket(bi, key);
        if(di == -1){
            return false;
        }
        else{
            return true;
        }
    }

    public ArrayList<Integer> keyset(){
        ArrayList<Integer> keys = new ArrayList<>();
        for(int bi = 0; bi < buckets.length; bi++){
            for(int di = 0; di < buckets[bi].size(); di++){
                keys.add(buckets[bi].get(di).key);
            }
        }
        return keys;
    }

    public void display(){
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        for(int bi = 0; bi < buckets.length; bi++){
            System.out.print("b" + bi + " -> ");
            for(int di = 0; di < buckets[bi].size(); di++){
                HMNode node = buckets[bi].get(di);
                System.out.print("[" + node.key + ", " + node.value + "], ");
            }
            System.out.println(".");
        }
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }



    public static void main(String[] args){
        HashMap map = new HashMap();
        map.put(1, "a");
        map.put(2, "b");
        map.put(3, "c");
        map.put(4, "d");
        map.put(5, "e");
        map.put(6, "f");
        map.put(7, "g");
        map.put(8, "h");
        map.display();

        map.put(9, "i");
        map.display();
    }
    
}