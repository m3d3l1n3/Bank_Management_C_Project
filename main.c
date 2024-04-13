#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "include/pathUtilises.h"
#include "include/structUser.h"
#include "include/accountManagement.h"
#include "include/menu.h"
int main(int argc, char **argv)
{
    char *dataPath = getDataPath(argv[0]);
    User currentUser = initialiseUser(argv[2], argv[3]);
    if (strcmp("login", argv[1]) == 0)
    {
        char res = loginUser(currentUser, dataPath);
        if (res == 0)
            printf("User not found.");
        else
        {
            // printf("User found.");
            char *options[] = {"Account Management", "Transactions"};
            showMenu(2, options);
        }
        // enter app
    }
    else if (strcmp("register", argv[1]) == 0)
    {
        char res = registerUser(currentUser, dataPath);
        if (res == 0)
            printf("Please login");
        else
            printf("User registered.");
    }
    return 0;
}