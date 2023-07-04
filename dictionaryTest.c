/** 
 * @file dictionaryTest.c
 * @brief This module contains tests for the dictionary module 
 * @author Jack Duignan (Jackpduignan@gmail.com)
 * @date 2023-07-04
 */


// ===================================== Includes =====================================
#include "dictionary.h"

#include <stdio.h>

// ===================================== Constants ====================================


// ===================================== Globals ======================================


// ===================================== Function Definitions =========================
int main(void) {
    /* stringIntDict_t Testing */
    // Test creating a dictionary
    char* keys[] = {"a", "b", "c"};
    int values[] = {1, 2, 3};

    stringIntDict_t* stringIntDict = stringIntDict_create(keys, values, 3);

    // Print the size of the dictionary
    printf("Size of stringIntDict: %d\n", stringIntDict->size);

    // Print the values of the dictionary
    for (int i = 0; i < stringIntDict->size; i++) {
        printf("Key: %s, Value: %d\n", stringIntDict->keys[i], stringIntDict->values[i]);
    }

    // Test getting a value from the dictionary
    printf("Value of key 'b': %d\n", stringIntDict_get(stringIntDict, "b"));

    // Free the dictionary
    stringIntDict_free(stringIntDict);

    printf("!! String to Int Dictionary Tests Passed\n");
}