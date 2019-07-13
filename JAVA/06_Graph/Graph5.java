package Lecture37;

import java.util.*;

public class Graph5 {
	private static class Edge {
		int o;
		int n;
		int wt;

		Edge(int v1, int v2, int wt) {
			this.o = v1;
			this.n = v2;
			this.wt = wt;
		}
	}

	private static void addEdge(ArrayList<ArrayList<Edge>> graph, int v1, int v2, int wt) {
		graph.get(v1).add(new Edge(v1, v2, wt));
		graph.get(v2).add(new Edge(v2, v1, wt));
	}

	private static void display(ArrayList<ArrayList<Edge>> graph) {
		for (int v = 0; v < graph.size(); v++) {
			System.out.print("|" + v + "| -> ");
			for (int e = 0; e < graph.get(v).size(); e++) {
				Edge edge = graph.get(v).get(e);
				System.out.print("[" + edge.o + ", " + edge.n + ", " + edge.wt + "]" + ", ");
			}
			System.out.println();
		}
	}

	private static boolean hasPath11(int src, int dest, ArrayList<ArrayList<Edge>> graph, boolean[] visited) {
		if (src == dest) {
			return true;
		}
		visited[src] = true;
		for (int e = 0; e < graph.get(src).size(); e++) {
			// take neighbour
			int nbr = graph.get(src).get(e).n;
			if (visited[nbr] == false) {
				// path from neighbour
				boolean pfn = hasPath11(nbr, dest, graph, visited);
				if (pfn == true) {
					return true;
				}
			}
		}
		return false;
	}

	private static boolean hasPath12(int src, int dest, ArrayList<ArrayList<Edge>> graph, boolean[] visited) {
		if (visited[src] == true) {
			return false;
		}
		if (src == dest) {
			return true;
		}
		visited[src] = true;
		for (int e = 0; e < graph.get(src).size(); e++) {
			// take neighbour
			int nbr = graph.get(src).get(e).n;
			// path from neighbour
			boolean pfn = hasPath12(nbr, dest, graph, visited);
			if (pfn == true) {
				return true;
			}
		}
		return false;
	}

	private static boolean hasPath21(int src, int dest, ArrayList<ArrayList<Edge>> graph, boolean[] visited) {
		// In this function we have to marks it in main that it is visited

		if (src == dest) {
			return true;
		}
		for (int e = 0; e < graph.get(src).size(); e++) {
			// take neighbour
			int nbr = graph.get(src).get(e).n;
			if (visited[nbr] == false) {
				// path from neighbour
				visited[nbr] = true;
				boolean pfn = hasPath21(nbr, dest, graph, visited);
				if (pfn == true) {
					return true;
				}
			}
		}
		return false;
	}

	private static void printAllPath11(int src, int dest, ArrayList<ArrayList<Edge>> graph, boolean[] visited,
			String asf, int dsf) {
		if (src == dest) {
			System.out.println(asf + src + "@" + dsf);
			return;
		}
		visited[src] = true;
		for (int e = 0; e < graph.get(src).size(); e++) {
			int nbr = graph.get(src).get(e).n;
			int ndist = graph.get(src).get(e).wt;
			if (visited[nbr] == false) {
				printAllPath11(nbr, dest, graph, visited, asf + src + "->", dsf + ndist);
			}
		}
		visited[src] = false;
	}

	private static void printAllPath12(int src, int dest, ArrayList<ArrayList<Edge>> graph, boolean[] visited,
			String asf) {

		// in this code we have to add src in main
		if (src == dest) {
			System.out.println(asf);
			return;
		}
		for (int e = 0; e < graph.get(src).size(); e++) {
			int nbr = graph.get(src).get(e).n;
			if (visited[nbr] == false) {
				visited[nbr] = true;
				printAllPath12(nbr, dest, graph, visited, asf + nbr + "->");
				visited[nbr] = false;
			}
		}

	}

