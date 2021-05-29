#include "../src/libpassgen/passgen.h"
#include "ctest.h"
#include <stdlib.h>

CTEST(initEasyPasswordProperties, pass_properties_easy)
{
    password_properties property = initEasyPasswordProperties();
    ASSERT_EQUAL(1, property.count);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(false, property.flag_number);
    ASSERT_EQUAL(false, property.flag_capital_letter);
    ASSERT_EQUAL(true, property.flag_small_letter);
    ASSERT_EQUAL(false, property.flag_special_symbol);
}

CTEST(initMediumPasswordProperties, pass_properties_medium)
{
    password_properties property = initMediumPasswordProperties();
    ASSERT_EQUAL(1, property.count);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(true, property.flag_number);
    ASSERT_EQUAL(true, property.flag_capital_letter);
    ASSERT_EQUAL(true, property.flag_small_letter);
    ASSERT_EQUAL(false, property.flag_special_symbol);
}

CTEST(initHardPasswordProperties, pass_properties_hard)
{
    password_properties property = initHardPasswordProperties();
    ASSERT_EQUAL(1, property.count);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(true, property.flag_number);
    ASSERT_EQUAL(true, property.flag_capital_letter);
    ASSERT_EQUAL(true, property.flag_small_letter);
    ASSERT_EQUAL(true, property.flag_special_symbol);
}
