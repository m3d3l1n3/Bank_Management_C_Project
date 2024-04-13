#define _CRT_SECURE_NO_WARNINGS
#include "pathUtilises.h"
#include <string.h>
#include <stdlib.h>

char *getDataPath(char *executablePath)
{
    char *filePath = malloc(strlen(executablePath) + 5);
    strcpy(filePath, "\0");
    char *tmp = strtok(executablePath, "\\");
    while (tmp)
    {
        if (strstr(tmp, ".exe") == NULL)
        {
            strcat(filePath, tmp);
            strcat(filePath, "\\");
        }
        tmp = strtok(NULL, "\\");
    }
    strcat(filePath, "data\\");
    return filePath;
}