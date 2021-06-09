package main

import (
	"fmt"
)

type Graph struct {
	data map[string][]string
}

func addVertex(value string, graph *Graph) {
	graph.data[value] = make([]string, 10)
}

func addEdge(v1 string, v2 string, graph *Graph) {
	if graph.data[v1] == nil || graph.data[v2] == nil {
		fmt.Println("Not valid keys")
		return 
	}
	graph.data[v1] = append(graph.data[v1], v2)
	graph.data[v2] = append(graph.data[v2], v1)
}

func get(value string, graph *Graph) []string {
	return graph.data[value]
}

func main() {
	graph := Graph {
		data: make(map[string][]string),
	}
	addVertex("Blitz", &graph)
	addVertex("John", &graph)
	addVertex("Justin", &graph)
	addEdge("Blitz", "John", &graph)
	addEdge("Justin", "Blitz", &graph)
	
	connections := get("Blitz", &graph)
	for i := 0; i < len(connections); i++ {
		if connections[i] != "" {
			fmt.Println(connections[i])
		}
	}
}
