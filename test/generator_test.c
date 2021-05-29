#include "../src/libpassgen/passgen.h"
#include "ctest.h"
#include <stdlib.h>

CTEST(generatorPassword, genPassword_easy)
{
    password_properties property = initEasyPasswordProperties();

    char* result = generatorPassword(property);

    ASSERT_TRUE(checkSmallLetter(result, property.length));
    ASSERT_FALSE(checkNumber(result, property.length));
    ASSERT_FALSE(checkCapitalLetter(result, property.length));
    ASSERT_FALSE(checkSpecialSymbol(result, property.length));
    ASSERT_TRUE(checkLength(strlen(result)));
    ASSERT_EQUAL(8, strlen(result));
}

CTEST(generatorPassword, genPassword_medium)
{
    password_properties property = initMediumPasswordProperties();

    char* result = generatorPassword(property);

    ASSERT_TRUE(checkSmallLetter(result, property.length));
    ASSERT_TRUE(checkNumber(result, property.length));
    ASSERT_TRUE(checkCapitalLetter(result, property.length));
    ASSERT_FALSE(checkSpecialSymbol(result, property.length));
    ASSERT_TRUE(checkLength(strlen(result)));
    ASSERT_EQUAL(8, strlen(result));
}

CTEST(generatorPassword, genPassword_hard)
{
    password_properties property = initHardPasswordProperties();

    char* result = generatorPassword(property);

    ASSERT_TRUE(checkSmallLetter(result, property.length));
    ASSERT_TRUE(checkNumber(result, property.length));
    ASSERT_TRUE(checkCapitalLetter(result, property.length));
    ASSERT_TRUE(checkSpecialSymbol(result, property.length));
    ASSERT_TRUE(checkLength(strlen(result)));
    ASSERT_EQUAL(8, strlen(result));
}

CTEST(generatorPassword, genPasswords_easy)
{
    password_properties property = initEasyPasswordProperties();

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_FALSE(checkNumber(passwords[0], property.length));
    ASSERT_FALSE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[0], property.length));
}

CTEST(generatorPassword, genPasswords_medium)
{
    password_properties property = initMediumPasswordProperties();

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[0], property.length));
}

CTEST(generatorPassword, genPasswords_hard)
{
    password_properties property = initHardPasswordProperties();

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[0], property.length));
}

CTEST(generatorPassword, genPasswords_2easy)
{
    password_properties property = initEasyPasswordProperties();
    property.count = 2;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_FALSE(checkNumber(passwords[0], property.length));
    ASSERT_FALSE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[0])));
    ASSERT_EQUAL(8, strlen(passwords[0]));

    ASSERT_TRUE(checkSmallLetter(passwords[1], property.length));
    ASSERT_FALSE(checkNumber(passwords[1], property.length));
    ASSERT_FALSE(checkCapitalLetter(passwords[1], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[1], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[1])));
    ASSERT_EQUAL(8, strlen(passwords[1]));
}

CTEST(generatorPassword, genPasswords_2medium)
{
    password_properties property = initMediumPasswordProperties();
    property.count = 2;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[0])));
    ASSERT_EQUAL(8, strlen(passwords[0]));

    ASSERT_TRUE(checkSmallLetter(passwords[1], property.length));
    ASSERT_TRUE(checkNumber(passwords[1], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[1], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[1], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[1])));
    ASSERT_EQUAL(8, strlen(passwords[1]));
}

CTEST(generatorPassword, genPasswords_2hard)
{
    password_properties property = initHardPasswordProperties();
    property.count = 2;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[0])));
    ASSERT_EQUAL(8, strlen(passwords[0]));

    ASSERT_TRUE(checkSmallLetter(passwords[1], property.length));
    ASSERT_TRUE(checkNumber(passwords[1], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[1], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[1], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[1])));
    ASSERT_EQUAL(8, strlen(passwords[1]));
}

CTEST(generatorPassword, genPasswords_lneasy)
{
    password_properties property = initEasyPasswordProperties();
    property.length = 20;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_FALSE(checkNumber(passwords[0], property.length));
    ASSERT_FALSE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[0])));
    ASSERT_EQUAL(20, strlen(passwords[0]));
}

CTEST(generatorPassword, genPasswords_lnmedium)
{
    password_properties property = initMediumPasswordProperties();
    property.length = 20;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[0])));
    ASSERT_EQUAL(20, strlen(passwords[0]));
}

