
public class climbStairs2 {
    

    static int stairs(int n, int[] qb){

        if(n == 0){
            return 1;
        }
        else if(n < 0){
            return 0;
        }

        if(qb[n] != 0){
            return qb[n];
        }

        int ways = 0;

        int ways1 = stairs(n - 1, qb);
        int ways2 = stairs(n - 2, qb);
        int ways3 = stairs(n - 3, qb);

        ways = ways1 + ways2 + ways3;
        return ways;

    }

    public static void main(String[] args) {
        int n = 7;
        int[] qb = new int[n + 1];
        System.out.println(stairs(7, qb));
    } 
}