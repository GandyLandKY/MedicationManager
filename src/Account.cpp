#include "Account.h"

Account::Account (const std::string& id, const std::string& email)
    : id(id), email(email)
{}

void Account::addUser(const User& user) {
    userProfiles.push_back(user);
}

bool Account::deleteUser(const std::string& userID) {
    auto it = std::find_if(
        userProfiles.begin(),
        userProfiles.end(),
        [&](auto const& u) {return u.getId() == userID;}
    );
    if (it != userProfiles.end()) {
        userProfiles.erase(it);
        return true;
    }
    return false;
}

std::string Account::getEmail() const {
    return email;
}

void Account::editEmail(const std::string& newEmail) {
    email = newEmail;
}

const std::vector<User>& Account::getUserProfiles() const {
    return userProfiles;
}