CTEST(generatorPassword, genPassword_lnhard)
{
    password_properties property = initHardPasswordProperties();
    property.length = 20;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[0])));
    ASSERT_EQUAL(20, strlen(passwords[0]));
}

CTEST(generatorPassword, genPasswords_2lneasy)
{
    password_properties property = initEasyPasswordProperties();
    property.count = 2;
    property.length = 20;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_FALSE(checkNumber(passwords[0], property.length));
    ASSERT_FALSE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[0])));
    ASSERT_EQUAL(20, strlen(passwords[0]));

    ASSERT_TRUE(checkSmallLetter(passwords[1], property.length));
    ASSERT_FALSE(checkNumber(passwords[1], property.length));
    ASSERT_FALSE(checkCapitalLetter(passwords[1], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[1], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[1])));
    ASSERT_EQUAL(20, strlen(passwords[1]));
}

CTEST(generatorPassword, genPasswords_2lnmedium)
{
    password_properties property = initMediumPasswordProperties();
    property.count = 2;
    property.length = 20;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[0])));
    ASSERT_EQUAL(20, strlen(passwords[0]));

    ASSERT_TRUE(checkSmallLetter(passwords[1], property.length));
    ASSERT_TRUE(checkNumber(passwords[1], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[1], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[1], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[1])));
    ASSERT_EQUAL(20, strlen(passwords[1]));
}

CTEST(generatorPassword, genPasswords_2lnhard)
{
    password_properties property = initHardPasswordProperties();
    property.count = 2;
    property.length = 20;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[0])));
    ASSERT_EQUAL(20, strlen(passwords[0]));

    ASSERT_TRUE(checkSmallLetter(passwords[1], property.length));
    ASSERT_TRUE(checkNumber(passwords[1], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[1], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[1], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[1])));
    ASSERT_EQUAL(20, strlen(passwords[1]));
}

CTEST(generatorPassword, genPasswords_enl_c1)
{
    password_properties property = initHardPasswordProperties();
    property.count = 150;
    property.length = 20;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[0])));
    ASSERT_EQUAL(20, strlen(passwords[0]));

    ASSERT_TRUE(checkSmallLetter(passwords[149], property.length));
    ASSERT_TRUE(checkNumber(passwords[149], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[149], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[149], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[149])));
    ASSERT_EQUAL(20, strlen(passwords[149]));
}

CTEST(generatorPassword, genPasswords_enl_c2)
{
    password_properties property = initHardPasswordProperties();
    property.count = 1150;
    property.length = 20;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[0])));
    ASSERT_EQUAL(20, strlen(passwords[0]));

    ASSERT_TRUE(checkSmallLetter(passwords[1149], property.length));
    ASSERT_TRUE(checkNumber(passwords[1149], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[1149], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[1149], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[1149])));
    ASSERT_EQUAL(20, strlen(passwords[1149]));
}

CTEST(generatorPassword, genPasswords_enl_l1)
{
    password_properties property = initHardPasswordProperties();
    property.count = 2;
    property.length = 39;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[0])));
    ASSERT_EQUAL(39, strlen(passwords[0]));

    ASSERT_TRUE(checkSmallLetter(passwords[1], property.length));
    ASSERT_TRUE(checkNumber(passwords[1], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[1], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[1], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[1])));
    ASSERT_EQUAL(39, strlen(passwords[1]));
}

CTEST(generatorPassword, genPasswords_enl_l2)
{
    password_properties property = initHardPasswordProperties();
    property.count = 2;
    property.length = 40;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_FALSE(checkLength(strlen(passwords[0])));

    ASSERT_TRUE(checkSmallLetter(passwords[1], property.length));
    ASSERT_TRUE(checkNumber(passwords[1], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[1], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[1], property.length));
    ASSERT_FALSE(checkLength(strlen(passwords[1])));
}

CTEST(generatorPassword, genPasswords_enl_cl)
{
    password_properties property = initHardPasswordProperties();
    property.count = 1150;
    property.length = 39;

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[0], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[0])));
    ASSERT_EQUAL(39, strlen(passwords[0]));

    ASSERT_TRUE(checkSmallLetter(passwords[1149], property.length));
    ASSERT_TRUE(checkNumber(passwords[1149], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[1149], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[1149], property.length));
    ASSERT_TRUE(checkLength(strlen(passwords[1149])));
    ASSERT_EQUAL(39, strlen(passwords[1149]));
}
