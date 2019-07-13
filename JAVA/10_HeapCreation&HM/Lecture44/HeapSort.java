package Lecture44;

//import java.util.*;

public class HeapSort {

    public static void swap(int[] arr, int i, int j){
        int ith = arr[i];
        int jth = arr[j];
        arr[i] = jth;
        arr[j] = ith;
    }

    public static void downheapify(int[] arr, int idx, int sz){
        int lci = 2 * idx + 1;
        int rci = 2 * idx + 2;

        int maxidx = idx;

        if(lci < sz && arr[maxidx] < arr[lci]){
            maxidx = lci;
        }
        if(lci < sz && arr[maxidx] < arr[rci]){
            maxidx = rci;
        }
        if(maxidx != idx){
            swap(arr, maxidx, idx);
            downheapify(arr, maxidx, sz);
        }
    }

    public static void heapSort(int[] arr){
        // make a priority queue from call down heapify from len/2 - 1
        for(int i = arr.length / 2 - 1; i >= 0; i--){
            downheapify(arr, i, arr.length - 1);
        }

        int cse = 0; // current sorted element is now 0
        while(cse < arr.length - 1){
            swap(arr, 0, arr.length - 1 - cse);
            cse++;
            downheapify(arr, 0, arr.length - cse);
        }

    }

    public static void main(String[] args) {
        int[] arr = {9, 8, 7, 4, 6, 5, 3, 2, 1};
        heapSort(arr);

        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }    
}