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
        std::string password;
        std::vector<User> userProfiles;

    public:
        Account (const std::string& id, 
                const std::string& email, 
                const std::string& password);

        //operations
        void addUser(const User& user);
        bool deleteUser(const std::string& userID);

        //getters/setters
        std::string getId() const;
        std::string getEmail() const;
        std::string getPassword() const;
        void setEmail(const std::string& newEmail);
        void setPassword(const std::string& newPassword);

        //optional getter for all profiles
        const std::vector<User>& getUserProfiles() const;
        std::vector<User>& getUserProfiles();
};