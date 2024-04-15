#ifndef USERMANAGEMENT
#define USERMANAGEMENT
#include "structUser.h"

char *getUserPath(User currentUser, char *dataPath);
char loginUser(User user, char *dataPath);
char registerUser(User user, char *dataPath);
#endif