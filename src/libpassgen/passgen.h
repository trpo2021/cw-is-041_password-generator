#pragma once
#include "check.h"
#include "helpInform.h"
#include "parcer.h"
#include "password_properties.h"

char* generatorPassword(password_properties property);
char** generatorPasswords(password_properties property);
