# File: Makefile
# Author: Jack Duignan (Jackpduignan@gmail.com)
# Breif: Makefile for the morse code simulator project

# Ensure that make is run in powershell to improve compatibility with linux and windows (rm vs del)
ifeq ($(OS),Windows_NT)
SHELL := powershell.exe
.SHELLFLAGS := -NoProfile -Command
endif

# Compiler
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g

# Targets
# Test decodeMorse module
.PHONY: test_decode
test_decode: decodeMorse  
	@./decodeMorseTest

decodeMorse: decodeMorse.o dictionary.o
	$(CC) $(CFLAGS) $^ -o $@ -lm

decodeMorse.o: decodeMorse.c decodeMorse.h ./Cdictionary/dictionary.h
	$(CC) $(CFLAGS) -c $< -o $@

dictionary.o: ./Cdictionary/dictionary.c ./Cdictionary/dictionary.h
	$(CC) $(CFLAGS) -c $< -o $@


# Clean up
.PHONY: clean
clean:
	rm *.o
	rm *.exe
