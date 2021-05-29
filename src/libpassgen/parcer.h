#pragma once
#include "check.h"
#include "helpInform.h"
#include "password_properties.h"
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool getPasswordProperties(
        password_properties* property, int argc, char* argv[]);
