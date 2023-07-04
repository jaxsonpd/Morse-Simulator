/** 
 * @file dictionary.c
 * @brief This module contains functions for implementing a dictionaries in C
 * @author Jack Duignan (Jackpduignan@gmail.com)
 * @date 2023-07-04
 */


// ===================================== Includes =====================================
#include "dictionary.h"

#include <stdlib.h>
#include <string.h>


// ===================================== Constants ====================================


// ===================================== Types ========================================


// ===================================== Globals ======================================


// ===================================== Function Definitions =========================
/** 
 * @brief Creates a new string to int dictionary
 * @param keys The array of starting keys (can be NULL)
 * @param values The array of starting values (must be NULL if keys is NULL)
 * @param size The size of the starting arrays (must be greater than 0)
 * 
 * @return a pointer to the new dictionary
 */
stringIntDict_t* stringIntDict_create(char** keys, int* values, int size) {
    // Check that the size is valid
    if (size <= 0) {
        return 0;
    }

    // Allocate memory for the dictionary    
    stringIntDict_t* dict = malloc(sizeof(stringIntDict_t));

    dict->keys = malloc(sizeof(char*) * size);
    dict->values = malloc(sizeof(int) * size);

    // Populate the dictionary
    dict->size = size;
    for (int i = 0; i < size; i++) {
        // Only copy the keys if they are not null
        if (keys != 0) {
            dict->keys[i] = keys[i];
        }

        if (values != 0) {
            dict->values[i] = values[i];
        } else {
            dict->values[i] = 0;
        }
    }

    return dict;
}


/** 
 * @brief Returns the value associated with a key
 * @param dict The dictionary to search
 * @param key The key to search for must be contained in the dictionary
 * 
 * @value The value associated with the key
 */
int stringIntDict_get(stringIntDict_t* dict, char* key) {
    // Search for the key
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->keys[i], key) == 0) {
            return dict->values[i];
        }
    }

    // If the key is not found return -1
    return -1;
}

/** 
 * @brief Frees the memory allocated to a dictionary
 * @param dict The dictionary to free
 */
void stringIntDict_free(stringIntDict_t* dict) {
    // Free the keys
    for (int i = 0; i < dict->size; i++) {
        free(dict->keys[i]);
    }

    // Free the values
    free(dict->values);

    // Free the dictionary
    free(dict);
}

