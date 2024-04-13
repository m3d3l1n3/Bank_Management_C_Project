#ifndef STRUCTUSER
#define STRUCTUSER

typedef struct user
{
    char *name;
    char *surname;
} User;

User initialiseUser(char *name, char *surname);

#endif