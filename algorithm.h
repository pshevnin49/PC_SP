

#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include <stdio.h>
#include <math.h>
#include "node.h"
#include "edge.h"
#include "loader.h"
#include "vector.h"
#include "bfs.h"

extern vector_t *out_edges;

int ford_fulkerson(int source, int sink);

#endif