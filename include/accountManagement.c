#define _CRT_SECURE_NO_WARNINGS
#include "accountManagement.h"
#include "structUser.h"
#include "pathUtilises.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getUserPath(User currentUser, char *dataPath)
{
    char *prefix = "clientAccounts\\";
    char *filePath = malloc(strlen(dataPath) + strlen(currentUser.name) + strlen(currentUser.surname) + strlen(prefix) + 3);
    filePath[0] = '\0';
    strcpy(filePath, dataPath);
    strcat(filePath, prefix);
    strcat(filePath, currentUser.name);
    strcat(filePath, currentUser.surname);
    strcat(filePath, ".csv");
    return filePath;
}

char fileExists(User currentUser, char *dataPath)
{
    char *filePath = getUserPath(currentUser, dataPath);
    FILE *f;
    if ((f = fopen(filePath, "r")))
        return 1;
    else
        return 0;
}

char loginUser(User currentUser, char *dataPath)
{
    char exists = fileExists(currentUser, dataPath);
    if (exists == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char registerUser(User currentUser, char *dataPath)
{
    char *filePath = getUserPath(currentUser, dataPath);
    FILE *f;
    if (!(f = fopen(filePath, "r")))
    {
        f = fopen(filePath, "w");
        fclose(f);
        return 1;
    }
    else
        return 0;
}