#pragma once
#include "const.h"
#include <stdbool.h>
#include <string.h>

bool checkCount(int count);
bool checkLength(int length);
bool checkNumber(char* text, size_t size);
bool checkSmallLetter(char* text, size_t size);
bool checkCapitalLetter(char* text, size_t size);
bool checkSpecialSymbol(char* text, size_t size);
