/**
 * @file bfs.h
 * @author Pavel Shevnin
 * @brief Soubor obsahujicí BFS (prohledávaní do šiřky) který hleda cestu v grafu,  
 * @version 1.2
 * @date 2021-12-27
 * 
 */
#ifndef _BFS_H
#define _BFS_H

#include <stdio.h>
#include <math.h>
#include "node.h"
#include "edge.h"
#include "loader.h"
#include "vector.h"

#define WHITE 0
#define GREY 1
#define BLACK 2
#define O 1000000000

extern vector_t *q;

void in_q(int x);

int from_q();

edge_t *find_edge(node_t *node_from, int to);

node_t *find_node(int id);

int bfs(int start, int target);

#endif