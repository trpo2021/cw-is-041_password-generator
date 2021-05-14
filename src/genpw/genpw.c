#include "libpassgen/passgen.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    srand(time(NULL));

    password_properties property = initMediumPasswordProperties();

    if (getPasswordProperties(&property, argc, argv)) {
        char** passwords = generatorPasswords(property);

        for (int i = 0; i < property.count; i++) {
            printf("%s\n", passwords[i]);
        }

        for (int i = 0; i < property.count; i++) {
            free(passwords[i]);
        }

        free(passwords);
    }

    return 0;
}
