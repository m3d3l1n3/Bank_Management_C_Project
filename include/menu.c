#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <stdio.h>
int showMenu(int length, char **options)
{
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
    return 1;
}