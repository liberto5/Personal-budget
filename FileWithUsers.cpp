#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {
    CMarkup userFile;
    bool ifFileWithUsersExists = userFile.Load( nameOfFileWithUsers );
    if (ifFileWithUsersExists == false) {
        userFile.AddElem( "UsersList" );
        userFile.IntoElem();
    }
    userFile.FindElem();
    userFile.IntoElem();
    userFile.AddElem( "Id", user.downloadUserId() );
    userFile.AddElem( "Name", user.downloadUserName() );
    userFile.AddElem( "Surname", user.downloadUserSurname() );
    userFile.AddElem( "Login", user.downloadUserLogin() );
    userFile.AddElem( "Password", user.downloadUserPassword() );
    userFile.Save( nameOfFileWithUsers );
}

void FileWithUsers::addAllUsersToFile(vector <User> &users) {
    CMarkup userFile;
    userFile.AddElem( "UsersList" );
    userFile.IntoElem();
    userFile.FindElem();
    userFile.IntoElem();
    vector <User>::iterator itrEnd = --users.end();
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
    userFile.AddElem( "Id", itr -> downloadUserId() );
    userFile.AddElem( "Name", itr -> downloadUserName() );
    userFile.AddElem( "Surname", itr -> downloadUserSurname() );
    userFile.AddElem( "Login", itr -> downloadUserLogin() );
    userFile.AddElem( "Password", itr -> downloadUserPassword() );
    userFile.Save( nameOfFileWithUsers );
    }
}

vector <User> FileWithUsers::loadUsersFromFile() {
    User user;
    vector<User> users;
    CMarkup userFile;
    userFile.Load( nameOfFileWithUsers );
    userFile.ResetPos();
    userFile.FindElem();
    userFile.IntoElem();
    while (true) {
        bool ifNextPositionExists = userFile.FindElem();
        if (ifNextPositionExists == false)
        {
            break;
        }
        string id = userFile.GetElemContent();
        int idAsInt = atoi(id.c_str());
        user.setUserId(idAsInt);
        userFile.FindElem();
        string name = userFile.GetElemContent();
        user.setUserName(name);
        userFile.FindElem();
        string surname = userFile.GetElemContent();
        user.setUserSurname(surname);
        userFile.FindElem();
        string login = userFile.GetElemContent();
        user.setUserLogin(login);
        userFile.FindElem();
        string password = userFile.GetElemContent();
        user.setUserPassword(password);
        users.push_back(user);
    }
    return users;
}
