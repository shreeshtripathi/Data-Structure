import java.util.*;

public class Graph {

    static class Edge {
        int n;
        int wt;

        Edge(int n, int wt) {
            this.n = n;
            this.wt = wt;
        }
    }

    static void addEdge(ArrayList<ArrayList<Edge>> graph, int v1, int v2, int wt) {
        graph.get(v1).add(new Edge(v2, wt));
        graph.get(v2).add(new Edge(v1, wt));
    }

    static void display(ArrayList<ArrayList<Edge>> graph) {
        System.out.println("-----------------------------");
        for (int v = 0; v < graph.size(); v++) {
            System.out.print(v + "->");
            for (int n = 0; n < graph.get(v).size(); n++) {
                Edge ne = graph.get(v).get(n);
                System.out.print("[" + ne.n + "-" + ne.wt + "], ");
            }
            System.out.println();
        }
        System.out.println("-----------------------------");
    }

    static boolean hasPath(ArrayList<ArrayList<Edge>> graph, int src, int dest, boolean[] visited) {
        
        if (src == dest) {
            return true;
        }

        visited[src] = true;
        for (int n = 0; n < graph.get(src).size(); n++) {
            
            Edge ne = graph.get(src).get(n);

            if (visited[ne.n] == false) {
                if (hasPath(graph, ne.n, dest, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    static void printAllPath(ArrayList<ArrayList<Edge>> graph, int src, int dest, boolean[] visited, String psf, int pd){
        if (src == dest) {
            System.out.println(psf + " " + src + " @ " + pd);
            return;
        }

        visited[src] = true;
        for (int n = 0; n < graph.get(src).size(); n++) {
            
            Edge ne = graph.get(src).get(n);

            if (visited[ne.n] == false) {
                printAllPath(graph, ne.n, dest, visited, psf + " " + src, pd + ne.wt);
            }
        }
        visited[src] = false;
    }

    // if we mark to the one step ahead that is we include neighbour
    static void printAllPath_Inc(ArrayList<ArrayList<Edge>> graph, int src, int dest, boolean[] visited, String psf, int pd){
        if (src == dest) {
            System.out.println(psf + "  @ " + pd);
            return;
        }

        
        for (int n = 0; n < graph.get(src).size(); n++) {
            
            Edge ne = graph.get(src).get(n);

            if (visited[ne.n] == false) {
                visited[ne.n] = true;
                printAllPath(graph, ne.n, dest, visited, psf + " " + ne.n, pd + ne.wt);
                visited[ne.n] = false;
            }
        }
        
    }

    static class mnHelper{
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        String mnpath;
        String mxpath;
    }

    static void MinMax(ArrayList<ArrayList<Edge>> graph, int src,
                     int dest, String psf, boolean[] visited, int pd, mnHelper mn){
        if(src == dest){
            if(mn.min > pd){
                mn.min = pd;
                mn.mnpath = psf + " " + src;
            }
            if(mn.max < pd){
                mn.max = pd;
                mn.mxpath = psf + " " + src;
            }
            return;
        }

        visited[src] = true;
        for(int n = 0; n < graph.get(src).size(); n++){
            Edge ne = graph.get(src).get(n);
            if(visited[ne.n] == false){
                MinMax(graph, ne.n, dest, psf + " " + src, visited, pd + ne.wt, mn);
            }
        }
        visited[src] = false;
    }

    static class cfHelper{
        int ceil = Integer.MAX_VALUE;
        int floor = Integer.MIN_VALUE;
        String cpath = "";
        String fpath = "";
    }

    static void ceilFloor(ArrayList<ArrayList<Edge>> graph, int src, int dest,
                 boolean[] visited, String psf, int pd, cfHelper cf, int factor){
        
                    if(src == dest){
            // ceil = qualified min
            if(pd > factor && cf.ceil > pd){
                cf.ceil = pd;
                cf.cpath = psf + " " + src;
            }
            // floor = qualified max
            if(pd < factor && cf.floor < pd){
                cf.floor = pd;
                cf.fpath = psf + " " + src;
            }
            return;
        }

        visited[src] = true;
        for(int n = 0; n < graph.get(src).size(); n++){
            Edge ne = graph.get(src).get(n);

            if(visited[ne.n] == false){
                ceilFloor(graph, ne.n, dest, visited, psf + " " +src, pd + ne.wt, cf, factor);
            }
        }
        visited[src] = false;
    }

    static class kLarge implements Comparable<kLarge>{
        int pd;
        String psf;

        public int compareTo(kLarge o){
            return this.pd - o.pd;
        }

        kLarge(int pd, String psf){
            this.pd = pd;
            this.psf = psf;
        }
    }

    //~~~~~~~~~~~~~~~~~~~~~~~Kth Largest from the concept of Priority Queue~~~~~~~~~~~~~~~
    static PriorityQueue<kLarge> pq = new PriorityQueue<>(Collections.reverseOrder());

    static void KthLargest(ArrayList<ArrayList<Edge>> graph, int src, 
                        boolean[] visited, int dest, String psf, int dsf){

        if(src == dest){
            psf =psf + " " + src;
            pq.add(new kLarge(dsf, psf));
            return;
        }

        visited[src] = true;
        for(int n = 0; n < graph.get(src).size(); n++){
            Edge ne = graph.get(src).get(n);
            if(visited[ne.n] == false){
                KthLargest(graph, ne.n, visited, dest, psf + " " + src, dsf + ne.wt);
            }
        }
        visited[src] = false;
    }

    static void kLargest(ArrayList<ArrayList<Edge>> graph, int src, 
             int dest, String psf, int dsf, int k){
        boolean[] visited = new boolean[7];
        KthLargest(graph, src, visited, dest, psf, dsf);
        if(pq.size() < k){
            System.out.println("No " + k + " paths are available");
            return;
        }
        for(int i = 0; i < k - 1; i++){
            pq.remove();
        }
        kLarge kl = pq.peek();
        System.out.println(kl.psf + " @ " + kl.pd);
    }

    //~~~~~~~~~~~~~~~~~~~~~~Kth Largest pq End here~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    static void kLarge_fromCeil(ArrayList<ArrayList<Edge>> graph, int src, int dest,
            int k){
        
        int limits = Integer.MAX_VALUE;
        boolean[] visited = new boolean[graph.size()];
        
        int pd = 0;
        String psf = "";
        for(int i = 0; i < k; i++){
            cfHelper kl = new cfHelper();
            ceilFloor(graph, src, dest, visited, "", 0, kl, limits);
            pd = kl.floor;
            psf = kl.fpath;
            limits = pd;
        }

        System.out.println(psf + " " + pd);
        
    }

    //Date : 26th May 2019

    static class THelper{
        int v;
        String psf;
        int dsf;

        THelper(int v, String psf, int dsf){
            this.v = v;
            this.psf = psf;
            this.dsf = dsf;
        }
    }

    static boolean bfs(ArrayList<ArrayList<Edge>> graph, int src, int dest){
        LinkedList<THelper> queue = new LinkedList<>();
        queue.addLast(new THelper(src,"" + src,0));
        boolean[] visited = new boolean[7];
        while(queue.size() > 0){
            //grmwc
            THelper rem = queue.getFirst();
            queue.removeFirst();

            System.out.println(rem.v + " via " + rem.psf + " @ " + rem.dsf);
            if(visited[rem.v] == true){
                continue;
            }
            else{
                visited[rem.v] = true;
            }

            if(rem.v == dest){
                return true;
            }

            for(int n = 0; n < graph.get(rem.v).size(); n++){
                Edge nbr = graph.get(rem.v).get(n);
                if(visited[nbr.n] == false){
                    queue.addLast(new THelper(nbr.n, rem.psf + " " + nbr.n, rem.dsf + nbr.wt));
                }
            }
        }        

        return false;
    }

    static class fireHelper{
        int i;
        int j;
        int t;
        fireHelper(int i, int j, int t){
            this.i = i;
            this.j = j;
            this.t = t;
        }
    }

    static boolean isValid(int[][] city, int i, int j){
        if(i < 0 || i >= city.length || j < 0 || j >= city[0].length){
            return false;
        }
        else if(city[i][j] == -1){
            return false;
        }
        else if(city[i][j] >= 0){
            return false;
        }
        else{
            return true;
        }
    }

    static void fire_in_city(int[][] city){
        LinkedList<fireHelper> queue = new LinkedList<>();
        for(int i = 0; i < city.length; i++){
            for(int j = 0; j < city[i].length; j++){
                if(city[i][j] == 0){
                    queue.addLast(new fireHelper(i, j, 0));
                }
            }
        }

        while(queue.size() > 0){
            fireHelper rem = queue.getFirst();

            queue.removeFirst();

            
            if(city[rem.i][rem.j] > 0){
                continue;
            }
            else{
                city[rem.i][rem.j] = rem.t;
            }

            System.out.println(rem.i + "" + rem.j + " Burn at " + rem.t);

            if(isValid(city, rem.i + 1, rem.j))
                queue.addLast(new fireHelper(rem.i + 1, rem.j, rem.t + 1));
            if(isValid(city, rem.i - 1, rem.j))
                queue.addLast(new fireHelper(rem.i - 1, rem.j, rem.t + 1));
            if(isValid(city, rem.i, rem.j + 1))
                queue.addLast(new fireHelper(rem.i, rem.j + 1, rem.t + 1));
            if(isValid(city, rem.i, rem.j - 1))
                queue.addLast(new fireHelper(rem.i, rem.j - 1, rem.t + 1));
        }
    }

    static String getConnectedComp(ArrayList<ArrayList<Edge>> graph, int src,
            boolean[] visited){
        LinkedList<Integer> queue = new LinkedList<>();
        String comp = "";
        queue.addLast(src);

        while(queue.size() > 0){
            int rem = queue.getFirst();
            queue.removeFirst();

            if(visited[rem] == true){
                continue;
            }
            else{
                visited[rem] = true;
            }

            comp = comp + rem;
            for(int n = 0; n < graph.get(rem).size(); n++){
                Edge ne = graph.get(rem).get(n);
                if(visited[ne.n] == false){
                    queue.addLast(ne.n);
                }
            }
        }
        return comp;
    }

    static ArrayList<String> getConnectedComponets(ArrayList<ArrayList<Edge>> graph){
        ArrayList<String> comps = new ArrayList<>();
        boolean[] visited = new boolean[graph.size()];

        for(int v = 0; v < graph.size(); v++){
            if(visited[v] == false){
                String comp = getConnectedComp(graph, v, visited);
                comps.add(comp);
            }

        }
        return comps;
    }

    static boolean isValid4I(int[][] mat, int i, int j){
        if(i < 0 || i >= mat.length || j < 0 || j >= mat[0].length)
            return false;
        else if(mat[i][j] == -1)
            return false;
        else if(mat[i][j] > 0)
            return false;
        else 
            return true;
    }

    static class Ihelper{
        int i;
        int j;
        Ihelper(int i, int j){
            this.i = i;
            this.j = j;
        }
    }

    static String getIsLandComp(int[][] mat,int i,int j, int count){
        LinkedList<Ihelper> queue = new LinkedList<>();
        String land = "";
        queue.addLast(new Ihelper(i, j));
        while(queue.size() > 0){
            Ihelper rem = queue.getFirst();
            queue.removeFirst();

            if(mat[rem.i][rem.j] > 0){
                continue;
            }
            else
            {
                mat[rem.i][rem.j] = count + 1;
            } 
            land = land + "(" + rem.i + "," +  rem.j+ ")";

            if(isValid4I(mat, rem.i + 1, rem.j))
                queue.addLast(new Ihelper(rem.i + 1, rem.j));
            if(isValid4I(mat, rem.i - 1, rem.j))
                queue.addLast(new Ihelper(rem.i - 1, rem.j));
            if(isValid4I(mat, rem.i, rem.j + 1))
                queue.addLast(new Ihelper(rem.i, rem.j + 1));
            if(isValid4I(mat, rem.i, rem.j - 1))
                queue.addLast(new Ihelper(rem.i, rem.j - 1));
            
        }
        return land;
    }

    static int island(int[][] mat){
        int count = 0;
        ArrayList<String> lands = new ArrayList<>();
        for(int i = 0; i < mat.length; i++){
            for(int j = 0; j < mat[i].length; j++){
                if(mat[i][j] == 0){
                    String land = getIsLandComp(mat, i, j, count);
                    lands.add(land);
                    count++;
                }
            }
        }

        for(int i = 0; i < mat.length; i++){
            for(int j = 0; j < mat[i].length; j++){
                if(mat[i][j] == -1)
                System.out.print("X ");
                else
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println(lands);
        return count;
    }


    // 27th May 2019

    public static boolean detectCycle(ArrayList<ArrayList<Edge>> graph,
                    int src, boolean[] visited){
        LinkedList<Integer> queue = new LinkedList<>();
        queue.add(src);

        while(queue.size() > 0){
            int rem = queue.getFirst();
            queue.removeFirst();

            if(visited[rem] == true){
                return true;
            }
            visited[rem] = true;

            for(int n = 0; n < graph.get(rem).size(); n++){
                Edge ne = graph.get(rem).get(n);
                if(visited[ne.n] == false){
                    queue.add(ne.n);
                }
            }
        }
        return false;
    }

    public static boolean isCyclic(ArrayList<ArrayList<Edge>> graph){
        boolean[] visited = new boolean[graph.size()];
        
        for(int v = 0; v < graph.size(); v++){
            if(visited[v] == false){
                boolean res = detectCycle(graph, v, visited);
                if(res == true){
                    return true;
                }
            }
        }
        return false;
    }

    static ArrayList<Integer> getAstro(ArrayList<ArrayList<Edge>> astr, int src,
        boolean[] visited){
        LinkedList<Integer> queue = new LinkedList<>();
        ArrayList<Integer> list = new ArrayList<>();

        queue.add(src);

        while(queue.size() > 0){
            int rem = queue.getFirst();
            queue.removeFirst();

            if(visited[rem] == true){
                continue;
            }
            else{
                visited[rem] = true;
            }
            list.add(rem);

            for(int n = 0; n < astr.get(rem).size(); n++){
                Edge ne = astr.get(rem).get(n);

                if(visited[ne.n] == false){
                    queue.add(ne.n);
                }
            }
        }
        return list;
    }

    static int astronautsCount(ArrayList<ArrayList<Edge>> astr){
        boolean[] visited = new boolean[astr.size()];
        ArrayList<ArrayList<Integer>> lists = new ArrayList<>();
        for(int v = 0; v < astr.size(); v++){
            if(visited[v] == false){
                ArrayList<Integer> list = getAstro(astr, v, visited);
                lists.add(list);
            }
        }
        System.out.println(lists);
        //print combinations and return count

        int num = 0;

        for(int i = 0; i < lists.size(); i++){
            for(int j = i + 1; j < lists.size(); j++){
                num += lists.get(i).size() * lists.get(j).size();
            }
        }

        return num;
    }

    static class bHelper{
        int v;
        int l;
        bHelper(int v, int l){
            this.v = v;
            this.l = l;
        }
    }
    static boolean bipertiteComp(ArrayList<ArrayList<Edge>> graph, int src,
        int[] visited){

        bHelper b = new bHelper(src, 0);
        LinkedList<bHelper> queue = new LinkedList<>();
        queue.addLast(b);

        while(queue.size() > 0){
            bHelper rem = queue.getFirst();
            queue.removeFirst();

            if(visited[rem.v] != -1){
                // check for bipertite
                if(visited[rem.v] != rem.l %2){
                    return false;
                }
                else{
                    continue;
                }
            }
            else{
                visited[rem.v] = rem.l % 2;
            }

            for(int n = 0; n < graph.get(rem.v).size(); n++){
                Edge ne = graph.get(rem.v).get(n);

                if(visited[ne.n] == -1){
                    queue.addLast(new bHelper(ne.n, rem.l + 1));
                }
            }

        }
        return true;
    }
    static boolean isBipertite(ArrayList<ArrayList<Edge>> graph){
        int[] visited = new int[graph.size()];
        Arrays.fill(visited, -1);
        for(int v = 0; v < graph.size(); v++){
            if(visited[v] == -1){
                boolean res = bipertiteComp(graph, v, visited);
                if(res == false){
                    return false;
                }
            }
        }
        return true;
    }


    // Date: 29th May 2019

    static class Dhelper implements Comparable<Dhelper>{
        int v;
        String psf;
        int dsf;

        Dhelper(int v, String psf, int dsf){
            this.v = v;
            this.psf = psf;
            this.dsf = dsf;
        }

        public int compareTo(Dhelper other){
            return this.dsf - other.dsf;
        }
    }

    static void djikstras(ArrayList<ArrayList<Edge>> graph, int src){
        PriorityQueue<Dhelper> pq = new PriorityQueue<>();
        pq.add(new Dhelper(src, "" + src, 0));
        
        boolean[] visited = new boolean[graph.size()];

        while(pq.size() > 0){
            Dhelper rem = pq.peek();
            pq.remove();

            if(visited[rem.v] == true){
                continue;
            }
            else{
                visited[rem.v] = true;
            }

            System.out.println(rem.v + " " + rem.psf + " @ " + rem.dsf);


            for(int n = 0; n < graph.get(rem.v).size(); n++){
                Edge ne = graph.get(rem.v).get(n);

                if(visited[ne.n] == false){
                    pq.add(new Dhelper(ne.n, rem.psf + ne.n, rem.dsf + ne.wt));
                }
            }
        }
    }

    static class primHelper implements Comparable<primHelper>{
        int v;
        int a;
        int d;

        primHelper(int v, int a, int d){
            this.v = v;
            this.a = a;
            this.d = d;
        }

        public int compareTo(primHelper other){
            return this.d - other.d;
        }
    }

    static ArrayList<ArrayList<Edge>> prims(ArrayList<ArrayList<Edge>> graph){
        
        ArrayList<ArrayList<Edge>> mst = new ArrayList<>();
        for(int i = 0; i < graph.size(); i++){
            mst.add(new ArrayList<>());
        }

        PriorityQueue<primHelper> pq = new PriorityQueue<>();
        boolean[] visited = new boolean[graph.size()];

        pq.add(new primHelper(0, -1, 0));

        while(pq.size() > 0){
            primHelper rem = pq.peek();
            pq.remove();

            if(visited[rem.v] == true){
                continue;
            }
            else{
                visited[rem.v] = true;
            }
            

            if(rem.a != -1){
                addEdge(mst, rem.v, rem.a, rem.d);
            }

            for(int n = 0; n < graph.get(rem.v).size(); n++){
                Edge ne = graph.get(rem.v).get(n);
                if(visited[ne.n] == false){
                    pq.add(new primHelper(ne.n, rem.v, ne.wt));
                }
            }
        }
        return mst;
    }

    static class KEdge implements Comparable<KEdge>{
        int v1;
        int v2;
        int wt;

        KEdge(int v1, int v2, int wt){
            this.v1 = v1;
            this.v2 = v2;
            this.wt = wt;
        }

        public int compareTo(KEdge other){
            return this.wt - other.wt;
        }
    }

    //function which give set leader for keushkals
    static int findsl(int[] pa, int vtx){

        if(pa[vtx] == vtx){
            return vtx;
        }
        else{
            int sl = findsl(pa, pa[vtx]);
            return sl;
        }
    }

    // a function to merge set leader for krushkals
    static void mergesl(int[] pa, int[] ra, int v1sl, int v2sl){
        if(ra[v1sl] < ra[v2sl]){
            pa[v1sl] = v2sl;
        }
        else if(ra[v2sl] < ra[v1sl]){
            pa[v2sl] = v1sl;
        }
        else{
            pa[v1sl] = v2sl;
            ra[v1sl]++;
        }
    }


    static ArrayList<ArrayList<Edge>> krushkals(ArrayList<ArrayList<Edge>> graph){

        ArrayList<ArrayList<Edge>> mst = new ArrayList<>();
        PriorityQueue<KEdge> pq = new PriorityQueue<>();

        for(int i = 0; i < graph.size(); i++){
            mst.add(new ArrayList<>());
        }
        // pointer array
        int[] pa = new int[graph.size()];
        for(int i = 0; i < pa.length; i++){
            pa[i] = i;
        }
        // rank array
        int[] ra = new int[graph.size()];
        Arrays.fill(ra, 1);
        // fill priority queue from krushkals edge

        for(int v = 0; v < graph.size(); v++){
            for(int n = 0; n < graph.get(v).size(); n++){
                Edge ne = graph.get(v).get(n);
                if(v < ne.n){
                    KEdge ke = new KEdge(v, ne.n, ne.wt);
                    pq.add(ke);
                }
            }
        }

        // algo step
        int count = 0; // it doesnot impact the code's complexity
        while(pq.size() > 0 && count < graph.size() - 1){
            KEdge ke = pq.peek();
            pq.remove();
            
            int v1sl = findsl(pa, ke.v1);
            int v2sl = findsl(pa, ke.v2);

            if(v1sl != v2sl){
                addEdge(mst, ke.v1, ke.v2, ke.wt);
                mergesl(pa, ra, v1sl, v2sl);
                count++;
            }
            
        }

        return mst;
    } 

    static void hamiltoniun(ArrayList<ArrayList<Edge>> graph, int src,
                boolean[] visited, ArrayList<Integer> psf){
        if(psf.size() == graph.size() - 1){
            boolean isCyclic = false;
            int first = psf.get(0);
            int last = src;
            for(int n = 0; n < graph.get(src).size(); n++){
                if(graph.get(src).get(n).n == first){
                    isCyclic = true;
                }
            }

            if(isCyclic == true){
                System.out.print(psf);
                System.out.println(src + "*");
            }
            else{
                System.out.print(psf);
                System.out.println(src + ".");
            }
        }
        visited[src] = true;
        for(int n = 0; n < graph.get(src).size(); n++){
            Edge e = graph.get(src).get(n);
            if(visited[e.n] == false){
                psf.add(src);
                hamiltoniun(graph, e.n, visited, psf);
                psf.remove(psf.size() - 1);
            }
        }
        visited[src] = false;
    }

    static boolean isValidKnight(int[][] board, int x, int y){
        
        if(x < 0 || x >= board.length || y < 0 || y >= board.length){
            return false;
        }
        else if(board[x][y] != 0){
            return false;
        }
        else{
            return true;
        }
    }

    static int[] movex = {-2, -2, -1 ,1, 2, 2, 1, -1};
    static int[] movey = {1, -1, 2, 2, 1, -1, -2, -2};
    static int counter = 0;

    static void KnightsTour(int[][] board, int row, int col, int count){
        
        
        if(count == board.length * board.length - 1){
            counter++;
            board[row][col] = count + 1;
            System.out.println("~~~~~~~~~~" + counter + "~~~~~~~~~~~");
            for(int i = 0; i < board.length; i++){
                for(int j = 0; j< board.length; j++){
                    System.out.print(board[i][j] + "\t ");
                }
                System.out.println();
            }
            board[row][col] = 0;
            System.out.println("~~~~~~~~~~" + counter + "~~~~~~~~~~~");
            return;
        }
        
        board[row][col] = count + 1;
        for(int i = 0; i < movex.length; i++){
            if(isValidKnight(board, row + movex[i], col + movey[i])){
                KnightsTour(board, row + movex[i], col + movey[i], count + 1);
            }
        }

        board[row][col] = 0;
    }

    // Date: 30th May 2019

    static void floydWarshell(ArrayList<ArrayList<Edge>> graph){
        
        int[][] res = new int[graph.size()][graph.size()];

        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph.size(); j++){
                res[i][j] = Integer.MAX_VALUE;
            }
        }

        for(int i = 0; i < graph.size(); i++){
            res[i][i] = 0;
            for(int n = 0; n < graph.get(i).size(); n++){
                Edge ne = graph.get(i).get(n);
                res[i][ne.n] = ne.wt;
            }
        }

        // At t = 0; it have only neighbours or Direct Edge
        // at t = 1, it have all ways from single intermediate [sd, si1d]
        // at t = 2, it have all ways from two intermediates [sd, si1d, si2d, si1i2d*]
        // at t = 3, it have all ways from three intermediates ......

        for(int i = 0; i < graph.size(); i++){
            for(int s = 0; s < graph.size(); s++){
                for(int d = 0; d < graph.size(); d++){
                    if(s == d || i == s || i == d){
                        continue;
                    }
                    else if(res[s][i] == Integer.MAX_VALUE || res[i][d] == Integer.MAX_VALUE){
                        continue;
                    }
                    else{
                        if(res[s][i] + res[i][d] < res[s][d]){
                            res[s][d] = res[s][i] + res[i][d];
                        }
                    }
                }
            }
        }

        // display
        for(int i = 0; i < res.length; i++){
            for(int j = 0; j < res.length; j++){
                if(res[i][j] == Integer.MAX_VALUE)
                    System.out.print("X  ");
                else
                System.out.print(res[i][j] + "  ");
            }
            System.out.println();
        }
    }

    static class BEdge{
        int v1;
        int v2;
        int wt;

        BEdge(int v1, int v2, int wt){
            this.v1 = v1;
            this.v2 = v2;
            this.wt = wt;
        }
    }

    static void bellmanford(ArrayList<ArrayList<Edge>> graph, int src){
        ArrayList<BEdge> e = new ArrayList<>();
        // prepare a vector of edges
        for(int v = 0; v < graph.size(); v++){
            for(int n = 0; n < graph.get(v).size(); n++){
                Edge ne = graph.get(v).get(n);
                e.add(new BEdge(v, ne.n, ne.wt));
            }
        }

        int[] res = new int[graph.size()];
        Arrays.fill(res, Integer.MAX_VALUE);
        res[0] = 0;

        for(int i = 0; i < graph.size() - 1; i++){
            for(int j = 0; j < e.size(); j++){
                BEdge be = e.get(j);
                if(res[be.v1] != Integer.MAX_VALUE && res[be.v1] + be.wt < res[be.v2]){
                    res[be.v2] = res[be.v1] + be.wt;
                }
            }
        }
        
        for(int j = 0; j < e.size(); j++){
            BEdge be = e.get(j);
            if(res[be.v1] != Integer.MAX_VALUE && res[be.v1] + be.wt < res[be.v2]){
                System.out.println("Negative Cycle detect");
                return;
            }
        }

        for(int i = 0; i < res.length; i++){
            System.out.print(res[i] + " ");
        }
        System.out.println();
    }

    //  1st June 2019

    static void topHeler(ArrayList<ArrayList<Edge>> graph, int src, boolean[] visited, Stack<Integer> st){

        visited[src] = true;
        for(int n = 0; n < graph.get(src).size(); n++){
            Edge ne = graph.get(src).get(n);
            if(visited[ne.n] == false){
                topHeler(graph, ne.n, visited, st);
            }
        }
        st.push(src);
    }

    static void TopologicalSort(ArrayList<ArrayList<Edge>> graph){
        Stack<Integer> st = new Stack<>();
        boolean[] visited = new boolean[graph.size()];

        for(int v = 0; v < graph.size(); v++){
            if(visited[v] == false){
                topHeler(graph, v, visited, st);
            }
        }

        // stack can be print by System.out.println();
        System.out.println(st);
        while(st.size() > 0){
            int val = st.peek(); st.pop();
            System.out.print(val + " ");
        }
        System.out.println();
    }

    static int timer = 0;
    static void BridgesAndAps(ArrayList<ArrayList<Edge>> graph, int[] disc,
            int[] low, int par, int src, boolean[] visited, boolean[] aps){
        
        visited[src] = true;
        disc[src] = low[src] = ++timer;
        int count = 0;
        for(int n = 0; n < graph.get(src).size(); n++){
            Edge ne = graph.get(src).get(n);
            int nbr = ne.n;

            if(visited[nbr] == true && nbr == par){
                // nothing to do here
            }
            else if(visited[nbr] == true && nbr != src){
                low[src] = Math.min(disc[nbr], low[src]);
            }
            else{
                count++; // help to update the root
                BridgesAndAps(graph, disc, low, src, nbr, visited, aps);
                low[src] = Math.min(low[src], low[nbr]);
                if(disc[src] == 1){
                    if(count >= 2){
                        aps[src] = true;
                    }
                }
                else{
                    if(low[nbr] >= disc[src]){
                        aps[src] = true;
                    }
                }

                if(low[nbr] > disc[src]){
                    System.out.println(src + "--" + nbr + " is a bridge");
                }
            }
        } 
    }



    public static void main(String[] args) {
        ArrayList<ArrayList<Edge>> graph = new ArrayList<>();

        for (int v = 0; v < 7; v++) {
            graph.add(new ArrayList<>());
        }

        addEdge(graph, 0, 1, 10);
        addEdge(graph, 1, 2, 10);
        addEdge(graph, 2, 3, 10);
        addEdge(graph, 0, 3, 40);
        addEdge(graph, 3, 4, 2);
        addEdge(graph, 4, 5, 3);
        addEdge(graph, 5, 6, 3);
        addEdge(graph, 4, 6, 8);
        addEdge(graph, 2, 5, 5);

/*
        boolean[] visited = new boolean[7];
        display(graph);

        System.out.println(hasPath(graph, 0, 6, visited));
        System.out.println();
        visited = new boolean[7];
        // printAllPath(graph, 0, 6, visited, "", 0);
        // visited[0] = true;
        // printAllPath_Inc(graph, 0, 6, visited, "0", 0);

        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        mnHelper mn = new mnHelper();
        MinMax(graph, 0, 6, "", visited, 0, mn);
        System.out.println("Smallest path - " + mn.mnpath + " @ " + mn.min);
        System.out.println("Largest path - " + mn.mxpath + " @ " + mn.max);


        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        visited = new boolean[7];
        cfHelper cf = new cfHelper();
        ceilFloor(graph, 0, 6, visited, "", 0, cf, 46);
        System.out.println("Ceil path - " + cf.cpath + " @ " + cf.ceil);
        System.out.println("Floor path - " + cf.fpath + " @ " + cf.floor);
        System.out.println();
        kLarge_fromCeil(graph, 0, 6, 3);
        
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        kLargest(graph, 0, 6, "", 0, 5);
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        System.out.println(bfs(graph, 0, 6)); 
    
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        int[][] city = {
            {-2, -2, 0, -2, -2, -2},
            {-2, -1, -1, -2, -1, -1},
            {-2, -2, -1, -2, -2, -2},
            {-2, -2, -2, -2, -1, -1},
            {-2, -1, -1, 0, -2, -2}
        };
        // fire_in_city(city);
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        ArrayList<String> gcc = new ArrayList<>();
        gcc = getConnectedComponets(graph);
        System.out.println(gcc);
*/
        // System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        // int[][] isl = {
        //     {0, 0, -1, 0, 0},
        //     {0, -1, -1, -1, -1},
        //     {-1, 0, 0, 0, 0},
        //     {0, -1, 0, -1, 0},
        //     {0, -1, -1, -1, 0}
        // };
        // System.out.println(island(isl));
        // System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");

        // Date: 27th May 2019
 /*       System.out.println(isCyclic(graph));
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");

        // astraunats problem
        int[] ar1 = {1, 6, 8, 2, 9, 10, 0};
        int[] ar2 = {2, 9, 3, 5, 5, 3, 11};
        int count = 12;

        ArrayList<ArrayList<Edge>> astr = new ArrayList<>();

        for(int i = 0; i < count; i++){
            astr.add(new ArrayList<>());
        }
        for(int i = 0; i < ar1.length; i++){
            addEdge(astr, ar1[i], ar2[i], 0);
        }

        // display(astr);
        System.out.println(astronautsCount(astr));
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        System.out.println(isBipertite(graph));
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");

        // System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");

        // Date: 29th May 2019
        // djikstras(graph, 0);
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        ArrayList<ArrayList<Edge>> mst = prims(graph);
        display(mst);
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        ArrayList<ArrayList<Edge>> mst2 = prims(graph);
        display(mst2);
    */
        // System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        // boolean[] visited = new boolean[graph.size()];
        // ArrayList<Integer> psf = new ArrayList<>();
        // hamiltoniun(graph, 2, visited, psf);
        // System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        // int[][] board = new int[5][5];
        // KnightsTour(board, 1, 1, 0);

        // Date: 30th May 2019
       /* 
        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        ArrayList<ArrayList<Edge>> fwg = new ArrayList<>();
        for(int i = 0; i < 4; i++){
            fwg.add(new ArrayList<>());
        }
        fwg.get(0).add(new Edge(1, 2));
        fwg.get(0).add(new Edge(2, 4));
        fwg.get(0).add(new Edge(3, 8));
        fwg.get(1).add(new Edge(2, 1));
        fwg.get(1).add(new Edge(3, 5));
        fwg.get(2).add(new Edge(3, 1));

        display(fwg);

        floydWarshell(fwg);

        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");

        bellmanford(fwg, 0); */
        

        //  1st June 2019

        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");

        ArrayList<ArrayList<Edge>> tGraph = new ArrayList<>();
        for(int i = 0; i < 7; i++){
            tGraph.add(new ArrayList<>());
        }
        tGraph.get(0).add(new Edge(1, 0));
        tGraph.get(0).add(new Edge(4, 0));
        tGraph.get(1).add(new Edge(2, 0));
        tGraph.get(2).add(new Edge(3, 0));
        tGraph.get(5).add(new Edge(3, 0));
        tGraph.get(6).add(new Edge(5, 0));
        tGraph.get(6).add(new Edge(4, 0));

        TopologicalSort(tGraph);

        System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");

        ArrayList<ArrayList<Edge>> graph2 = new ArrayList<>();

        for (int v = 0; v < 9; v++) {
            graph2.add(new ArrayList<>());
        }

        addEdge(graph2, 0, 1, 10);
        addEdge(graph2, 1, 2, 10);
        addEdge(graph2, 2, 3, 10);
        addEdge(graph2, 0, 3, 40);
        addEdge(graph2, 3, 4, 2);
        addEdge(graph2, 4, 5, 3);
        addEdge(graph2, 5, 6, 3);
        addEdge(graph2, 4, 6, 8);
        // addEdge(graph2, 2, 5, 5);
        addEdge(graph2, 0, 7, 2);
        addEdge(graph2, 0, 8, 2);
        addEdge(graph2, 7, 8, 2);

        boolean[] visited2 = new boolean[graph2.size()];
        boolean[] aps = new boolean[graph2.size()];
        int[] disc = new int[graph2.size()];
        int[] low = new int[graph2.size()];
        
        BridgesAndAps(graph2, disc, low, -1, 0, visited2, aps);

        for(int i = 0; i < aps.length; i++){
            if(aps[i] == true)
                System.out.print(i + " ");
        }
        System.out.println("is Articulation point");

        // System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        
        // System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");

        // System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~");
        
    }
}