	/* Date: 11th April 2019 */

	private static class MnMxHelper {
		String sp;
		int spd;
		String lp;
		int lpd;

		MnMxHelper() {
			sp = "";
			spd = Integer.MAX_VALUE;
			lp = "";
			lpd = Integer.MIN_VALUE;
		}
	}

	private static void minmaxPath(int src, int dest, ArrayList<ArrayList<Edge>> graph, boolean[] visited, String psf,
			int dsf, MnMxHelper path) {
		if (src == dest) {
			psf = psf + " " + src;
			if (dsf < path.spd) {
				path.sp = psf;
				path.spd = dsf;

			}
			if (dsf > path.lpd) {
				path.lp = psf;
				path.lpd = dsf;
			}
			return;
		}

		visited[src] = true;
		for (int e = 0; e < graph.get(src).size(); e++) {
			int nbr = graph.get(src).get(e).n;
			int ndist = graph.get(src).get(e).wt;
			if (visited[nbr] == false) {
				minmaxPath(nbr, dest, graph, visited, psf + " " + src, dsf + ndist, path);
			}
		}
		visited[src] = false;
	}

	private static class CFhelper {
		String cp;
		int cpd;
		String fp;
		int fpd;

		CFhelper() {
			cp = "";
			cpd = Integer.MAX_VALUE;
			fp = "";
			fpd = Integer.MIN_VALUE;
		}
	}

	private static void ceilfloorPath(int src, int dest, int factor, ArrayList<ArrayList<Edge>> graph,
			boolean[] visited, String psf, int dsf, CFhelper path) {
		if (src == dest) {
			psf = psf + " " + src;
			if (dsf > factor && path.cpd > dsf) {
				path.cp = psf;
				path.cpd = dsf;

			}
			if (dsf < factor && path.fpd < dsf) {
				path.fp = psf;
				path.fpd = dsf;
			}
			return;
		}

		visited[src] = true;
		for (int e = 0; e < graph.get(src).size(); e++) {
			int nbr = graph.get(src).get(e).n;
			int ndist = graph.get(src).get(e).wt;
			if (visited[nbr] == false) {
				ceilfloorPath(nbr, dest, factor, graph, visited, psf + " " + src, dsf + ndist, path);
			}
		}
		visited[src] = false;
	}

	private static void kthLargestPath(int src, int dest, ArrayList<ArrayList<Edge>> graph, String psf, int dsf, int k,
			CFhelper fl) {
		int factor = Integer.MAX_VALUE;
		for (int i = 0; i < k; i++) {
			fl.fp = "";
			fl.fpd = Integer.MIN_VALUE;
			boolean[] visited = new boolean[graph.size()];
			ceilfloorPath(src, dest, factor, graph, visited, psf, dsf, fl);
			factor = fl.fpd;
		}
		System.out.println(fl.fp + " @ " + fl.fpd);

	}

	private static void hamiltonian(int src, ArrayList<ArrayList<Edge>> graph, boolean[] visited,
			ArrayList<Integer> psf, int os) {
		if (psf.size() == graph.size() - 1) {
			psf.add(src);

			System.out.print(psf);
			boolean cycleDetected = false;
			for (int e = 0; e < graph.get(src).size(); e++) {
				Edge edge = graph.get(src).get(e);
				if (edge.n == os) {
					cycleDetected = true;
					break;
				}
			}

			if (cycleDetected == true) {
				System.out.println("*");
			} else {
				System.out.println(".");
			}

			psf.remove(psf.size() - 1);
			return;
		}

		visited[src] = true;
		psf.add(src);
		for (int e = 0; e < graph.get(src).size(); e++) {
			Edge edge = graph.get(src).get(e);
			if (visited[edge.n] == false) {
				hamiltonian(edge.n, graph, visited, psf, os);
			}
		}
		visited[src] = false;
		psf.remove(psf.size() - 1);
	}
	
