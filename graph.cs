using System.Collections.Generic;
using System.Collections;
using System;

class Graph
{
  public Dictionary<int, ArrayList> AdjList;
  
  public Graph() 
  {
    AdjList = new Dictionary<int, ArrayList>();
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
      foreach(int i in AdjList[Vertex]) {
        if (!visited.Contains(i)) 
        {
            visited.Add(i);
            queue.Enqueue(i);
        }
      }
    }
  }
  
  public LinkedList<int> Dfs(int StartNode, HashSet<int> visited, LinkedList<int> res)
  {
    if (AdjList[StartNode] == null) 
        return res;

    visited.Add(StartNode);
    res.AddLast(StartNode);

    foreach(int i in AdjList[StartNode]) {
        if (!visited.Contains(i)) 
        {
            Dfs(i, visited, res);
        }
    }
    return res;
  }
  
  public void AddVertex(int node)
  {
    AdjList.Add(node, new ArrayList());
  }
  
  public void AddEdge(int node1, int node2) 
  {
    AdjList[node1].Add(node2);
    AdjList[node2].Add(node1);
  }
}

