#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct vertex_t
{
    uint8_t v;
    struct vertex_t* next;
};

struct adj_list_t
{
    struct vertex* start_of_vertex_arr;
};

typedef struct graph_t 
{   
    uint8_t size;
    struct adj_list_t* adj_list;
}graph_t;

struct vertex_t* create_node(uint8_t value);
struct graph_t* create_graph(uint8_t s);
void add_edge(graph_t* graph, uint8_t node1, uint8_t node2);

int main()
{
    graph_t* graph = create_graph(10);
    add_edge(graph, 0, 1);
    uint8_t* arr = graph->adj_list[0].start_of_vertex_arr;
    while (*arr)
    {
        printf("%d->", *arr);
        arr++;
    }
}

struct vertex_t* create_node(uint8_t value)
{
    struct vertex_t* res = malloc(sizeof(struct vertex_t));
    res->v = value;
    res->next = NULL;
    return res;
}

struct graph_t* create_graph(uint8_t s)
{
    struct graph_t* graph = malloc(sizeof(graph_t));
    graph->size = s;
    graph->adj_list = malloc(sizeof(struct adj_list_t) * s);

    for (uint8_t i = 0; i < s; i++)
        graph->adj_list[i].start_of_vertex_arr = NULL;
    return graph;
}

void add_edge(graph_t* graph, uint8_t node1, uint8_t node2)
{
    struct vertex_t* val1 = create_node(node1);
    struct vertex_t* val2 = create_node(node2);
    val1->next = graph->adj_list[node2].start_of_vertex_arr; // This puts the pointer to the adj list in node2 in the next value for val1
    graph->adj_list[node2].start_of_vertex_arr = val1;  // Asigns the value
    val2->next = graph->adj_list[node1].start_of_vertex_arr;
    graph->adj_list[node1].start_of_vertex_arr = val2;
}