#include "../src/libpassgen/check.h"
#include "ctest.h"
#include <stdio.h>
#include <stdlib.h>

CTEST(checkCount, count)
{
    ASSERT_TRUE(checkCount(10));
    ASSERT_FALSE(checkCount(0));
    ASSERT_FALSE(checkCount(50));
    ASSERT_FALSE(checkCount(-10));
}

CTEST(checkLength, length)
{
    ASSERT_TRUE(checkLength(10));
    ASSERT_FALSE(checkLength(1));
    ASSERT_FALSE(checkLength(50));
    ASSERT_FALSE(checkLength(-10));
}

CTEST(checkNumber, numbers)
{
    ASSERT_FALSE(checkNumber("a1", 1));
    ASSERT_FALSE(checkNumber("aa", 2));
    ASSERT_FALSE(checkNumber("1a", 0));
    ASSERT_TRUE(checkNumber("123456", 6));
    ASSERT_TRUE(checkNumber("1a", 2));
    ASSERT_TRUE(checkNumber("12", 2));
    ASSERT_TRUE(checkNumber("/.3456", 6));
    ASSERT_TRUE(checkNumber("a1", 2));
}

CTEST(checkSmallLetter, small_letters)
{
    ASSERT_TRUE(checkSmallLetter("/23ab6", 6));
    ASSERT_FALSE(checkSmallLetter("/23", 3));
    ASSERT_FALSE(checkSmallLetter("SOS", 3));
    ASSERT_TRUE(checkSmallLetter("sab", 3));
    ASSERT_FALSE(checkSmallLetter("/2A", 3));
}

CTEST(checkCapitalLetter, cap_letters)
{
    ASSERT_TRUE(checkCapitalLetter("/2A", 3));
    ASSERT_FALSE(checkCapitalLetter("/23", 3));
    ASSERT_FALSE(checkCapitalLetter("abc", 3));
    ASSERT_TRUE(checkCapitalLetter("SOS", 3));
}

CTEST(checkSpecialSymbol, spsymbol)
{
    ASSERT_FALSE(checkSpecialSymbol("TRPO", 4));
    ASSERT_TRUE(checkSpecialSymbol("\?\?/.", 4));
    ASSERT_FALSE(checkSpecialSymbol("666", 3));
    ASSERT_FALSE(checkSpecialSymbol("ab1A", 3));
}
