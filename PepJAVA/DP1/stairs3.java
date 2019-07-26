import javax.lang.model.util.ElementScanner6;

public class stairs3 {

    // static int min = Integer.MAX_VALUE;
    // static int minPath = 0;

    static int stairways(int n, int[] steps, int[] qb) {

        if (n == 0) {
            return 1;
        } else if (n < 0) {
            return 0;
        }
        if (qb[n] != 0) {
            return qb[n];
        }
        int ways = 0;
        for (int i = 1; i <= steps[n]; i++) {
            ways += stairways(n - i, steps, qb);
        }

        qb[n] = ways;
        return ways;
    }


    static int climbStairsTab(int[] steps) {
        // Assign Storage and assign meaning to it
        int[] strg = new int[steps.length];
        strg[0] = 1;
        for (int s = 1; s < steps.length; s++) {
            // s = source
            for (int js = 1; js <= steps[s]; js++) {
                int i = s - js;
                if (i >= 0) {
                    // travel and calculate    
                    strg[s] += strg[i];
                } else {
                    break;
                }
            }
        }
        return strg[strg.length - 1];
    }

    static int minJumpCount(int[] steps){
        int[] strg = new int[steps.length];
        strg[0] = 0;

        for(int s = 1; s < steps.length; s++){
            if(steps[s] == 0){
                strg[s] = -1;
                continue;
            }
            int min = Integer.MAX_VALUE;
            for(int js = 1; js <= steps[s]; js++){
                int i = s - js;
                if(i >= 0 && strg[i] != -1){
                    min = Math.min(min, strg[i]);
                }
            }
            if(min != Integer.MAX_VALUE){
                strg[s] = min + 1;
            } else{
                strg[s] = -1;
            }
        }

        return strg[strg.length - 1];
    }

    public static void main(String[] args) {
        int[] steps = { 0, 2, 3, 1, 0, 2, 0, 2, 4 };
        int n = 8;
        int[] qb = new int[n + 1];
        // System.out.println(stairways(n, steps, qb));

        System.out.println(climbStairsTab(steps));

        System.out.println(minJumpCount(steps));

    }
}