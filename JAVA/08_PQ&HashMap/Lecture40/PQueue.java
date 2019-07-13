package Lecture40;

import java.util.*;

public class PQueue{

    private static void printSmallestNum(int[] arr, int k){
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i = 0; i < arr.length; i++){
            pq.add(arr[i]);
        }

        for(int i = 0; i < k; i++){
            int val = pq.peek();
            pq.remove();
            System.out.print(val + " ");
        }
        System.out.println();
    }

    private static void printSmallestNum2(int[] arr, int k){
        
    }

    public static void main(String[] args){
        int[] arr = new int[]{10, 15, 2, 17, 7, 18, 22, 9, 3};
        printSmallestNum(arr, 4);
    }
}