#include "UserManager.h"

void UserManager::signUp() {
    User user = enterDataOfNewUser();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);
    cout << endl << "User has been added." << endl << endl;
    system("pause");
}

void UserManager::displayAllUsers() {
    for (int i = 0; i < users.size(); i++) {
        cout << users[i].downloadUserId() << endl;
        cout << users[i].downloadUserName() << endl;
        cout << users[i].downloadUserSurname() << endl;
        cout << users[i].downloadUserLogin() << endl;
        cout << users[i].downloadUserPassword() << endl;
    }
}

User UserManager::enterDataOfNewUser() {
    User user;
    user.setUserId(downloadIdOfNewUser());
    string name;
    string surname;
    string login;
    string password;

    cout << "Enter your first name: ";
    cin >> name;
    user.setUserName(name);

    cout << "Enter your last name: ";
    cin >> surname;
    user.setUserSurname(surname);

    do {
        cout << "Enter login: ";
        cin >> login;
        user.setUserLogin(login);
    } while (isLoginInUse(user.downloadUserLogin()) == true);

    cout << "Enter password: ";
    cin >> password;
    user.setUserPassword(password);

    return user;
}

int UserManager::downloadIdOfNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().downloadUserId() + 1;
}

bool UserManager::isLoginInUse(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].downloadUserLogin() == login) {
            cout << endl << "Login is taken." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::signIn() {
    string login = "", password = "";

    cout << "Enter login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> downloadUserLogin() == login) {
            for (int attemptsNumber = 3; attemptsNumber > 0; attemptsNumber--) {
                cout << "Enter password. " << attemptsNumber << " attempts left: ";
                cin >> password;

                if (itr -> downloadUserPassword() == password) {
                    cout << endl << "You are logged in." << endl << endl;
                    loggedInUserId = itr -> downloadUserId();
                    system("pause");
                    return;
                }
            }
            cout << "Incorrect password has been entered 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with such login." << endl << endl;
    system("pause");
    return;
}

void UserManager::changePassword() {
    string newPassword = "";
    cout << "Enter new password: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> downloadUserId() == loggedInUserId) {
            itr -> setUserPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.addAllUsersToFile(users);
}

void UserManager::logOut() {
    loggedInUserId = 0;
}

bool UserManager::isUserLoggedIn() {
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}

int UserManager::downloadIdOfLoggedInUser() {
    return loggedInUserId;
}
