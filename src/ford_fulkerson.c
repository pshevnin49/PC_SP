#include <stdio.h>
#include <math.h>
#include "vector.h"
#include "loader.h"
#include "node.h"
#include "edge.h"

#define A 0
#define B 1
#define C 2
#define O 1000000000

int head, tail;
vector_t *q;

node_t *find_node(int id){
  node_t *node;
  int a;

  for(a = 0; a < nodes->count; a++){
    node = *(node_t **)vector_at(nodes, a);
    if (node){
      if (node->id == id){
        return node;
      }
    }   
  }

  return NULL;

}

void enqueue(int x) {
  node_t *node;
  vector_push_back(q, &x);
  tail++;
  node = find_node(x);
  node->color = B;
}

int dequeue() {
  int x = *(int *)vector_at(q, head);
  head++;
  find_node(x)->color = C;
  return x;
}


edge_t *find_edge(node_t *node_from, int to){
  edge_t *edge;
  int a;

  if (!node_from){
    return NULL;
  }
  
  for(a = 0; a < node_from->edges->count; a++){
    edge = *(edge_t **)vector_at(node_from->edges, a);
    if (edge){
      if(edge->target == to){
          return edge;
      }
    }
  }

  return NULL;
}

int bfs(int start, int target) {
  
  int n, e, node_id;
  node_t *node;
  edge_t *edge;

  for(n = 0; n < nodes->count; n++){
    node = *(node_t **)vector_at(nodes, n);
    node->pred = -1;
    node->color = A;
  }

  head = tail = 0;
  q = vector_create(sizeof(int), NULL);

  enqueue(start);
  find_node(start)->pred = -1;
  while (head != tail) {
    printf("q count: %d\n", (int)q->count);
    node_id = dequeue();
    printf("id %d", node_id);
    node = find_node(node_id);
    node_print(node);
    for (e = 0; e < node->edges->count; e++) {
      edge = *(edge_t **)vector_at(node->edges, e);
      if (find_node(edge->target)->color == A && edge->capacity - edge->flow > 0) {
        enqueue(edge->target);
        find_node(edge->target)->pred = node_id;
      }
    }
  }
  return find_node(target)->color == C;
}

// Applying fordfulkerson algorithm
int ford_fulkerson(int source, int sink) {// create list edges min rez
  int max_flow = 0;
  edge_t *edge, *edge_temp;
  node_t *node, *pred_node;
  
  // Updating the residual values of edges
  while (bfs(source, sink)) {
    int increment = O;
    printf("in while");
    node = find_node(sink);
    do{
      pred_node = find_node(node->pred);
      edge = find_edge(pred_node, node->id);
      if (increment > edge->capacity - edge->flow){
        edge_temp = edge;
        increment = edge->capacity - edge->flow;
      }

      node = pred_node;
    } while (node->pred >= 0);

    node = find_node(sink);
    do{  
      pred_node = find_node(node->pred);
      edge = find_edge(pred_node, node->id);
      edge->flow += increment; 
      node = pred_node;
    } while (node->pred >= 0);

    printf("increment %d ", increment);
    /*edge_print(edge_temp);*/
    max_flow += increment;
  }
  return max_flow;
}