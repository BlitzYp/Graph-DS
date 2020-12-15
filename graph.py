class Graph:
    def __init__(self):
        self.count = 0
        self.adject_list = {}

    # adding a Node (new item)
    def add_vertex(self, node):
        self.adject_list[node] = []
        self.count += 1

    # undirected graph
    def add_edge(self, node1, node2):
        self.adject_list[node1].append(node2)
        self.adject_list[node2].append(node1)


def bfs(graph, start_node):
    queue = []
    visited = []
    res = []

    visited.append(start_node)
    queue.append(start_node)

    while len(queue):
        vertex = queue.pop(0)
        res.append(vertex)
        for neighbor in graph[vertex]:
            if neighbor not in visited:
                visited.append(neighbor)
                queue.append(neighbor)

    return res

def dfs(graph, node: str, visited: set, res):
    if not node:
        return

    visited.add(node)
    res.append(node)

    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited, res)

    return res
    

def main():
    graph = Graph()
    graph.add_vertex("1")
    graph.add_vertex("5")
    graph.add_vertex("6")
    graph.add_vertex("2")
    graph.add_edge("1", "5")
    graph.add_edge("1", "6")
    graph.add_edge("5", "2")
    graph.add_edge("6", "2")
    
    #BFS
    bfs(graph.adject_list, "1")

    #DFS
    visited = set()
    res = dfs(graph.adject_list, "5", visited, [])

    #BFS
    res2 = bfs(graph.adject_list, "1")
    print(res, res2)

if __name__ == "__main__":
    main()