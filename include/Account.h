//Account.h

#pragma once 

#include <string>
#include <vector>
#include <algorithm> //for std::find_if
#include "User.h"  //forward-declares class User

class Account {
    private:
        std::string id;
        std::string email;
        std::vector<User> userProfiles;

    public:
        Account (const std::string& id, const std::string& email);

        //operations
        void addUser(const User& user);
        bool deleteUser(const std::string& userID);
        std::string getEmail() const;
        void editEmail(const std::string& newEmail);

        //optional getter for all profiles
        const std::vector<User>& getUserProfiles() const;
        std::vector<User>& getUserProfiles();
};