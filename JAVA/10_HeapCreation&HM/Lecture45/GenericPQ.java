package Lecture45;

import java.util.*;

public class GenericPQ {

    private static class PriorityQueue<T extends Comparable<T>>{

        private ArrayList<T> list = new ArrayList<>();

        private void upheapify(int idx){
            if(idx == 0)
            {
                return;
            }
            int ci = idx;
            int pi = (ci - 1) / 2;
            if(list.get(ci).compareTo(list.get(pi)) < 0)
            {
                swap(ci,pi);
                upheapify(pi);
            }
        }

        private void downheapify(int idx){
            int minidx = idx;
            int lci = 2 * idx + 1;
            int rci = 2 * idx + 2;

            if(lci < list.size() && list.get(lci).compareTo(list.get(minidx)) < 0)
            {
                minidx = lci;
            }
                if( rci < list.size() && list.get(rci).compareTo(list.get(minidx)) < 0)
            {
                minidx = rci;
            }
            
            if(minidx != idx){
                swap(minidx, idx);
                downheapify(minidx);
            }
        }

        private void swap(int i, int j){
            T ith = list.get(i);
            T jth = list.get(j);
            list.set(j, ith);
            list.set(i, jth);
        }
        
        public void add(T data){
            list.add(data);
            upheapify(list.size() - 1);
        }

        public void remove(){
            swap(0, list.size() - 1);
            list.remove(list.size() - 1);
            downheapify(0);
        }

        public T peek(){
            return list.get(0);
        }

        public int size(){
            return list.size();
        }
    }
    
    public static class Car implements Comparable<Car>{
        int speed;
        int price;
        String name;

        Car(int speed, int price, String name){
            this.name = name;
            this.price = price;
            this.speed = speed;
        }

        public void display(){
            System.out.println(price + " " + speed + " " + name);
        }

        public int compareTo(Car other){
            return this.speed - other.speed;
        }
    }
    

    
    public static void main(String[] args) {
        
       /* PriorityQueue<Integer> pq = new PriorityQueue();
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
        System.out.println(); */

        PriorityQueue<Car> pq = new PriorityQueue<>();
        Car c1 = new Car(100, 1000, "A");
        Car c2 = new Car(159, 5000, "B");
        Car c3 = new Car(400, 200, "C");
        Car c4 = new Car(320, 7500, "D");
        Car c5 = new Car(145, 8800, "E");

        pq.add(c1);
        pq.add(c2);
        pq.add(c3);
        pq.add(c4);
        pq.add(c5);

        while(pq.size() > 0){
            Car c = pq.peek();
            pq.remove();
            c.display();
        }

        
    }    
}