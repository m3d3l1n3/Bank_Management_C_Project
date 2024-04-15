#define _CRT_SECURE_NO_WARNINGS
#include "userManagement.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *createIBAN(char *currency)
{
    char *IBAN = malloc(33);
    strcpy(IBAN, "RO45MG");
    if (strcmp(currency, "RON"))
    {
        strcat(IBAN, "10");
    }
    if (strcmp(currency, "USD"))
    {
        strcat(IBAN, "12");
    }
    if (strcmp(currency, "EUR"))
    {
        strcat(IBAN, "14");
    }
    for (int i = 1; i <= 26; i++)
    {
        char r = rand() % 10;
        IBAN[i + 5] = r + 48;
    }
    return IBAN;
}

char createAccount(User currentUser, char *dataPath, char *currency)
{
    char *userPath = getUserPath(currentUser, dataPath);
    FILE *userFile = fopen(userPath, "a");
    char *IBAN = createIBAN(currency);
    int check = fprintf(userFile, "%s,%s,%d,%d\n", IBAN, currency, 0, 1);
    fclose(userFile);
    if (check > 0)
        return 1;
    else
        return 0;
}

char deleteAccount(User currentUser, char *dataPath, char *IBAN)
{
    char *userPath = getUserPath(currentUser, dataPath);
    FILE *userFile = fopen(userPath, "a");
    int lineSize = strlen(currentUser.name);
    int check = fprintf(userFile, "%s,%s,%d,%d\n", IBAN, "currency", 0, 1);
    fclose(userFile);
    return 0;
}