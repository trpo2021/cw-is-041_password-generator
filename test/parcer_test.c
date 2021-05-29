#include "../src/libpassgen/parcer.h"
#include "ctest.h"
#include <stdio.h>
#include <stdlib.h>

CTEST(getPasswordProperties, parc_no_argument)
{
    password_properties property = initMediumPasswordProperties();
    char* argv = "./exe";
    int argc = 1;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, &argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_FALSE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_small_letters)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "-sa"};
    int argc = 2;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_FALSE(property.flag_capital_letter);
    ASSERT_FALSE(property.flag_special_symbol);
    ASSERT_FALSE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_capital_letters)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "-sA"};
    int argc = 2;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_FALSE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_FALSE(property.flag_special_symbol);
    ASSERT_FALSE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_numbers)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "-s1"};
    int argc = 2;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_FALSE(property.flag_small_letter);
    ASSERT_FALSE(property.flag_capital_letter);
    ASSERT_FALSE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_sp_simbols)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "-s!"};
    int argc = 2;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_FALSE(property.flag_small_letter);
    ASSERT_FALSE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_FALSE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_sm_cap_letters)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "-sAa"};
    int argc = 2;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_FALSE(property.flag_special_symbol);
    ASSERT_FALSE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_all_no_special)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "-sAa0"};
    int argc = 2;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_FALSE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_all)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "-sAa4/"};
    int argc = 2;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_cap_special)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "-sA!"};
    int argc = 2;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_FALSE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_FALSE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_all_no_cap)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "-s!a8"};
    int argc = 2;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_FALSE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_3_args)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "-s!a8", "-l10"};
    int argc = 3;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_FALSE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(10, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_4_args)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "-s!a8", "-l10", "-c8"};
    int argc = 4;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_FALSE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(10, property.length);
    ASSERT_EQUAL(8, property.count);
}

CTEST(getPasswordProperties, parc_2_args_l)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "-l10"};
    int argc = 2;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_FALSE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(10, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_2_args_c)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "-c10"};
    int argc = 2;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_FALSE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(10, property.count);
}

CTEST(getPasswordProperties, parc_2_args_easy)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--mod=easy"};
    int argc = 3;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_FALSE(property.flag_capital_letter);
    ASSERT_FALSE(property.flag_special_symbol);
    ASSERT_FALSE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_2_args_medium)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--mod=medium"};
    int argc = 3;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_FALSE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_2_args_hard)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--mod=hard"};
    int argc = 3;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_3_args_hard_c)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--mod=hard", "-c10"};
    int argc = 3;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(10, property.count);
}

CTEST(getPasswordProperties, parc_4_args_hard)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--mod=hard", "-l10", "-c15"};
    int argc = 4;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(10, property.length);
    ASSERT_EQUAL(15, property.count);
}

CTEST(getPasswordProperties, parc_3_args_hard_l)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--mod=hard", "-l10"};
    int argc = 3;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(10, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_long_l)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--mod=hard", "--length=10"};
    int argc = 3;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(10, property.length);
    ASSERT_EQUAL(1, property.count);
}
CTEST(getPasswordProperties, parc_long_c)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--mod=hard", "--count=10"};
    int argc = 3;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(10, property.count);
}
CTEST(getPasswordProperties, parc_incor_l_)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--mod=hard", "--l10"};
    int argc = 3;

    int base_optind = optind;
    ASSERT_FALSE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}
CTEST(getPasswordProperties, parc_incor_mod)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--modhard", "-l10"};
    int argc = 3;

    int base_optind = optind;
    ASSERT_FALSE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_FALSE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}
CTEST(getPasswordProperties, parc_incor_l)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--mod=hard", "-l=10"};
    int argc = 3;

    int base_optind = optind;
    ASSERT_FALSE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}
CTEST(getPasswordProperties, parc_incor_full_c)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--mod=hard", "-count10"};
    int argc = 3;

    int base_optind = optind;
    ASSERT_FALSE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_TRUE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_incor_full_c_)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--symbols=Aa0", "-count10"};
    int argc = 3;

    int base_optind = optind;
    ASSERT_FALSE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_FALSE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(8, property.length);
    ASSERT_EQUAL(1, property.count);
}

CTEST(getPasswordProperties, parc_full_all)
{
    password_properties property = initMediumPasswordProperties();
    char* argv[] = {"./exe", "--symbols=Aa0", "--length=10", "--count=10"};
    int argc = 4;

    int base_optind = optind;
    ASSERT_TRUE(getPasswordProperties(&property, argc, argv));
    optind = base_optind;

    ASSERT_TRUE(property.flag_small_letter);
    ASSERT_TRUE(property.flag_capital_letter);
    ASSERT_FALSE(property.flag_special_symbol);
    ASSERT_TRUE(property.flag_number);
    ASSERT_EQUAL(10, property.length);
    ASSERT_EQUAL(10, property.count);
}
