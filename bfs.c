#include "bfs.h"

/** @brief fronta pro indexy uzlů ktere jsou v cestě */
queue_t *queue;

node_t *find_node(int id){
	node_t *node;
	size_t a;

	for(a = 0; a < nodes->count; ++a){
		node = *(node_t **)vector_at(nodes, a);
		if(node){
			if(node->id == id){
				return node;
			}
		}
	}
	return NULL;
}

edge_t *find_edge(node_t *node_from, int to){
	edge_t *edge;
	size_t a;

	if(!node_from){
		return NULL;
	}

	for(a = 0; a < node_from->edges->count; ++a){
		edge = *(edge_t **)vector_at(node_from->edges, a);
		
		if(edge){
			if(edge->target == to){
				return edge;
			}
		}

	}
	
	return NULL;
}

int bfs(int start, int end){
	size_t a, b;
	int node_id;
	node_t *node;
	edge_t *edge;

	for(a = 0; a < nodes->count; ++a){
		node = *(node_t **)vector_at(nodes, a);
		node->pred = -1;
		node->color = WHITE;
	}

	queue = queue_create();
	/*vklada zdroj do fronty*/
	in_queue(queue, start);
	/*vklada prebarvi zdroj dna šedou, protože teď je ve frontě*/
	find_node(start)->color = GREY;
	/*predchozí prvek se rovna -1 protože cestá pro zdroj neexistuje*/
	find_node(start)->pred = -1;

	/*pokud fronta není prázdna*/
	while(!queue_is_empty(queue)){
		node_id = from_queue(queue);
		node = find_node(node_id);
		node->color = BLACK;

		/*prochází všichní hrany nalezeného uzlu*/
		for(b = 0; b < node->edges->count; ++b){
			edge = *(edge_t **)vector_at(node->edges, b);
			
			if(find_node(edge->target)->color == WHITE && edge->capacity - edge->flow > 0){
				in_queue(queue, edge->target);
				find_node(edge->target)->color = GREY;
				find_node(edge->target)->pred = node_id;
			}
		}
	}
	queue_destroy(&queue);
	
	/*pokud cestá byla nalezéna vrací 1 v opačném případě 0*/
	if(find_node(end)->color == BLACK){
		return 1;
	}
	return 0;
}