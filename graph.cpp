#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

class Graph
{
public:
	std::map<int, std::vector<int>> data;
	size_t size;
	Graph()
	{
		data = std::map<int, std::vector<int>>();
		size = 0;
	}

	void addVertex(int n)
	{
		data.insert(std::pair<int, std::vector<int>>(n, std::vector<int>(1)));
	}

	void addEdge(int n, int a)
	{
		data[n].push_back(a);
		data[a].push_back(n);
	}

	void showEdges()
	{
		for (auto i: data) 
		{
			std::vector<int> currentData = i.second;
			printf("%d", i.first);
			for (auto j: currentData) 
			{
				if (j != 0) printf("->%d", j);
			}	
			puts(" ");
		}
	}

	void breadthFirstSearch(int x, std::vector<int>& placeToStore)
	{
		std::set<int> visited = std::set<int>();
		std::queue<int> q = std::queue<int>();
		q.push(x);
		placeToStore.push_back(x);
		while (!q.empty())
		{
			int current = q.front();
			q.pop();
			for (auto i : data[current])
			{
				if (!visited.count(i))
				{
					visited.insert(i);
					placeToStore.push_back(i);
				}
			}
		}
	}
};

int main()
{
	Graph graph = Graph();
	graph.addVertex(2);
	graph.addVertex(4);
	graph.addEdge(2, 4);
	graph.showEdges();
	std::vector<int> data;
	graph.breadthFirstSearch(2, data);
	for (auto i : data)
		std::cout << i << '\n';
}
