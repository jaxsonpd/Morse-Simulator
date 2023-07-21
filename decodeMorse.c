/** 
 * @file decodeMorse.c
 * @brief This module contains functions to decode incoming morse code
 * @author Jack Duignan (Jackpduignan@gmail.com)
 * @date 2023-07-04
 */


// ===================================== Includes =====================================
#include "decodeMorse.h"
#include "dictionary.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// ===================================== Constants ====================================


// ===================================== Globals ======================================


// ===================================== Function Definitions =========================
/** 
 * @brief Decodes a morse code string
 * @param message The morse code string to decode
 * @param size The number of characters in the string
 * 
 * @return the decoded string
 */
char* decodeMorse(char* message, int size) {
    // Create the dictionary
    char* keys[] = {"...", "---"};
    int values[] = {'S', 'O'};
    
    stringIntDict_t* morseDict = stringIntDict_create(keys, values, 2);

    // Create the output string
    char* output = malloc(sizeof(char) * size);

    // Decode the message
    const char delim[2] = " ";

    char* currentMorseChar;
    currentMorseChar = strtok(message, delim);

    int currentIndex = 0;

    while (currentMorseChar != NULL) {

        // Get the current character
        char currentChar = stringIntDict_get(morseDict, currentMorseChar);

        // Add the character to the output string
        output[currentIndex] = currentChar;
        currentIndex++;

        // Get the next morse character
        currentMorseChar = strtok(NULL, delim);
    }

    // Free the dictionary
    stringIntDict_free(morseDict);

    return output;

}

int main(void) {
    char* morse = malloc(sizeof(char) * 80);
    memcpy(morse, "... --- ...", 80); // SOS

    char* decoded = decodeMorse(morse, 3);

    if (strcmp(decoded, "SOS") != 0) {
        printf("SOS decode test failed\n");
    }

	printf("All Tests Passed\n");
}
	
