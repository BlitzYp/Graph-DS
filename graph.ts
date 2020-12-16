interface adjacentList<T> {
    value: string
    count: number
    data: adjacentList<T>[];
}

const addVertex = <T>(node: string, graph: adjacentList<T>) => {
    graph.data[node] = [];
    graph.count++;
    return;
}

const addEdge = <T>(node1: string, node2: string, graph: adjacentList<T>) => {
    graph.data[node1].push(node2);
    graph.data[node2].push(node1);
    return;
}


// Iterative way to do DFS
const showConnections = <T>(list: adjacentList<T>) => {
    const allNodes: string[] = Object.keys(list.data);
    for (let node of allNodes) {
        let nodeConnections: string[] = list.data[node];
        let connections = "";
        let vertex: string;
        for (vertex of nodeConnections) {
            connections += vertex + " ";
        }
        console.log(node + "-->" + connections);
    }
}

const dfs = <T>(graph: adjacentList<T>, node: T, res: T[], visited): Array<T> => {
    if (!node)
        return res;

    visited[node.toString()] = 1;
    let i: T;
    for (i of graph.data[node.toString()])
    {
        if (!visited[i.toString()])
        {
            visited[i.toString()] = 1;
            res.push(i);
            dfs(graph, i, res, visited);
        }
    }
    return res;
}

const bfs = <T>(graph: adjacentList<T>, node: T): T[] => {
    let queue: T[] = [];
    let visited = {};
    let res: T[] = [];
    queue.push(node);
    while (queue.length > 0)
    {
        const vertex: T = queue.shift();
        let i: T;
        for (i of graph.data[vertex.toString()])
        {
            if (!visited[i.toString()])
            {
                queue.push(i);
                res.push(i);
                visited[i.toString()] = i;
            }
        }
    }
    return res;
}

function main() {
    let graph: adjacentList<string> = { value: "", count: 0, data: [] };
    addVertex("1", graph);
    addVertex("2", graph);
    addVertex("5", graph);
    addVertex("3", graph);
    addVertex("4", graph);
    addEdge<string>("3", "2", graph);
    addEdge<string>("4", "5", graph);
    addEdge<string>("4", "2", graph);
    //showConnections<string>(graph);
    const res = dfs<string>(graph, "4", [], {});
    const res2 = bfs<string>(graph, "4");
    console.log(res, res2);
}

main();
