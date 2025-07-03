#include "Account.h"

Account::Account (const std::string& id, 
                  const std::string& email,
                  const std::string& password)
    : id(id), 
    email(email),
    password(password)
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

std::string Account::getId() const {
    return id;
}

std::string Account::getEmail() const {
    return email;
}

std::string Account::getPassword() const {
    return password;
}

void Account::setEmail(const std::string& newEmail) {
    email = newEmail;
}

void Account::setPassword(const std::string& newPassword) {
    password = newPassword;
}

const std::vector<User>& Account::getUserProfiles() const {
    return userProfiles;
}

std::vector<User>& Account::getUserProfiles() {
    return userProfiles;
}