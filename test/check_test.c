#include "../src/libpassgen/check.h"
#include "ctest.h"
#include <stdio.h>
#include <stdlib.h>

CTEST(checkCount, count_test_1)
{
    int count = 10;

    ASSERT_TRUE(checkCount(count));
}

CTEST(checkCount, count_test_2)
{
    int count = 50;

    ASSERT_FALSE(checkCount(count));
}

CTEST(checkCount, count_test_3)
{
    int count = 0;

    ASSERT_FALSE(checkCount(count));
}

CTEST(checkCount, count_test_4)
{
    int count = -10;

    ASSERT_FALSE(checkCount(count));
}

CTEST(checkLength, length_test_1)
{
    int length = 10;

    ASSERT_TRUE(checkLength(length));
}

CTEST(checkLength, length_test_2)
{
    int length = 1;

    ASSERT_FALSE(checkLength(length));
}

CTEST(checkLength, length_test_3)
{
    int length = 50;

    ASSERT_FALSE(checkLength(length));
}

CTEST(checkLength, length_test_4)
{
    int length = -10;

    ASSERT_FALSE(checkLength(length));
}

CTEST(checkNumber, numbers_test_1)
{
    int size = 1;
    char text[] = {'a', '1'};

    ASSERT_FALSE(checkNumber(text, size));
}

CTEST(checkNumber, numbers_test_2)
{
    int size = 2;
    char text[] = {'a', 'a'};

    ASSERT_FALSE(checkNumber(text, size));
}

CTEST(checkNumber, numbers_test_3)
{
    int size = 0;
    char text[] = {'1', 'a'};

    ASSERT_FALSE(checkNumber(text, size));
}

CTEST(checkNumber, numbers_test_4)
{
    int size = 6;
    char text[] = {
            '1',
            '2',
            '3',
            '4',
            '5',
            '6',
    };

    ASSERT_TRUE(checkNumber(text, size));
}

CTEST(checkNumber, numbers_test_5)
{
    int size = 2;
    char text[] = {'1', 'a'};

    ASSERT_TRUE(checkNumber(text, size));
}

CTEST(checkNumber, numbers_test_6)
{
    int size = 2;
    char text[] = {'1', '2'};

    ASSERT_TRUE(checkNumber(text, size));
}

CTEST(checkNumber, numbers_test_7)
{
    int size = 6;
    char text[] = {
            '/',
            '.',
            '3',
            '4',
            '5',
            '6',
    };

    ASSERT_TRUE(checkNumber(text, size));
}

CTEST(checkNumber, numbers_test_8)
{
    int size = 2;
    char text[] = {'a', '1'};

    ASSERT_TRUE(checkNumber(text, size));
}

CTEST(checkSmallLetter, smallletters1)
{
    int size = 6;
    char text[] = {
            '/',
            '2',
            '3',
            'a',
            'b',
            '6',
    };

    ASSERT_TRUE(checkSmallLetter(text, size));
}

CTEST(checkSmallLetter, small_letters_test_2)
{
    int size = 3;
    char text[] = {
            '/',
            '2',
            '3',
    };

    ASSERT_FALSE(checkSmallLetter(text, size));
}

CTEST(checkSmallLetter, small_letters_test_3)
{
    int size = 3;
    char text[] = {
            'S',
            'O',
            'S',
    };

    ASSERT_FALSE(checkSmallLetter(text, size));
}

CTEST(checkSmallLetter, small_letters_test_4)
{
    int size = 3;
    char text[] = {
            's',
            'a',
            'b',
    };

    ASSERT_TRUE(checkSmallLetter(text, size));
}

CTEST(checkSmallLetter, small_letters_test_5)
{
    int size = 3;
    char text[] = {
            '/',
            '2',
            'A',
    };

    ASSERT_FALSE(checkSmallLetter(text, size));
}

CTEST(checkCapitalLetter, cap_letters_test_1)
{
    int size = 3;
    char text[] = {
            '/',
            '2',
            'A',
    };

    ASSERT_TRUE(checkCapitalLetter(text, size));
}

CTEST(checkCapitalLetter, cap_letters_test_2)
{
    int size = 3;
    char text[] = {
            '/',
            '2',
            '3',
    };

    ASSERT_FALSE(checkCapitalLetter(text, size));
}

CTEST(checkCapitalLetter, cap_letters_test_3)
{
    int size = 3;
    char text[] = {
            'a',
            'b',
            'c',
    };

    ASSERT_FALSE(checkCapitalLetter(text, size));
}

CTEST(checkCapitalLetter, cap_letters_test_4)
{
    int size = 3;
    char text[] = {
            'S',
            'O',
            'S',
    };

    ASSERT_TRUE(checkCapitalLetter(text, size));
}

CTEST(checkSpecialSymbol, spsymbol_test_1)
{
    int size = 4;
    char text[] = {
            'T',
            'R',
            'P',
            'O',
    };

    ASSERT_FALSE(checkSpecialSymbol(text, size));
}

CTEST(checkSpecialSymbol, spsymbol_test_2)
{
    int size = 4;
    char text[] = {
            '?',
            '?',
            '/',
            '.',
    };

    ASSERT_TRUE(checkSpecialSymbol(text, size));
}

CTEST(checkSpecialSymbol, spsymbol_test_3)
{
    int size = 3;
    char text[] = {
            '6',
            '6',
            '6',
    };

    ASSERT_FALSE(checkSpecialSymbol(text, size));
}

CTEST(checkSpecialSymbol, spsymbol_test_4)
{
    int size = 3;
    char text[] = {
            'a',
            'b',
            '1',
            'A',
    };

    ASSERT_FALSE(checkSpecialSymbol(text, size));
}
