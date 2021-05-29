#include "passgen.h"

char* generatorPassword(password_properties property)
{
    char* result = malloc(property.length * sizeof(char));

    char* alphabet = malloc(100 * sizeof(char));

    if (property.flag_number) {
        strcat(alphabet, array_numbers);
    }

    if (property.flag_small_letter) {
        strcat(alphabet, array_small_letter);
    }

    if (property.flag_capital_letter) {
        strcat(alphabet, array_capital_letter);
    }

    if (property.flag_special_symbol) {
        strcat(alphabet, array_special_symbol);
    }

    int size_alphabet = strlen(alphabet);
    while (true) {
        for (int i = 0; i < property.length; i++) {
            result[i] = alphabet[rand() % size_alphabet];
        }

        if (property.flag_number) {
            if (!checkNumber(result, property.length)) {
                continue;
            }
        }

        if (property.flag_small_letter) {
            if (!checkSmallLetter(result, property.length)) {
                continue;
            }
        }

        if (property.flag_capital_letter) {
            if (!checkCapitalLetter(result, property.length)) {
                continue;
            }
        }

        if (property.flag_special_symbol) {
            if (!checkSpecialSymbol(result, property.length)) {
                continue;
            }
        }

        break;
    }

    free(alphabet);
    return result;
}

char** generatorPasswords(password_properties property)
{
    char** result = malloc(property.count * sizeof(char*));

    for (int i = 0; i < property.count; i++) {
        result[i] = generatorPassword(property);
    }

    return result;
}

void printPasswords(char** passwords, int count)
{
    for (int i = 0; i < count; i++) {
        printf("%s\n", passwords[i]);
    }
}

void freePasswords(char** passwords, int count)
{
    for (int i = 0; i < count; i++) {
        free(passwords[i]);
    }

    free(passwords);
}
