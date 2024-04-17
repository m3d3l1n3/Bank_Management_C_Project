#ifndef USERMANAGEMENT
#define USERMANAGEMENT
#include "structUser.h"

/**
 * @brief Get the path to the file dedicated to the current user.
 *
 * @param currentUser
 * @param dataPath
 * @return char*
 */
char* getUserPath(User currentUser, char* dataPath);
/**
 * @brief Checks if the user has logged in.
 *
 * @param user
 * @param dataPath
 * @return char
 */
char loginUser(User user, char* dataPath);
/**
 * @brief Checks if the user has registered.
 *
 * @param user
 * @param dataPath
 * @return char
 */
char registerUser(User user, char* dataPath);

#endif