	static int counter = 0;
	
	private static void knightTour(int[][] graph, int r, int c, int move){
         if(r < 0 || r >= graph.length || c < 0 || c >= graph.length || graph[r][c] != 0){
        	 return;
         }
         if(move == graph.length * graph.length) {
        	 graph[r][c] = move;
        	 counter++;
        	 System.out.println("========"+counter+"========");
        	 for(int i = 0; i < graph.length; i++) {
        		 for(int j = 0; j < graph.length; j++) {
        			 System.out.print(graph[i][j] + " ");
        		 }
        		 System.out.println();
        	 }
        	 System.out.println("========"+counter+"========");
        	 graph[r][c] = 0;
        	 return;
         }
         
         graph[r][c] = move;
         knightTour(graph, r - 2, c + 1, move+1);
         knightTour(graph, r - 2, c - 1, move+1);
         knightTour(graph, r + 2, c + 1, move+1);
         knightTour(graph, r + 2, c - 1, move+1);
         knightTour(graph, r - 1, c + 2, move+1);
         knightTour(graph, r + 1, c + 2, move+1);
         knightTour(graph, r - 1, c - 2, move+1);
         knightTour(graph, r + 1, c - 2, move+1);
         
         graph[r][c] = 0;

     }

	static class THelper implements Comparable<THelper>{
		int vtx;
		String psf;
		int dsf;

		THelper(int vtx, String psf, int dsf) {
			this.vtx = vtx;
			this.dsf = dsf;
			this.psf = psf;
		}

		public int compareTo(THelper other){
			return this.dsf - other.dsf;
		}
	}

	private static boolean bfs(ArrayList<ArrayList<Edge>> graph, int src, int dest) {
		LinkedList<THelper> queue = new LinkedList<>();

		THelper t = new THelper(src, src + "", 0);
		queue.addLast(t);
		boolean[] visited = new boolean[graph.size()];

		while (queue.size() > 0) {
			// Get
			THelper cp = queue.getFirst();
			// Remove
			queue.removeFirst();

			System.out.println(cp.vtx + " via " + cp.psf + " @ " + cp.dsf);
			// Mark* - multiple marking
			if (visited[cp.vtx] == true) {
				continue;
			} else {
				visited[cp.vtx] = true;
			}
			// Work
			if (cp.vtx == dest) {
				System.out.println("We Win");
				return true;
			}
			// Add*
			for (int e = 0; e < graph.get(cp.vtx).size(); e++) {
				Edge edge = graph.get(cp.vtx).get(e);
				int dist = edge.wt;
				if (visited[edge.n] == false) {
					THelper np = new THelper(edge.n, cp.psf + edge.n, cp.dsf + dist);
					queue.addLast(np);
				}
			}

		}
		return false;
	}

	/* Date: 12th April 2019*/
	
	private static boolean dfs(ArrayList<ArrayList<Edge>> graph, int src, int dest) {
		LinkedList<THelper> stack = new LinkedList<>();
		THelper t = new THelper(src, src + "", 0);
		
		
		return false;
	}
	
	private static void gcc(ArrayList<ArrayList<Edge>> graph, ArrayList<ArrayList<Integer>> comp) {
		boolean[] visited = new boolean[graph.size()];
		for(int v = 0; v < graph.size(); v++) {
			if(visited[v] == false) {
				ArrayList<Integer> scomp = new ArrayList<>();
				gccComponent(graph, v, visited, scomp);
				comp.add(scomp);
			}
		}
	}
	
