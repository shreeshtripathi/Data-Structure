package Lecture39;

public class stree{
    static int[] ba;
    static int [] sa;

    private static void preprocess(){
        int h = (int)Math.ceil(ba.length) + 1;
        int sz = (1 << h) - 1;
        sa = new int[sz];
        build(0, sa.length - 1, 0);
    }

    private static int getLog(int n){
        int log = 0;
        while((1 << log) < n){
            log++;
        }
        return log;
    }

    private static void build(int ss, int se, int si){
        if(ss == se){
            sa[si] = ba[ss];
            return;
        }
        int mid = (ss + se) / 2;
        build(ss, mid, 2 * si + 1);
        build(mid + 1, se, 2 * si + 2);
        sa[si] = sa[2 * si + 1] + sa[2 * si + 2];
    }

    private static void update(int idx, int nval, int ss, int se, int si){
        if(ss == se){
            sa[si] = nval;
            ba[ss] = nval;
        }
        int mid = (ss + se) / 2;
        if(idx > mid){
            update(idx, nval, mid + 1, se, 2 * si + 2);
        } else {
            update(idx, nval, ss, mid, 2 * si + 1);
        }
        sa[si] = sa[2 * si + 1] + sa[2 * si + 2];
    }

    private static int query(int qs, int qe, int ss,int se, int si){
        if(qs <= ss && qe >= se){
            return sa[si];
        }
        else if(se < qs || qe < ss){
            return 0;
        }
        else {
            int mid = (ss + se) / 2;
            int lc = query(qs, qe, ss, mid, 2 * si + 1);
            int rc = query(qs, qe, mid + 1, se, 2 * si + 2);
            return lc + rc;
        }
    }

    private static void display(){
        for(int i = 0; i < sa.length; i++){
            System.out.print(sa[i] + " ");
        }
        System.out.println();
    }



    public static void main(String[] argv){
        ba = new int[]{1, 2, 3, 4, 5, 6, 7};
        preprocess();
        display();
    }
}