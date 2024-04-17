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
#include "include/transactionManagement.h"

int main(int argc, char** argv)
{
    srand(time(NULL));
    char* dataPath = getDataPath(argv[0]);
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
                            int resCreateAccount;
                            switch (currency)
                            {
                            case 1:
                                resCreateAccount = createAccount(currentUser, dataPath, "RON");
                                break;

                            case 2:
                                resCreateAccount = createAccount(currentUser, dataPath, "EUR");
                                break;

                            case 3:
                                resCreateAccount = createAccount(currentUser, dataPath, "USD");
                                break;

                            default:
                                break;
                            }
                            if (resCreateAccount) {
                                printf("Account created.\n");
                                // awaitInput();
                            }
                        }
                        if (accountRes == 2) {

                            int editRes = editMenu();
                            char IBAN[33], newData[33];
                            showAccounts(currentUser, dataPath);
                            printf("Please insert IBAN for the account to be modified: ");
                            scanf("%s", IBAN);
                            printf("Please insert the new data for the account: ");
                            scanf("%s", newData);
                            if (editAccount(currentUser, dataPath, IBAN, editRes, newData))
                                printf("Account updated.\n");
                            else printf("Update failed.\n");
                            //printf("dsahsus");
                        }
                        if (accountRes == 3)
                        {
                            showAccounts(currentUser, dataPath);
                        }
                        if (accountRes == 4) {
                            showAccounts(currentUser, dataPath);
                            printf("Please insert IBAN for the account to be deleted:");
                            char IBAN[33];
                            scanf("%s", IBAN);
                            deleteAccount(currentUser, dataPath, IBAN);
                            printf("Delete succesful.\n");
                        }
                    }
                }
                if (mainRes == 2)
                {
                    int transactionRes;
                    while ((transactionRes = transactionMenu()) != 3)
                    {
                        if (transactionRes == 1) {

                            printf("Your accounts are:\n");
                            showAccounts(currentUser, dataPath);
                            char sourceIBAN[33], destinationIBAN[33], amount[10];
                            printf("Please write the source IBAN:");
                            scanf("%s", sourceIBAN);
                            printf("Please write the destination IBAN:");
                            scanf("%s", destinationIBAN);
                            printf("Please write the amount to be transfered:");
                            scanf("%s", amount);
                            if (sendMoney(currentUser, dataPath, sourceIBAN, destinationIBAN, amount))
                                printf("Transfer completed.\n");
                            else
                                printf("Transfer failed.\n");
                        }
                        if (transactionRes == 2) {

                            showAccounts(currentUser, dataPath);
                            char IBAN[33];
                            printf("Please write the IBAN of the account in which you wish to deposit:");
                            scanf("%s", IBAN);
                            char sum[11];
                            printf("Please write the sum to be deposited:");
                            scanf("%s", sum);
                            if (depositMoney(currentUser, dataPath, IBAN, sum))
                                printf("Succesful deposit.\n");
                            else printf("The deposit failed.\n");
                        }

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