#pragma once
#include <stdbool.h>
#include <stdio.h>

enum short_option {
    MOD = 'm',
    LENGTH = 'l',
    COUNT = 'c',
    SYMBOLS = 's',
    HELP = 'h'
};

typedef struct {
    int count;
    int length;

    bool flag_number;
    bool flag_capital_letter;
    bool flag_small_letter;
    bool flag_special_symbol;
} password_properties;

password_properties initEasyPasswordProperties();
password_properties initMediumPasswordProperties();
password_properties initHardPasswordProperties();

void setCount(password_properties* property, int count);
void setLength(password_properties* property, int length);
void setNumber(password_properties* property, bool flag_number);
void setCapitalLetter(password_properties* property, bool flag_capital_letter);
void setSmallLetter(password_properties* property, bool flag_small_letter);
void setSpecialSymbol(password_properties* property, bool flag_special_symbol);
bool checkSymbol(password_properties property);
