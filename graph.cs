using System;
using System.Collections.Generic;
using System.Collections;

class Program {
  class Graph
  {
    public LinkedList<int>[] AdjList;
    public Graph(int size) 
    {
      AdjList = new LinkedList<int>[size];
      for (int i = 0; i < size; i++) {
        AdjList[i] = new LinkedList<int>();
      }
    }

    public void Bfs(int StartNode) 
    {
      Queue<int> queue = new Queue<int>();
      HashSet<int> visited = new HashSet<int>();
      queue.Enqueue(StartNode);
      visited.Add(StartNode);

      while (queue.Count != 0) 
      {
        int Vertex = queue.Dequeue();
        Console.WriteLine(Vertex);
        foreach (int i in AdjList[Vertex]) {
          if (!visited.Contains(i)) {
            visited.Add(i);
            queue.Enqueue(i);
          }
        }
      }
    }
    public void AddEdge(int node1, int node2)
    {
      AdjList[node1].AddLast(node2);
      AdjList[node2].AddLast(node1);
    }
  }
  public static void Main(string[] args)
  {
    Graph graph = new Graph(5);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.Bfs(0);
  }
}

