#include "User.h"

void User::setUserId(int newId) {
    if (newId >= 0)
        userId = newId;
}
void User::setUserLogin(string newLogin) {
    login = newLogin;
}
void User::setUserPassword (string newPassword) {
    password = newPassword;
}
void User::setUserName (string newName) {
    name = newName;
}
void User::setUserSurname (string newSurname) {
    surname = newSurname;
}

int User::downloadUserId() {
    return userId;
}
string User::downloadUserLogin() {
    return login;
}
string User::downloadUserPassword() {
    return password;
}
string User::downloadUserName() {
    return name;
}
string User::downloadUserSurname() {
    return surname;
}
