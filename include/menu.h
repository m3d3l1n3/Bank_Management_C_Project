#ifndef MENU
#define MENU

/**
 * @brief Gives options for the accounts menu.
 * Options:
 * Account Management,
 * Transactions,
 * Quit,
 *
 * @return int
 */
int mainMenu();
/**
 * @brief Gives options for the accounts menu.
 * Options:
 * Add account,
 * Edit account,
 * View account data,
 * Delete account,
 * Back.
 *
 * @return int
 */
int accountsMenu();
/**
 * @brief Gives options for the transaction menu.
 * Options:
 * Send money,
 * Deposit,
 * Back.
 *
 * @return int
 */
int transactionMenu();
/**
 * @brief Gives options for the currency menu.
 * Options:
 * RON,
 * EUR,
 * USD,
 * Back.
 *
 * @return int
 */
int currencyMenu();
/**
 * @brief Displays menus based on their length and options.
 *
 * @param length
 * @param options
 * @return int
 */
int showMenu(int length, char** options);
/**
 * @brief Gives options for the main menu.
 * Options:
 * IBAN,
 * Currency,
 * Back.
 *
 * @return int
 */
int editMenu();

void awaitInput();
#endif