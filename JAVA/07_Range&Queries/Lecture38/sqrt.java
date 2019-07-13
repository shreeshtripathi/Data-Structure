package Lecture38;
import java.util.*;

public class sqrt {
    static int[] oa;
    static int[] sa;

    static int sb;
    static int cb;

    private static void preprocess() {

    }

    private static int query(int lo, int hi) {
    	return 0;
    }

    private static int update(int idx, int nval) {
        int oval = oa[idx];
        oa[idx] = nval;

     // yaha se aage
        
        return 0;
    }

    private static int queryTest(int lo, int hi){
        int sum = 0;
        for(int i = lo; i <= hi; i++){
            sum += oa[i];
        }
        return sum;
    }

    public static void main(String[] args) {

    }

}