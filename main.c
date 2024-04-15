#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "include/pathUtilises.h"
#include "include/structUser.h"
#include "include/userManagement.h"
#include "include/menu.h"
#include "include/accountManagement.h"
int main(int argc, char **argv)
{
    srand(time(NULL));
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
            int mainRes;
            while ((mainRes = mainMenu()) != 3)
            {
                if (mainRes == 1)
                {
                    int accountRes;
                    while ((accountRes = accountsMenu()) != 5)
                    {
                        if (accountRes == 1)
                        {
                            int currency = currencyMenu();
                            switch (currency)
                            {
                            case 1:
                                createAccount(currentUser, dataPath, "RON");
                                break;

                            case 2:
                                createAccount(currentUser, dataPath, "EUR");
                                break;

                            case 3:
                                createAccount(currentUser, dataPath, "USD");
                                break;

                            default:
                                break;
                            }
                        }
                    }
                }
                if (mainRes == 2)
                {
                    int transactionRes;
                    while ((transactionRes = transactionMenu()) != 3)
                    {
                        //
                    }
                }
            }
        }
        // enter app
    }
    else if (strcmp("register", argv[1]) == 0)
    {
        char res = registerUser(currentUser, dataPath);
        if (res == 0)
            printf("User already has an account. Please login");
        else
            printf("User registered.");
    }
    // printf("%d", createAccount(currentUser, dataPath, "RON"));
    return 0;
}