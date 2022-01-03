/**
 * @file vector.h
 * @author František Pártl (fpartl@kiv.zcu.cz)
 * @brief Hlavičkový soubor knihovny dynamicky realokovaného pole.
 * @date 2021-11-25
 */

#ifndef _VECTOR_H
#define _VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/** @brief Násobitel zvětšení pole při realokaci. */
#define VECTOR_SIZE_MULT 2

/** @brief Počáteční velikost vektoru. */
#define VECTOR_INIT_SIZE 4

/**
 * @brief Definice ukazatele na obecnou funkci, která umí uvolnit prvek uložený ve vektoru.
 *        Využívá se ve funkci vector_destroy a vector_at_destroy.
 */
typedef void (*vec_it_dealloc_t)(void **item);

/**
 * @brief Struktura _vector
 * Přestavuje obecné dynamicky alokované pole, do které lze přidávat prvky, manipulovat s nimi a
 * odstraňovat je (včetně jeji uvolnění).
 */
typedef struct _vector_t {
    size_t count;                   /**< Počet prvků vektoru. */
    size_t capacity;                /**< Velikost vektoru. */
    size_t item_size;               /**< Velikost jednoho prvku vektoru. */
    void *data;                     /**< Data obsažené ve vektoru. */
    vec_it_dealloc_t deallocator;   /**< Ukazatel na funkci, která umí uvolnit dynamicky alokované prvky obsažené ve vektoru. */
} vector_t;

/**
 * @brief Alokuje prázdný vektor s kapacitou VECTOR_INIT_SIZE.
 * @param item_size Velikost jednoho prvku vektoru.
 * @return vector* Ukazatel na alokovaný vektor.
 */
vector_t *vector_create(const size_t item_size, const vec_it_dealloc_t deallocator);

/**
 * @brief Funkce provede inicializaci instance struktury vector, která je dána ukazatelem v.
 *        Datový segment bufferu bude prealokován pro VECTOR_INIT_SIZE prvků o velikosti item_size.
 * 
 * @param item_size Velikost jednoho prvku vektoru.
 * @return int 1, pokud se inicializace podařila, jinak 0.
 */
int vector_init(vector_t *v, const size_t item_size, const vec_it_dealloc_t deallocator);

/**
 * @brief Uvolní vektor z paměti. V případě platnosti ukazatele (*v)->deallocator je funkce, na kterou ukazatel odkazuje, zavolána
 *        nad všemi prvky vektoru. Interní pole je pak interpretováno jako pole void *.
 * @param v Ukazatel na vektor.
 */
void vector_destroy(vector_t **v);

/**
 * @brief Funkce zadanému vektoru odebere vlastnictví udržovaného ukazatele na dynamicky
 *        alokovaný buffer. 
 * 
 * @param v Ukazatel na vektor, nad jehož daty přebíráme kontrolu.
 * @return void* Ukazatel na data získaná z vektoru.
 */
void *vector_giveup(vector_t *v);

/**
 * @brief Realokuje zadaný vektor tak, aby jeho kapacita byla size.
 * @param v Realokovaný vektor.
 * @param size Nová kapacita vektoru. 
 * @return int 1, pokud se realokace povedla, jinak 0.
 */
int vector_realloc(vector_t *v, const size_t size);

/**
 * @brief Vrací ukazatel na at-tý prvek vektoru v. V případě neexistence prvku vratí NULL.
 * 
 * @param v Ukazatel na vektor.
 * @param at Index prvku ve vektoru.
 * @return void* Ukazatel na prvek vektoru nebo NULL při neexistenci prvku.
 */
void *vector_at(const vector_t *v, const size_t at);

/**
 * @brief Přidá prvek do vektoru. V případě chyby není vektor daný ukazatel v změněn.
 * @param v Ukazatel na vektor, kam se prvke přidává.
 * @param item Ukazatel na přidávaný prvek.
 * @return int 1, pokud se přidání prvku povedlo, jinak 0.
 */
int vector_push_back(vector_t *v, const void *item);

/**
 * @brief Říká, zda je zadaný vektor prázdný nebo obsahuje nějaké prvky.
 * @param v Ukazatel na vektor.
 * @return int 1, pokud je vektor prázdný, jinak 0.
 */
int vector_isempty(const vector_t *v);

/**
 * @brief Vrátí počet prvků vektoru.
 * @param v Ukazatel na vektor.
 * @return int Počet zapsaných prvků ve vektoru.
 */
size_t vector_count(const vector_t *v);

#endif