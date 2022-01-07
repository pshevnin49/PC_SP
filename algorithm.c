#include "algorithm.h"
/*vector s hránama minímalního řezu*/
vector_t *out_edges;

int ford_fulkerson(int source, int target){
	int max_flow_graph = 0;

	edge_t *edge, *edge_out;
	node_t *node, *pred_node;
	
	/*Pokud zdroj a stok jsou stejná čísla tok určítě neexistuje*/
	if(source == target){
		return max_flow_graph;
	}

	out_edges = vector_create(sizeof(edge_t *), (vec_it_dealloc_t)edge_destroy);
	if(!out_edges){
		return EXIT_FAILURE_UNDEF;
	}

	/*algoritmus bfs hledá cestu ze zdroju ke stoku*/
	while(bfs(source, target)){
		int increment;

		/*aktualní vrchol (na začatku je to poslední vchol) */
		node = find_node(target);
		increment = O;
		
		/*prochází cestu, ktéra byla nalezena a spočíta increment*/
		while(node->pred != -1){
			/*předchozí vrchol aktualního vrcholu*/
			pred_node = find_node(node->pred);
			/*hrana ktera jde z predchoziho vrcholu k aktualnímu */
			edge = find_edge(pred_node, node->id);

			/*když inkrement je větší než rozdíl toku a propustností, měníme ho za ten rozdil a edge je potencialně hranou min. řezu*/
			if(increment > edge->capacity - edge->flow){
				edge_out = edge;
				increment = edge->capacity - edge->flow;
			}
			node = pred_node;
		} 
		node = find_node(target);

		/*prochazí cestu ještě jednou, zvětšuje tok hran o increment*/
		while(node->pred != -1){
			pred_node = find_node(node->pred);
			edge = find_edge(pred_node, node->id);
			edge->flow += increment;
			node = pred_node;
		} 
		
		/*pokud je nula zastavíme*/
		if(!increment){
			break;
		}

		vector_push_back(out_edges, &edge_out);
		/*zvětšuje maximalní tok sítě o increment*/
		max_flow_graph += increment;
	}
	return max_flow_graph;
}