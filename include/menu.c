#define _CRT_SECURE_NO_WARNINGS

#include "menu.h"
#include <stdio.h>
#include <Windows.h>

void awaitInput() {
    char* buffer = malloc(50);
    printf("Press enter to continue...");
    scanf("%s", buffer);
    free(buffer);
    return;
}

int showMenu(int length, char** options)
{
    //system("cls");
    for (int i = 0; i < length; i++)
        printf("%d. %s\n", i + 1, options[i]);
    printf("Please select an option: ");
    int option;
    scanf("%d", &option);
    while (option > length)
    {
        printf("Previous selection was invalid. Please select an option: ");
        scanf("%d", &option);
    }
    return option;
}

int mainMenu()
{
    char* options[] = { "Account Management", "Transactions", "Quit" };
    return showMenu(3, options);
}

int accountsMenu()
{
    char* optionsManagement[] = { "Add account", "Edit account", "View account data", "Delete account", "Back" };
    return showMenu(5, optionsManagement);
}

int transactionMenu()
{
    char* options[] = { "Send money", "Deposit money", "Back" };
    return showMenu(3, options);
}

int currencyMenu()
{
    char* options[] = { "RON", "EUR", "USD", "Cancel" };
    return showMenu(4, options);
}

int editMenu() {
    char* options[] = { "IBAN", "Currency" };
    return showMenu(2, options);
}