	private static void gccComponent(ArrayList<ArrayList<Edge>> graph, int src, 
			boolean[] visited, ArrayList<Integer> scomp) {
		LinkedList<THelper> queue = new LinkedList<>();

		THelper t = new THelper(src, src + "", 0);
		queue.addLast(t);

		while (queue.size() > 0) {
			// Get
			THelper cp = queue.getFirst();
			// Remove
			queue.removeFirst();

			// Mark* - multiple marking
			if (visited[cp.vtx] == true) {
				continue;
			} else {
				visited[cp.vtx] = true;
			}
			// Work
			scomp.add(cp.vtx);
			// Add*
			for (int e = 0; e < graph.get(cp.vtx).size(); e++) {
				Edge edge = graph.get(cp.vtx).get(e);
				int dist = edge.wt;
				if (visited[edge.n] == false) {
					THelper np = new THelper(edge.n, cp.psf + edge.n, cp.dsf + dist);
					queue.addLast(np);
				}
			}

		}
	}
	
	private static boolean isConnected(ArrayList<ArrayList<Edge>> graph) {
		boolean[] visited = new boolean[graph.size()];
		for(int v = 0; v < graph.size(); v++) {
			if(visited[v] == false) {
				ArrayList<Integer> scomp = new ArrayList<>();
				gccComponent(graph, v, visited, scomp);
				if(scomp.size() == graph.size()) {
					return true;
				}
			}
		}
		return false;
	}
	
	private static boolean isCyclic(ArrayList<ArrayList<Edge>> graph){
		boolean[] visited = new boolean[graph.size()];
		for(int v = 0; v < graph.size(); v++) {
			if(visited[v] == false) {
				boolean isCycle = isCyclicComponent(graph, v, visited);
				if(isCycle == true){
					return true;
				}
			}
		}
		return false;
	}
	
	private static boolean isCyclicComponent(ArrayList<ArrayList<Edge>> graph,
		 int src, boolean[] visited){
		LinkedList<THelper> queue = new LinkedList<>();
		THelper t = new THelper(src, src + "", 0);
		queue.addLast(t);

		while (queue.size() > 0) {
			// Get
			THelper cp = queue.getFirst();
			// Remove
			queue.removeFirst();

			// Mark* - multiple marking
			if (visited[cp.vtx] == true) {
				return true;
			} else {
				visited[cp.vtx] = true;
			}
			// Work
			// Add*
			for (int e = 0; e < graph.get(cp.vtx).size(); e++) {
				Edge edge = graph.get(cp.vtx).get(e);
				int dist = edge.wt;
				if (visited[edge.n] == false) {
					THelper np = new THelper(edge.n, cp.psf + edge.n, cp.dsf + dist);
					queue.addLast(np);
				}
			}

		}
		return false;
	}

	/* Date: 13th April 2019*/
    
    private static void dijkstras(ArrayList<ArrayList<Edge>> graph, int src){
        PriorityQueue<THelper> pq = new PriorityQueue<>();
        THelper rh = new THelper(src, src+"", 0);

        pq.add(rh);
        boolean[] visited = new boolean[graph.size()];
        while(pq.size() > 0){
            THelper ch = pq.peek();
            pq.remove();

            if(visited[ch.vtx] == true){
                continue;
            }
            else {
                visited[ch.vtx] = true;
            }

            System.out.println(ch.vtx + " via " + ch.psf + " @ " + ch.dsf);

            for(int e = 0; e < graph.get(ch.vtx).size(); e++){
                Edge edge = graph.get(ch.vtx).get(e);
                int nbr = edge.n;
                int dist = edge.wt;
                if(visited[nbr] == false){
                    THelper th = new THelper(nbr, ch.psf + nbr, ch.dsf + dist);
                    pq.add(th);
                }
            }

        }

    }
	
	static class PHelper implements Comparable<PHelper>{
		int vtx;
		int pr;
		int wt;
		PHelper(int vtx, int pr, int wt){
			this.vtx = vtx;
			this.pr = pr;
			this.wt = wt;
		}

		public int compareTo(PHelper other){
			return this.wt - other.wt;
		}
	}

