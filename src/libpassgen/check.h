#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"

bool checkCount(int count);
bool checkLength(int length);
bool checkNumber(char* text, size_t size);
bool checkSmallLetter(char* text, size_t size);
bool checkCapitalLetter(char* text, size_t size);
bool checkSpecialSymbol(char* text, size_t size);
