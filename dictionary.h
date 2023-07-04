/** 
 * @file dictionary.h
 * @brief Header file for dictionary.c
 * @author Jack Duignan (Jackpduignan@gmail.com)
 * @date 2023-07-04
 */


#ifndef DICTIONARY_H
#define DICTIONARY_H


// ===================================== Includes =====================================


// ===================================== Constants ====================================


// ===================================== Types ========================================
// The string to int dictionary type
typedef struct stringIntDict_t {
    char** keys;
    int* values;
    int size;
} stringIntDict_t;

// ===================================== Function Prototypes ==========================
stringIntDict_t* stringIntDict_create(char** keys, int* values, int size);
void stringIntDict_free(stringIntDict_t* dict);
int stringIntDict_get(stringIntDict_t* dict, char* key);


#endif // DICTIONARY_H