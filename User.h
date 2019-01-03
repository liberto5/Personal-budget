#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User
{
    int userId;
    string login;
    string password;
    string name;
    string surname;

public:
    void setUserId (int newId);
    void setUserLogin (string newLogin);
    void setUserPassword (string newPassword);
    void setUserName (string newName);
    void setUserSurname (string newSurname);

    int downloadUserId();
    string downloadUserLogin();
    string downloadUserPassword();
    string downloadUserName();
    string downloadUserSurname();
};

#endif //USER_H
