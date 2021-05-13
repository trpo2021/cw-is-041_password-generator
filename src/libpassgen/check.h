#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char array_numbers[] = "0123456789";
const char array_small_letter[] = "abcdefghijklmnopqrstuvwxyz";
const char array_capital_letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char array_special_symbol[] = "!#$&\"'()*+,-./:;<=>?@[\\]^_`{|}~";

bool checkCount(int count);
bool checkLength(int length);
bool checkNumber(char* text, size_t size);
bool checkSmallLetter(char* text, size_t size);
bool checkCapitalLetter(char* text, size_t size);
bool checkSpecialSymbol(char* text, size_t size);
