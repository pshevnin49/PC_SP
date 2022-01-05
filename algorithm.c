#include "algorithm.h"

vector_t *out_edges;

int ford_fulkerson(int source, int sink){
	int max_flow = 0;

	edge_t *edge, *edge_out;
	node_t *node, *pred_node;

	if(source == sink){
		return max_flow;
	}

	out_edges = vector_create(sizeof(edge_t *), (vec_it_dealloc_t)edge_destroy);
	
	if(!out_edges){
		return EXIT_FAILURE_UNDEF;
	}

	while(bfs(source, sink)){
		int increment;
		
		vector_destroy(&q);
		node = find_node(sink);

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
		node = find_node(sink);
		
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