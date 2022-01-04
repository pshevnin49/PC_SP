#include "ford_fulkerson.h"

#define A 0
#define B 1
#define C 2
#define O 1000000000

int head, tail;
vector_t *q;
vector_t *out_edges;

node_t *find_node(int id){
	node_t *node;
	size_t a;

	for (a = 0; a < nodes->count; ++a){
		node = *(node_t **)vector_at(nodes, a);
		if (node){
			if (node->id == id){
				return node;
			}
		}
	}

	return NULL;
}

void enqueue(int x){
	node_t *node;
	vector_push_back(q, &x);
	tail++;
	node = find_node(x);
	node->color = B;
}

int dequeue(){
	int x = *(int *)vector_at(q, head);
	head++;
	find_node(x)->color = C;
	return x;
}

edge_t *find_edge(node_t *node_from, int to){
	edge_t *edge;
	size_t a;

	if (!node_from){
		return NULL;
	}

	for (a = 0; a < node_from->edges->count; ++a){
		edge = *(edge_t **)vector_at(node_from->edges, a);
		
		if (edge){
			if (edge->target == to){
				return edge;
			}
		}

	}

	return NULL;
}

int bfs(int start, int target){
	size_t a, b;
	int node_id;
	node_t *node;
	edge_t *edge;

	for (a = 0; a < nodes->count; ++a){
		node = *(node_t **)vector_at(nodes, a);
		node->pred = -1;
		node->color = A;
	}

	head = tail = 0;

	q = vector_create(sizeof(int), NULL);

	enqueue(start);
	find_node(start)->pred = -1;

	while (head != tail){
		node_id = dequeue();
		node = find_node(node_id);

		for (b = 0; b < node->edges->count; ++b){
			edge = *(edge_t **)vector_at(node->edges, b);
			if (find_node(edge->target)->color == A && edge->capacity - edge->flow > 0){
				enqueue(edge->target);
				find_node(edge->target)->pred = node_id;
			}
		}
	}

	return find_node(target)->color == C;

}

int ford_fulkerson(int source, int sink){
	int max_flow = 0;

	edge_t *edge, *edge_out;
	node_t *node, *pred_node;

	if(source == sink){
		return max_flow;
	}

	out_edges = vector_create(sizeof(edge_t *), (vec_it_dealloc_t)edge_destroy);

	while (bfs(source, sink)){
		int increment = O;
		node = find_node(sink);

		do{
			pred_node = find_node(node->pred);
			edge = find_edge(pred_node, node->id);
			if(increment > edge->capacity - edge->flow){

				edge_out = edge;
				increment = edge->capacity - edge->flow;
			}

			node = pred_node;
		} while(node->pred >= 0);

		node = find_node(sink);
		do{
			pred_node = find_node(node->pred);
			edge = find_edge(pred_node, node->id);
			edge->flow += increment;
			node = pred_node;
		} while(node->pred >= 0);

		vector_push_back(out_edges, &edge_out);
		max_flow += increment;

	}
	return max_flow;
}