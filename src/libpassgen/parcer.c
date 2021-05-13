#include "parcer.h"

bool getPasswordProperties(
        password_properties* property, int argc, char* argv[])
{
    const char short_options[]
            = {MOD, ':', LENGTH, ':', SYMBOLS, ':', HELP, COUNT, ':'};
    const struct option long_options[]
            = {{"mod", required_argument, NULL, MOD},
               {"length", required_argument, NULL, LENGTH},
               {"count", required_argument, NULL, COUNT},
               {"help", no_argument, NULL, HELP},
               {"symbols", required_argument, NULL, SYMBOLS},
               {NULL, 0, NULL, 0}};
    char flag;
    int option_index = 0;
    while (true) {
        flag = getopt_long(
                argc, argv, short_options, long_options, &option_index);
        if (flag == -1) {
            break;
        }
        if (flag == '?') {
            return false;
        }
        switch (flag) {
        case MOD: {
            if (strcmp(optarg, "easy") == 0) {
                *property = initEasyPasswordProperties();
                break;
            }
            if (strcmp(optarg, "medium") == 0) {
                *property = initMediumPasswordProperties();
                break;
            }
            if (strcmp(optarg, "hard") == 0) {
                *property = initHardPasswordProperties();
                break;
            }
            printf("Incorrect value mod\n");
            return false;
        }
        case LENGTH: {
            int value = atoi(optarg);
            if (!checkLength(value)) {
                printf("Incorrect value length (1..39)\n");
                return false;
            }
            setLength(&(*property), value);
            break;
        }
        case COUNT: {
            int value = atoi(optarg);
            if (!checkCount(value)) {
                printf("Incorrect value length (1..39)\n");
                return false;
            }
            setCount(&(*property), value);
            break;
        }
        case SYMBOLS: {
            size_t size_optarg = strlen(optarg);
            if (size_optarg > 4) {
                printf("Incorrect value symbols (max 4 symbol)\n");
                return false;
            }
            setNumber(&(*property), checkNumber(optarg, size_optarg));
            setSmallLetter(&(*property), checkSmallLetter(optarg, size_optarg));
            setCapitalLetter(
                    &(*property), checkCapitalLetter(optarg, size_optarg));
            setSpecialSymbol(
                    &(*property), checkSpecialSymbol(optarg, size_optarg));
            if (!checkSymbol(*property)) {
                return false;
            }
            break;
        }
        case HELP: {
            helpInformation();
            return false;
        }
        default: {
            return false;
        }
        }
    }
    return true;
}
