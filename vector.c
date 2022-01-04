#include "vector.h"

vector_t *vector_create(const size_t item_size, const vec_it_dealloc_t deallocator){
    vector_t *v;

    if (item_size == 0){
        return NULL;
    }

    v = (vector_t *)malloc(sizeof(vector_t));
    if (!v){
        return NULL;
    }

    if (!vector_init(v, item_size, deallocator)){
        free(v);
        return NULL;
    }

    return v;
}

int vector_init(vector_t *v, const size_t item_size, const vec_it_dealloc_t deallocator){
    if (!v || item_size == 0){
        return 0;
    }

    v->count = 0;
    v->capacity = 0;
    v->item_size = item_size;
    v->data = NULL;
    v->deallocator = deallocator;

    if (!vector_realloc(v, VECTOR_INIT_SIZE)){
        return 0;
    }

    /* Pro případ, že obsahem vectoru bude řetězec znaků. */
    ((char *)v->data)[0] = 0;

    return 1;
}

void vector_destroy(vector_t **v){
    size_t a;

    if (!v || !*v){
        return;
    }

    /* 
        Pokud je nastaven vlastní dealokátor, tak je pole iterpretováno jako pole ukazatelů na dynamicky alokované
        instance struktur. Nad všemi těmito ukazateli je pak uvedený dealokátor zavolán.
    */
    if ((*v)->deallocator){
        for (a = 0; a < (*v)->count; ++a){
            /* Pointerová aritmetika zde funguje, protože kompilátor ví, jaká je velikost typu void *. */
            ((*v)->deallocator)((void **)((*v)->data) + a); /* Jedná se funkční volání! Trošku maskované, ale ja tam. ;-) */
        }
    }

    if ((*v)->data){
        free((*v)->data);
    }

    free(*v);
    *v = NULL;
}

void *vector_giveup(vector_t *v){
    void *data;

    if (!v || vector_isempty(v)){
        return NULL;
    }

    data = v->data;

    vector_init(v, v->item_size, v->deallocator);
    return data;
}

int vector_realloc(vector_t *v, const size_t size){
    void *data_temp;

    if (!v || size <= v->count){
        return 0;
    }

    data_temp = realloc(v->data, v->item_size * size);
    if (!data_temp){
        return 0;
    }

    v->capacity = size;
    v->data = data_temp;
    return 1;
}

void *vector_at(const vector_t *v, const size_t at){
    if (!v || at > v->count - 1){      /* Jinak bychom sáhli za okraj vektoru. */
        return NULL;        
    }
    return (void *)((char *)v->data + (at * v->item_size));
}

int vector_push_back(vector_t *v, const void *item){
    if (!v || !item){
        return 0;
    }

    if (v->count == v->capacity){
        if (!vector_realloc(v, v->capacity * VECTOR_SIZE_MULT)){
            return 0;
        }
    }

    memcpy((void *)((char *)v->data + (v->count * v->item_size)), item, v->item_size);
    
    v->count++;
    return 1;
}

int vector_isempty(const vector_t *v){
    return !v || vector_count(v) == 0;
}

size_t vector_count(const vector_t *v){
    return v ? v->count : 0;
}