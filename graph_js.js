const _addVertex = (value, graph) => {
    graph.adjList[value] = [];
}

const _addEdge = (node1, node2, graph) => {
    graph.adjList[node1].push(node2);
    graph.adjList[node2].push(node1);
}

function _bfs(graph, startNode) {
    let visited = new Set();
    let res = [];
    let queue = [];

    queue.push(startNode);
    while (queue.length != 0) {
        const vertex = queue.shift();
        res.push(vertex);
        for (let i of graph.adjList[vertex])  {
            if (!visited.has(i)) {
                visited.add(i);
                queue.push(i);
            }  
        }
    }
    return res;
}

function _dfs(graph, node, visited, res) {
    if (!node) return res;

    res.push(node);
    visited[node.toString()] = true;

    for (let i of graph.adjList[node]) {
        if (!visited[i.toString()]) {
            _dfs(graph, i, visited, res)
        }
    }

    return res;
}

function _main() {
    let graph = { adjList: {} };
    _addVertex("1", graph);
    _addVertex("2", graph);
    _addVertex("5", graph);
    _addVertex("3", graph);
    _addVertex("4", graph);
    _addEdge("3", "2", graph);
    _addEdge("4", "5", graph);
    _addEdge("4", "2", graph);
    const res = _bfs(graph, "5");
    const res2 = _dfs(graph, "5", new Set(), []);
    console.log(res, res2);
}

_main();