	private static void prims(ArrayList<ArrayList<Edge>> graph){
		PriorityQueue<PHelper> pq = new PriorityQueue<>();
		PHelper rh = new PHelper(0, -1, 0);
		pq.add(rh);
		boolean[] visited = new boolean[graph.size()];
		ArrayList<ArrayList<Edge>> mst = new ArrayList<>();
		for(int i = 0; i < graph.size(); i++){
			mst.add(new ArrayList<>());
		}
		while(pq.size() > 0){
			PHelper ch = pq.peek();
			pq.remove();

			if(visited[ch.vtx] == true){
				continue;
			}
			else{
				visited[ch.vtx] = true;
			}
			if(ch.pr != -1){
				addEdge(mst, ch.vtx, ch.pr, ch.wt);
			}
			for(int e = 0; e < graph.get(ch.vtx).size(); e++){
				Edge edge = graph.get(ch.vtx).get(e);
				int nbr = edge.n;
				int dist = edge.wt;
				if(visited[nbr] == false){
					PHelper th = new PHelper(nbr, ch.vtx,dist);
					pq.add(th);
				}
			}

		}
		display(mst);

	}

	

	static class KEdge implements Comparable<KEdge>{
		int o;
		int n;
		int wt;

		KEdge(int o, int n, int wt){
			this.o = o;
			this.n = n;
			this.wt = wt;
		}

		public int compareTo(KEdge other){
			return this.wt - other.wt;
		}
	};
	
	//Kruskal Algorithm



	/* Date: 14th April 2019*/

	public static void main(String[] args) {
		int n = 7;
		ArrayList<ArrayList<Edge>> graph = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			graph.add(new ArrayList<Edge>());
		}

		addEdge(graph, 0, 3, 40);
		addEdge(graph, 0, 1, 10);
		addEdge(graph, 1, 2, 10);
		addEdge(graph, 2, 3, 10);
		addEdge(graph, 3, 4, 2);
		addEdge(graph, 4, 5, 3);
		addEdge(graph, 4, 6, 8);
		addEdge(graph, 5, 6, 3);
		// addEdge(graph, 2, 5, 5);

		// display(graph);
		boolean[] visited = new boolean[n];
		System.out.println(hasPath11(0, 6, graph, visited));
		System.out.println("----------");
		Arrays.fill(visited, false);
		printAllPath11(0, 6, graph, visited, "", 0);

		/* Date: 11th April 2019 */
		System.out.println();
		display(graph);

		System.out.println("----------------------");
		MnMxHelper pathms = new MnMxHelper();
		minmaxPath(0, 6, graph, visited, "", 0, pathms);
		System.out.println(pathms.lp + " @ " + pathms.lpd + "\n" + pathms.sp + " @ " + pathms.spd);

		System.out.println("----------------------");
/*		CFhelper pathcf = new CFhelper();
		ceilfloorPath(0, 6, 52, graph, visited, "", 0, pathcf);
		System.out.println(pathcf.cp + " @ " + pathcf.cpd + "\n" + pathcf.fp + " @ " + pathcf.fpd);
		CFhelper fl = new CFhelper();
		System.out.println("----------------------");
		kthLargestPath(0, 6, graph, "", 0, 2, fl);
		System.out.println("----------------------");
		ArrayList<Integer> psf = new ArrayList<>();
		hamiltonian(1, graph, visited, psf, 1);
		System.out.println("----------------------");
		bfs(graph, 0, 6);
		System.out.println("----------------------"); */
		int[][] g1 = new int[5][5];
//		knightTour(g1, 1, 3, 1);
		ArrayList<ArrayList<Integer>> comp = new ArrayList<>();
		gcc(graph, comp);
		System.out.println(comp);
		System.out.println(isConnected(graph));
		System.out.println(isCyclic(graph));
		System.out.println("~~~~~~~~~~~~~~~~~~~~");
		dijkstras(graph, 0);
		System.out.println("~~~~~~~~~~~~~~~~~~~~");
		prims(graph);
	}
		
}