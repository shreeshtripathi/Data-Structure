package Lecture38;

public class sparse {

    static int[][] st;
    static int[] oa;

    private static void preprocess() {
        int col = getLog(oa.length) + 1;
        int row = oa.length;
        st = new int[row][col];
        for (int j = 0; j < col; j++) {
            // in row, control the loop for action
            for (int i = 0; i <= row - (1 << j); i++) {
                if (j == 0) {
                    st[i][j] = oa[i];
                } else {
                    st[i][j] = Math.min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
                }
            }
        }
    }

    private static int query(int l, int r) {
        int n = r - l + 1;
        int log = getLog(n);

        // make two factors to handle all case
        int f1 = st[l][log];
        int f2 = st[r - (1 << log) + 1][log];

        return Math.min(f1, f2);

    }

    private static int getLog(int n) {// it return floor of log(n) base 2;
        int log = 0;
        while (1 << log <= n) {
            log++;
        }

        return log - 1;
    }

    public static void main(String[] args) {
        oa = new int[16];
        for (int i = 0; i < oa.length; i++) {
            oa[i] = (int) (10 * Math.random()) + 3;
            System.out.println(oa[i] + "  " + i);
        }

        preprocess();
        System.out.println("~~~~~~~~~~~~~~~~");

        System.out.println(0 + " to " + 5 + " " + query(0, 5));
        System.out.println(5 + " to " + 6 + " " + query(5, 6));
        System.out.println(7 + " to " + 14 + " " + query(7, 14));
        System.out.println(2 + " to " + 15 + " " + query(2, 15));

    }

}