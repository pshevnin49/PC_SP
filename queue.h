/**
 * @file queue.h
 * @author Pavel Shevnin
 * @brief Jednoduchá implementace frontý pomocí vektoru. Vkladá prvkí na konec a beré od začátku.
 * @version 1.0
 * @date 2021-12-30
 * 
 */
#ifndef _QUEUE_H
#define _QUEUE_H

#include "vector.h"
/**
 * @brief struktura queue_t fronta. 
 * Má konec začatek a vektor prvků tipu int
 * 
 */
typedef struct _queue {
  vector_t *queue;
  int begin, end;
} queue_t;
/**
 * @brief Alokuje prázdnou frontu pro prvky typu int
 * 
 */
queue_t *queue_create();

/**
 * @brief Funkce provede inicializaci instance struktury queue, která je dána ukazatelem
 * 
 * @param q ukazatel
 * @return int vrací 1 v případě uspěchu 0 v případě když fronta nebýla inicializovaná
 */
int queue_init(queue_t *q);

/**
 * @brief Vkladá prvék do frontý
 * 
 * @param q ukazatel na frontu
 * @param x prvék který budé do frontý vložen
 */
void in_queue(queue_t *q, int x);

/**
 * @brief Odstraňuje ze frontý a vrácí první element
 * 
 * @param q ukazatel
 * @return int prxní element fronty
 */
int from_queue(queue_t *q);

/**
 * @brief Kontroluje je li fronta prázdna
 * 
 * @return int 0 pokud je plna, 1 pokud je prázdna
 */
int queue_is_empty(queue_t *q);

/**
 * @brief Uvolní frontu z paměti.
 * @param v Ukazatel na frontu
 */
void queue_destroy(queue_t **poor);

#endif