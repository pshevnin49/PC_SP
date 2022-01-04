

#ifndef _FORDFULKERSON_H
#define _FORDFULKERSON_H

#include <stdio.h>
#include <math.h>
#include "vector.h"
#include "loader.h"
#include "node.h"
#include "edge.h"


extern vector_t *out_edges;

int ford_fulkerson(int source, int sink);

#endif