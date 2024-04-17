#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include "userManagement.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* createIBAN(char* currency)
{
    char* IBAN = malloc(33);
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
        IBAN[i + 5] = r + '0';
    }
    IBAN[32] = 0;
    return IBAN;
}
char* paddingAmount(char* amount) {
    int l = strlen(amount);
    char* padded = malloc(11);
    for (int i = 0; i < 10 - l; i++) {
        padded[i] = '0';
    }
    padded[10 - l] = 0;
    strcat(padded, amount);
    return padded;
}
char createAccount(User currentUser, char* dataPath, char* currency)
{
    char* userPath = getUserPath(currentUser, dataPath);
    FILE* userFile = fopen(userPath, "a");
    char* IBAN = createIBAN(currency);
    int check = fprintf(userFile, "%s,%s,%s,%d\n", IBAN, currency, paddingAmount("0"), 1);
    fclose(userFile);
    if (check > 0)
        return 1;
    else
        return 0;
}

char deleteAccount(User currentUser, char* dataPath, char* IBAN)
{
    char* userPath = getUserPath(currentUser, dataPath);
    int lineSize = strlen(currentUser.name) + strlen(currentUser.surname) + 50;
    char* line = malloc(lineSize);
    FILE* userFile = fopen(userPath, "r+");
    int position = 0, lastPosition;
    while (fgets(line, lineSize, userFile)) {
        lastPosition = position;
        position = ftell(userFile);
        char* tmp = strtok(line, ",");
        char splitLine[4][34];
        int i = 0;
        while (tmp) {
            strcpy(splitLine[i], tmp);
            i++;
            tmp = strtok(NULL, ",");
        }
        printf("%s\n%s\n", splitLine[0], IBAN);
        if (strcmp(splitLine[0], IBAN) == 0) {
            fseek(userFile, lastPosition, SEEK_SET);
            fprintf(userFile, "%s,%s,%s,%d\n", splitLine[0], splitLine[1], paddingAmount(splitLine[2]), 0);
            fclose(userFile);
            return 1;
        }
    }
    fclose(userFile);
    return 0;
}

void showAccounts(User currentUser, char* dataPath) {
    char* userPath = getUserPath(currentUser, dataPath);
    int lineSize = strlen(currentUser.name) + strlen(currentUser.surname) + 50;
    char* line = malloc(lineSize);
    FILE* userFile = fopen(userPath, "r");
    while (fgets(line, lineSize, userFile)) {
        char* tmp = strtok(line, ",");
        char splitLine[4][34];
        int i = 0;
        while (tmp) {
            strcpy(splitLine[i], tmp);
            i++;
            tmp = strtok(NULL, ",");
        }
        if (splitLine[3][0] != '0') {
            printf("IBAN: %s, Currency: %s, Amount: %d\n", splitLine[0], splitLine[1], atoi(splitLine[2]));
        }
    }
    fclose(userFile);
}

char editAccount(User currentUser, char* dataPath, char* IBAN, char modifiableData, char* newData) {
    char* userPath = getUserPath(currentUser, dataPath);
    int lineSize = strlen(currentUser.name) + strlen(currentUser.surname) + 50;
    char* line = malloc(lineSize);
    FILE* userFile = fopen(userPath, "r+");
    int position = 0, lastPosition;
    while (fgets(line, lineSize, userFile)) {
        lastPosition = position;
        position = ftell(userFile);
        char* tmp = strtok(line, ",");
        char splitLine[4][34];
        int i = 0;
        while (tmp) {
            strcpy(splitLine[i], tmp);
            i++;
            tmp = strtok(NULL, ",");
        }

        if (strcmp(splitLine[0], IBAN) == 0) {
            fseek(userFile, lastPosition, SEEK_SET);
            switch (modifiableData)
            {
            case 1:
                strcpy(splitLine[0], newData);
                break;
            case 2:
                strcpy(splitLine[1], newData);
                break;
            case 3:
                int newAddedSum = atoi(splitLine[2]);
                newAddedSum += atoi(newData);
                char stringAddedSum[11];
                itoa(newAddedSum, stringAddedSum, 10);
                strcpy(splitLine[2], stringAddedSum);
                break;
            case 4:
                int newSubstractedSum = atoi(splitLine[2]);
                newSubstractedSum -= atoi(newData);
                if (newSubstractedSum >= 0)
                {
                    char stringSubstractedSum[11];
                    itoa(newSubstractedSum, stringSubstractedSum, 10);
                    strcpy(splitLine[2], stringSubstractedSum);
                }
                else return 2;
                break;
            }
            fprintf(userFile, "%s,%s,%s,%d\n", splitLine[0], splitLine[1], paddingAmount(splitLine[2]), 1);
            fclose(userFile);
            return 1;
        }
    }
    fclose(userFile);
    return 0;
}

