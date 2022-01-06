#include "bfs.h"

int begin, end;
vector_t *q;

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

void in_q(int x){
	node_t *node;
	vector_push_back(q, &x);
	end++;
	node = find_node(x);
	node->color = GREY;
}

int from_q(){
	int x = *(int *)vector_at(q, begin);
	begin++;
	find_node(x)->color = BLACK;
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
		node->color = WHITE;
	}

	begin = end = 0;

	q = vector_create(sizeof(int), NULL);

	in_q(start);
	find_node(start)->pred = -1;

	while (begin != end){
		node_id = from_q();
		node = find_node(node_id);

		for (b = 0; b < node->edges->count; ++b){
			edge = *(edge_t **)vector_at(node->edges, b);
			if (find_node(edge->target)->color == WHITE && edge->capacity - edge->flow > 0){
				in_q(edge->target);
				find_node(edge->target)->pred = node_id;
			}
		}
	}
	vector_destroy(&q);
	return find_node(target)->color == BLACK;
}