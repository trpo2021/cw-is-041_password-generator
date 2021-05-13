#include "password_properties.h"

password_properties initEasyPasswordProperties()
{
    password_properties property
            = {.count = 1,
               .length = 8,
               .flag_number = false,
               .flag_capital_letter = false,
               .flag_small_letter = true,
               .flag_special_symbol = false};

    return property;
}
password_properties initMediumPasswordProperties()
{
    password_properties property
            = {.count = 1,
               .length = 8,
               .flag_number = true,
               .flag_capital_letter = true,
               .flag_small_letter = true,
               .flag_special_symbol = false};

    return property;
}
password_properties initHardPasswordProperties()
{
    password_properties property
            = {.count = 1,
               .length = 8,
               .flag_number = true,
               .flag_capital_letter = true,
               .flag_small_letter = true,
               .flag_special_symbol = true};

    return property;
}
void setCount(password_properties* property, int count)
{
    property->count = count;
}
void setLength(password_properties* property, int length)
{
    property->length = length;
}
void setNumber(password_properties* property, bool flag_number)
{
    property->flag_number = flag_number;
}
void setCapitalLetter(password_properties* property, bool flag_capital_letter)
{
    property->flag_capital_letter = flag_capital_letter;
}
void setSmallLetter(password_properties* property, bool flag_small_letter)
{
    property->flag_small_letter = flag_small_letter;
}
void setSpecialSymbol(password_properties* property, bool flag_special_symbol)
{
    property->flag_special_symbol = flag_special_symbol;
}
bool checkSymbol(password_properties property)
{
    return property.flag_capital_letter + property.flag_number
            + property.flag_small_letter + property.flag_special_symbol;
}
