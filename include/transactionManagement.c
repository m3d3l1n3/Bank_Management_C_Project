#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#define INVALID_HANDLE_VALUE

#include <Windows.h>
#include "transactionManagement.h"
#include "accountManagement.h"
#include "userManagement.h"
#include "accountManagement.h"
#include <fileapi.h>
#include <stdio.h>

char updateDestinationFile(char* dataPath, char* destinationIBAN, char* amount) {
    HANDLE hFind;
    WIN32_FIND_DATA FindFileData;
    char* prefix = "clientAccounts\\";
    char* wildCard = malloc(strlen(dataPath) + strlen(prefix) + 5);
    strcpy(wildCard, dataPath);
    strcat(wildCard, prefix);
    strcat(wildCard, "*.csv");
    /// printf("%s\n", wildCard);
    if ((hFind = FindFirstFile(wildCard, &FindFileData)) != INVALID_HANDLE_VALUE) {
        do {
            // printf("%s\n", FindFileData.cFileName);
            char* userPath = malloc(strlen(dataPath) + strlen(prefix) + strlen(FindFileData.cFileName));
            strcpy(userPath, dataPath);
            strcat(userPath, prefix);
            strcat(userPath, FindFileData.cFileName);

            int lineSize = strlen(FindFileData.cFileName) + 51;
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
                //printf("%s\n%s\n", splitLine[0], IBAN);
                if (strcmp(splitLine[0], destinationIBAN) == 0) {
                    fseek(userFile, lastPosition, SEEK_SET);
                    int newAddedSum = atoi(splitLine[2]);

                    newAddedSum += atoi(amount);
                    char stringAddedSum[11];
                    itoa(newAddedSum, stringAddedSum, 10);
                    strcpy(splitLine[2], stringAddedSum);
                    fprintf(userFile, "%s,%s,%s,%d\n", splitLine[0], splitLine[1], paddingAmount(stringAddedSum), 1);
                    fclose(userFile);
                    return 1;
                }
            }
        } while (FindNextFile(hFind, &FindFileData));
        FindClose(hFind);
    }
    return 0;
}

char sendMoney(User currentUser, char* dataPath, char* sourceIBAN, char* destinationIBAN, char* amount) {
    char* userPath = getUserPath(currentUser, dataPath);
    int editRes = editAccount(currentUser, dataPath, sourceIBAN, 4, amount);
    if (editRes == 0)
        return 0;
    else if (editRes == 1) {
        if (updateDestinationFile(dataPath, destinationIBAN, amount))
            return 1;
    }
    return 0;
}

char depositMoney(User currentUser, char* dataPath, char* IBAN, char* sum) {
    if (editAccount(currentUser, dataPath, IBAN, 3, sum))
        return 1;
    else return 0;
}

