#ifndef TRANSACTIONMANAGEMENT
#define TRANSACTIONMANAGEMENT
#include "structUser.h"

/**
 * @brief Adds the given sum to the already existing amount.
 *
 * @param currentUser
 * @param dataPath
 * @param IBAN
 * @param sum
 * @return char
 */
char depositMoney(User currentUser, char* dataPath, char* IBAN, char* sum);

/**
 * @brief Sends a specified amount from one account to another.
 *
 * @param currentUser
 * @param dataPath
 * @param sourceIBAN
 * @param destinationIBAN
 * @param amount
 * @return char
 */
char sendMoney(User currentUser, char* dataPath, char* sourceIBAN, char* destinationIBAN, char* amount);
#endif