#include <iostream>
#include <vector>
#include <map>

struct graph {
    std::map<std::string, std::vector<std::string>> adjList;
    size_t size;
};

void addVertex(std::string value, graph& g) {
    g.adjList[value] = std::vector<std::string>();
    g.size++;
}

void addEdge(std::string v1, std::string v2, graph& g) {
    if (g.adjList.count(v1) == 0) {
        printf("KEY ERROR: Couldn't find key: %s\n", v1.c_str());
        exit(1);
    }
    if (g.adjList.count(v2) == 0) {
        printf("KEY ERROR: Couldn't find key: %s\n", v2.c_str());
        exit(1);
    }
    g.adjList[v1].push_back(v2);
    g.adjList[v2].push_back(v1);
}


int main(void) {
    graph g = {std::map<std::string, std::vector<std::string>>(), 0};
    addVertex("Blitz", g);
    addVertex("Jonnathan", g);
    addVertex("Bob", g);
    addVertex("Shipof", g);
    addEdge("Blitz", "Jonnathan", g);
    addEdge("John", "Shipof", g);
    std::cout << g.size << '\n';
    return 0;
}
