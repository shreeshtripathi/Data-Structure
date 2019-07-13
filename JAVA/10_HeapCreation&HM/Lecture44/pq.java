package Lecture44;

import java.util.*;

public class pq {

    private static class PriorityQueue{

        private static ArrayList<Integer> list = new ArrayList<>();

        private void upheapify(int idx){
            if(idx == 0)
            {
                return;
            }
            int ci = idx;
            int pi = (ci - 1) / 2;
            if(list.get(ci) < list.get(pi))
            {
                swap(ci,pi);
                upheapify(pi);
            }
        }

        private void downheapify(int idx){
            int minidx = idx;
            int lci = 2 * idx + 1;
            int rci = 2 * idx + 2;

            if(lci < list.size() && list.get(lci) < list.get(minidx))
            {
                minidx = lci;
            }
                if( rci < list.size() && list.get(rci) < list.get(minidx))
            {
                minidx = rci;
            }
            
            if(minidx != idx){
                swap(minidx, idx);
                downheapify(minidx);
            }
        }

        private void swap(int i, int j){
            int ith = list.get(i);
            int jth = list.get(j);
            list.set(j, ith);
            list.set(i, jth);
        }
        
        public void add(int data){
            list.add(data);
            upheapify(list.size() - 1);
        }

        public void remove(){
            swap(0, list.size() - 1);
            list.remove(list.size() - 1);
            downheapify(0);
        }

        public int peek(){
            return list.get(0);
        }

        public int size(){
            return list.size();
        }
    }
    
    
    public static void main(String[] args) {
        PriorityQueue pq = new PriorityQueue();
        pq.add(10);
        pq.add(20);
        pq.add(15);
        pq.add(50);
        pq.add(37);
        pq.add(45);
        pq.add(5);

        while(pq.size() > 0){
            int val = pq.peek();
            pq.remove();
            System.out.print(val + " ");
        }
        System.out.println();
    }    
}