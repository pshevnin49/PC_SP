#ifndef _OUT_FILE_H
#define _OUT_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "node.h"
#include "vector.h"
#include "loader.h"
#include "ford_fulkerson.h"
#include "parameters.h"

#define WRITE "w"

int out_write(char *name);

#endif