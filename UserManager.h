#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>

#include "User.h"
#include "FileWithUsers.h"

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;
    User enterDataOfNewUser();
    bool isLoginInUse(string login);
    int downloadIdOfNewUser();

public:
    UserManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers) {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
        };
    void signUp();
    void displayAllUsers();
    void signIn();
    void changePassword();
    void logOut();
};

#endif //USERMANAGER_H
