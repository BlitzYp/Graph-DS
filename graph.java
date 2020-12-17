import java.util.*;

public class Main {
    public static class Graph {
        HashMap<Integer, ArrayList<Integer>> adjList;

        public Graph() {
            adjList = new HashMap<Integer, ArrayList<Integer>>();
        }

        public void addVertex(int value) {
            adjList.put(value, new ArrayList<Integer>());
        }

        public void addEdge(int src, int dest) {
            try {
                adjList.get(src).add(dest);
                adjList.get(dest).add(src);
            } catch (Exception err){
                System.out.println("Could not add edges");
            }
        }

        public void bfs(int startingVertex) {
            Queue<ArrayList<Integer>> queue = new LinkedList<ArrayList<Integer>>();
            HashMap<Integer, Boolean> visited = new HashMap<Integer, Boolean>();

            queue.add(adjList.get(startingVertex));
            visited.put(startingVertex, true);
            System.out.println(startingVertex);

            while (!queue.isEmpty()) {
                ArrayList<Integer> vertex = queue.poll();
                for (int i: vertex) {
                    if (visited.get(i) == null) {
                        System.out.println(i);
                        visited.put(i, true);
                        queue.add(adjList.get(i));
                    }
                }
            }
        }

        public ArrayList<Integer> dfs(int node, ArrayList<Integer> res, ArrayList<Integer> visited) {
            if (adjList.get(node) == null) {
                System.out.println(node);
                return res;
            }

            res.add(node);
            visited.add(node);

            for (int i: adjList.get(node)) {
                if (!visited.contains(i)) {
                    dfs(i, res, visited);
                }
            }
            return res;
        }
        public void showConnections() {
            for (int i: values) {
                ArrayList<Integer> connections = adjList.get(i);
                System.out.println(i + "->" + connections);
            }     
        }
    }
    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.addVertex(5);
        graph.addVertex(6);
        graph.addEdge(6, 5);
        graph.addVertex(1);
        graph.addVertex(3);
        graph.addEdge(1, 5);
        graph.addEdge(1, 6);
        graph.addEdge(3, 6);
        graph.bfs(1);
        ArrayList<Integer> res = graph.dfs( 1, new ArrayList<Integer>(), new ArrayList<Integer>());
        System.out.println(res);
    }
}
