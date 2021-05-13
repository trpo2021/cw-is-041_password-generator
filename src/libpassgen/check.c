#include "check.h"

bool checkCount(int count)
{
    return count >= 1 && count < 40;
}

bool checkLength(int length)
{
    return length >= 4 && length < 40;
}

bool checkNumber(char* text, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (strchr(array_numbers, text[i]) != NULL) {
            return true;
        }
    }
    return false;
}

bool checkSmallLetter(char* text, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (strchr(array_small_letter, text[i]) != NULL) {
            return true;
        }
    }
    return false;
}

bool checkCapitalLetter(char* text, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (strchr(array_capital_letter, text[i]) != NULL) {
            return true;
        }
    }
    return false;
}

bool checkSpecialSymbol(char* text, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (strchr(array_special_symbol, text[i]) != NULL) {
            return true;
        }
    }
    return false;
}
