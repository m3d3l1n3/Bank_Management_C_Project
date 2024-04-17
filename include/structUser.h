#ifndef STRUCTUSER
#define STRUCTUSER

typedef struct user
{
    char* name;
    char* surname;
} User;
/**
 * @brief Initialises a User instance
 *
 * @param name
 * @param surname
 * @return User
 */
User initialiseUser(char* name, char* surname);

#endif