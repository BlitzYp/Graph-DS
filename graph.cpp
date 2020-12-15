#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>

class Graph {
    public:
        std::map<int, std::vector<int>> adject_list;

        template<typename T>
        void add_vertex(const T num1)
        {
            std::vector<T> neighbors;
            adject_list[num1] = neighbors;
        }

        template<typename T>
        void add_edge(const T node1, const T node2)
        {
            adject_list[node1].push_back(node2);
            adject_list[node2].push_back(node2);
        }
};

void dfs(Graph* graph, const int node, std::set<int> visited, std::vector<int>* res)
{
    if (!node)
    {   
        return;
    }

    visited.insert(node);
    res->push_back(node);

    for (auto i: graph->adject_list[node])
    {
        if (!visited.count(i))
        {
            dfs(graph, i, visited, res);
        }
    }
}

template<typename T>
void bfs(Graph* graph, const T node, std::vector<int>& res)
{
    std::set<T> visited;
    std::queue<T> queue;

    queue.push(node);
    visited.insert(node);

    while (queue.size() != 0)
    {
        T vertex = queue.front();
        queue.pop();
        res.push_back(vertex);
        for (auto i: graph->adject_list[vertex])
        {
            if (!visited.count(i))
            {
                queue.push(i);
                visited.insert(i);
            }
        }
    }
}

int main()
{
    Graph graph;
    graph.add_vertex<int>(4);
    graph.add_vertex<int>(3);
    graph.add_vertex<int>(5);
    graph.add_vertex<int>(10);
    graph.add_edge<int>(4, 3);
    graph.add_edge<int>(10, 5);
    graph.add_edge<int>(5, 3);
    graph.add_edge<int>(10,4);
    graph.add_edge<int>(3, 10);
    std::vector<int> res;
    //dfs(&graph, 4, std::set<int>(), &res);
    bfs(&graph, 10, res);
    
    for (auto i: res) 
    {
        std::cout << i << "\n";
    }
}