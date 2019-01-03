#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <vector>

#include "User.h"
#include "Markup.h"

using namespace std;

class FileWithUsers
{
    const string nameOfFileWithUsers;

public:
    FileWithUsers(string NAMEOFFILEWITHUSERS) : nameOfFileWithUsers(NAMEOFFILEWITHUSERS) {};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
};

#endif //PLIKZUZYTKOWNIKAMI_H
