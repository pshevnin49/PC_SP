#include "algorithm.h"

vector_t *out_edges;

int ford_fulkerson(int source, int target){
	int max_flow = 0;

	edge_t *edge, *edge_out;
	node_t *node, *pred_node;

	if(source == target){
		return max_flow;
	}

	out_edges = vector_create(sizeof(edge_t *), (vec_it_dealloc_t)edge_destroy);
	
	if(!out_edges){
		return EXIT_FAILURE_UNDEF;
	}

	while(bfs(source, target)){
		int increment;
		
		node = find_node(target);
		increment = O;

		while(node->pred >= 0){
			pred_node = find_node(node->pred);
			edge = find_edge(pred_node, node->id);
			if(increment > edge->capacity - edge->flow){
				edge_out = edge;
				increment = edge->capacity - edge->flow;
			}
			node = pred_node;
		} 
		node = find_node(target);
		
		while(node->pred >= 0){
			pred_node = find_node(node->pred);
			edge = find_edge(pred_node, node->id);
			edge->flow += increment;
			node = pred_node;
		} 
		vector_push_back(out_edges, &edge_out);
		max_flow += increment;
	}
	return max_flow;
}