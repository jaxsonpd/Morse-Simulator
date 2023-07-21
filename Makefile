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
test_decode: decodeMorseTest
	@echo == Testing decodeMorse module ==
	@./decodeMorseTest

decodeMorseTest: decodeMorseTest.o decodeMorse.o dictionary.o
	$(CC) $(CFLAGS) $^ -o $@ -lm

decodeMorse.o: decodeMorse.c decodeMorse.h dictionary.h
	$(CC) $(CFLAGS) -c $< -o $@

# Test the dictionary module
.PHONY: test_dictionary
test_dictionary: dictionaryTest
	@echo == Testing dictionary module ==
	@./dictionaryTest

dictionaryTest: dictionaryTest.o dictionary.o
	$(CC) $(CFLAGS) $^ -o $@ -lm

dictionary.o: dictionary.c dictionary.h
	$(CC) $(CFLAGS) -c $< -o $@

dictionaryTest.o: dictionaryTest.c dictionary.o dictionary.h
	$(CC) $(CFLAGS) -c $< -o $@



# Clean up
.PHONY: clean
clean:
	rm -fo *.o
	rm -fo *.exe