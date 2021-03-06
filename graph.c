#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Struct for a single node in the adj_list */
struct vertex_t
{
    uint8_t v;
    struct vertex_t* next;
};

typedef struct graph_t 
{   
    uint8_t size;
    struct vertex_t** adj_list;
}graph_t;

struct vertex_t* create_node(uint8_t value);
struct graph_t* create_graph(uint8_t s);
void add_edge(graph_t* graph, uint8_t node1, uint8_t node2);

int main()
{
    graph_t* graph = create_graph(10);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 0, 3);
    add_edge(graph, 3, 1);
    struct vertex_t** list = &graph->adj_list[3];
    printf("Next elem: %d\n", list[0]->v);
}

struct vertex_t* create_node(uint8_t value)
{
    struct vertex_t* res = malloc(sizeof(struct vertex_t));
    res->v = value;
    res->next = NULL;
    return res;
}

struct graph_t* create_graph(uint8_t size)
{
    struct graph_t* graph = malloc(sizeof(graph_t));
    graph->size = size;
    graph->adj_list = malloc(sizeof(struct vertex_t) * size);

    /* Setting all values to null*/
    for (uint8_t i = 0; i < size; i++)
        graph->adj_list[i] = NULL;
    return graph;
}

void add_edge(graph_t* graph, uint8_t s, uint8_t d)
{
    struct vertex_t* src = create_node(s);
    struct vertex_t* dest = create_node(d);
    
    /* Adding a edge from src to dest */

    /* Storing the current src element in the next location and then  
    replacing the current src element with the new number/element */
    dest->next = graph->adj_list[s]; 
    graph->adj_list[s] = dest; 

    /* Adding a edge from dest to src */
    src->next = graph->adj_list[d];
    graph->adj_list[d] = src;
}
