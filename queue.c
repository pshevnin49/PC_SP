#include "queue.h"

queue_t *queue_create(){
    queue_t *q;
    
    q = (queue_t *)malloc(sizeof(queue_t));
    if (!q){
        return NULL;
    }

    if (!queue_init(q)){
        free(q);
        return NULL;
    }

    return q;
}

int queue_init(queue_t *q){
    if(!q){
        return 0;
    }

    q->begin = 0;
    q->end = 0;
    q->queue = vector_create(sizeof(int), NULL);

    return 1;
}

void in_queue(queue_t *q, int x){
    vector_push_back(q->queue, &x);
    q->end++;
}

int from_queue(queue_t *q){
    int x;
    if(q->begin == q->end){
        return -1;
    }

    x = *(int *)vector_at(q->queue, q->begin);
    q->begin++;
    return x;
}


void queue_destroy(queue_t **poor){
    if(!poor || !*poor){
        return;
    }

    if((*poor)->queue){
        vector_destroy(&(*poor)->queue);
    }
    
    (*poor)->begin = 0;
    (*poor)->end = 0;

    free(*poor);
    *poor = NULL;
}