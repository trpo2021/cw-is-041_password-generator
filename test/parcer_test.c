#include "../src/libpassgen/parcer.h"
#include "ctest.h"
#include <stdio.h>
#include <stdlib.h>

CTEST(getPasswordProperties, parc_no_argument_test_1)
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

CTEST(getPasswordProperties, parc_small_letters_test_2)
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

CTEST(getPasswordProperties, parc_capital_letters_test_3)
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

CTEST(getPasswordProperties, parc_numbers_test_4)
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

CTEST(getPasswordProperties, parc_sp_simbols_test_5)
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

CTEST(getPasswordProperties, parc_sm_cap_letters_test_6)
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

CTEST(getPasswordProperties, parc_all_no_special_test_7)
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

CTEST(getPasswordProperties, parc_all_test_8)
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

CTEST(getPasswordProperties, parc_cap_special_test_9)
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

CTEST(getPasswordProperties, parc_all_no_cap_test_10)
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

CTEST(getPasswordProperties, parc_3_args_test_11)
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

CTEST(getPasswordProperties, parc_4_args_test_12)
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

CTEST(getPasswordProperties, parc_2_args_test_13)
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

CTEST(getPasswordProperties, parc_2_args_test_14)
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

CTEST(getPasswordProperties, parc_2_args_easy_test_15)
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

CTEST(getPasswordProperties, parc_2_args_medium_test_16)
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

CTEST(getPasswordProperties, parc_2_args_hard_test_17)
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

CTEST(getPasswordProperties, parc_3_args_hard_test_18)
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

CTEST(getPasswordProperties, parc_4_args_hard_test_19)
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

CTEST(getPasswordProperties, parc_3_args_hard_test_20)
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

CTEST(getPasswordProperties, parc_full_l_test_21)
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
CTEST(getPasswordProperties, parc_full_c_test_22)
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
CTEST(getPasswordProperties, parc_incor_l_test_23)
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
CTEST(getPasswordProperties, parc_incor_mod_test_24)
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
CTEST(getPasswordProperties, parc_incor_l_test_25)
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
CTEST(getPasswordProperties, parc_incor_full_c_test_26)
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

CTEST(getPasswordProperties, parc_incor_full_c_test_27)
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

CTEST(getPasswordProperties, parc_full_all_test_28)
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
