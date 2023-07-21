/** 
 * @file decodeMorseTest.c
 * @brief This module contains functions for testing the decodeMorse module
 * @author Jack Duignan (Jackpduignan@gmail.com)
 * @date 2023-07-04
 */


// ===================================== Includes =====================================
#include "decodeMorse.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ===================================== Constants ====================================


// ===================================== Globals ======================================


// ===================================== Function Definitions =========================
int main() {
    /* Test the decode morse module */

    // == Test 1 ==
    printf("Starting Test 1\n");
    char* morse = malloc(sizeof(char) * 80);
    memcpy(morse, "... --- ...", 80); // SOS

    printf("Test 1: %s\n", morse);

    char* decoded = decodeMorse(morse, 3);

    printf("Decoded: %s\n", decoded);

    if (strcmp(decoded, "SOS") == 0) {
        printf("Test 1 passed\n");
    } else {
        printf("Test 1 failed\n");
    }


}