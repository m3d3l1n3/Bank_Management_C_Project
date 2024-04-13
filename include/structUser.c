#define _CRT_SECURE_NO_WARNINGS
#include "structUser.h"
#include <stdlib.h>
#include <string.h>
User initialiseUser(char *name, char *surname)
{
    User currentUser;
    currentUser.name = malloc(strlen(name));
    strcpy(currentUser.name, name);
    currentUser.surname = malloc(strlen(surname));
    strcpy(currentUser.surname, surname);
    return currentUser;
}