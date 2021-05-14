#include "libpassgen/passgen.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    srand(time(NULL));

    password_properties property = initMediumPasswordProperties();

    if (getPasswordProperties(&property, argc, argv)) {
        char** passwords = generatorPasswords(property);

        printPasswords(passwords, property.count);
        freePasswords(passwords, property.count);
    }

    return 0;
}
