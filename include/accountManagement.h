#ifndef ACCOUNTMANAGEMENT
#define ACCOUNTMANAGEMENT
#include "structUser.h"

/**
 * @brief Create an account file for the given user
 *
 * @param currentUser
 * @param dataPath
 * @param currency
 * @return char
 */
char createAccount(User currentUser, char* dataPath, char* currency);
/**
 * @brief Soft deletes an account identified by an IBAN
 *
 * @param currentUser
 * @param dataPath
 * @param IBAN
 */
void deleteAccount(User currentUser, char* dataPath, char* IBAN);
/**
 * @brief Displays list of accounts of the current user
 *
 * @param currentUser
 * @param dataPath
 */
void showAccounts(User currentUser, char* dataPath);
/**
 * @brief Edits account based on specified option:
 * 1 - IBAN
 * 2 - Currency
 * 3 - Adding a certain amount
 * 4 - Substracting a certain amount
 *
 * @param currentUser
 * @param dataPath
 * @param IBAN
 * @param modifiableData is the option selected
 * @param newData contains the data to be added
 * @return char
 */
char editAccount(User currentUser, char* dataPath, char* IBAN, char modifiableData, char* newData);

char* paddingAmount(char* amount);

#endif