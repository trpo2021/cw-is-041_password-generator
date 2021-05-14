#include "../src/libpassgen/passgen.h"
#include "ctest.h"
#include <stdlib.h>

CTEST(generatorPassword, generatorPassword_test1)
{
    password_properties property = initEasyPasswordProperties();

    char *result = generatorPassword(property);

    ASSERT_TRUE(checkSmallLetter(result, property.length));
    ASSERT_FALSE(checkNumber(result, property.length));
    ASSERT_FALSE(checkCapitalLetter(result, property.length));
    ASSERT_FALSE(checkSpecialSymbol(result, property.length));
    ASSERT_TRUE(checkLength(strlen(result)));
    ASSERT_EQUAL(8, strlen(result));
}

CTEST(generatorPassword, generatorPassword_test2)
{
    password_properties property = initMediumPasswordProperties();

    char *result = generatorPassword(property);

    ASSERT_TRUE(checkSmallLetter(result, property.length));
    ASSERT_TRUE(checkNumber(result, property.length));
    ASSERT_TRUE(checkCapitalLetter(result, property.length));
    ASSERT_FALSE(checkSpecialSymbol(result, property.length));
    ASSERT_TRUE(checkLength(strlen(result)));
    ASSERT_EQUAL(8, strlen(result));
}

CTEST(generatorPassword, generatorPassword_test3)
{
    password_properties property = initHardPasswordProperties();

    char *result = generatorPassword(property);

    ASSERT_TRUE(checkSmallLetter(result, property.length));
    ASSERT_TRUE(checkNumber(result, property.length));
    ASSERT_TRUE(checkCapitalLetter(result, property.length));
    ASSERT_TRUE(checkSpecialSymbol(result, property.length));
    ASSERT_TRUE(checkLength(strlen(result)));
    ASSERT_EQUAL(8, strlen(result));
}

CTEST(generatorPassword, generatorPassword_test4)
{
    password_properties property = initEasyPasswordProperties();

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_FALSE(checkNumber(passwords[0], property.length));
    ASSERT_FALSE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[0], property.length));
}

CTEST(generatorPassword, generatorPassword_test5)
{
    password_properties property = initMediumPasswordProperties();

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_FALSE(checkSpecialSymbol(passwords[0], property.length));
}

CTEST(generatorPassword, generatorPassword_test6)
{
    password_properties property = initHardPasswordProperties();

    char** passwords = generatorPasswords(property);

    ASSERT_TRUE(checkSmallLetter(passwords[0], property.length));
    ASSERT_TRUE(checkNumber(passwords[0], property.length));
    ASSERT_TRUE(checkCapitalLetter(passwords[0], property.length));
    ASSERT_TRUE(checkSpecialSymbol(passwords[0], property.length));
}

CTEST(generatorPassword, generatorPassword_test7)
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

CTEST(generatorPassword, generatorPassword_test8)
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

CTEST(generatorPassword, generatorPassword_test9)
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

CTEST(generatorPassword, generatorPassword_test10)
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

CTEST(generatorPassword, generatorPassword_test11)
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

CTEST(generatorPassword, generatorPassword_test12)
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

CTEST(generatorPassword, generatorPassword_test13)
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

CTEST(generatorPassword, generatorPassword_test14)
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

CTEST(generatorPassword, generatorPassword_test15)
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

CTEST(generatorPassword, generatorPassword_test16)
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

CTEST(generatorPassword, generatorPassword_test17)
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

CTEST(generatorPassword, generatorPassword_test18)
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

CTEST(generatorPassword, generatorPassword_test19)
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

CTEST(generatorPassword, generatorPassword_test20)
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
