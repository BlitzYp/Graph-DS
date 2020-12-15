#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    add_edge(graph, 1, 0);
    struct vertex_t** list = graph->adj_list;
    printf("%d\n", list[0]->v);
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

    for (uint8_t i = 0; i < size; i++)
        graph->adj_list[i] = NULL;
    return graph;
}

void add_edge(graph_t* graph, uint8_t s, uint8_t d)
{
    struct vertex_t* src = create_node(s);
    struct vertex_t* dest = create_node(d);
    
    /* Adding a edge from src to dest */
    dest->next = graph->adj_list[s];
    graph->adj_list[s] = dest;

    /* Adding a edge from dest to src */
    src->next = graph->adj_list[d];
    graph->adj_list[d] = src;
}
