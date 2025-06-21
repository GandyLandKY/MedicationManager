#include "User.h"

User::User(const std::string& id, const std::string& username)
    : id(id), username(username) 
{}

void User::addSchedule(const Schedule& schedule) {
    schedules.push_back(schedule);
}

bool User::deleteSchedule(const std::string& scheduleID) {
    auto it = std::find_if(
        schedules.begin(),
        schedules.end(),
        [&](auto const& s){ return s.getId() == scheduleID; }
    );
    if (it != schedules.end()) {
        schedules.erase(it);
        return true;
    }
    return false;
}

const std::vector<Schedule>& User::getSchedules() const {
    return schedules;
}

std::vector<Schedule>& User::getSchedules() {
    return schedules;
}

bool User::editScheduleName(const std::string& scheduleID, const std::string& newName) {
    auto it = std::find_if(
        schedules.begin(),
        schedules.end(),
        [&](auto const& s){ return s.getId() == scheduleID; }
    );
    if (it != schedules.end()) {
        it->setScheduleName(newName);
        return true;
    }
    return false;
}

std::string User::getId() const {
    return id;
}

std::string User::getUsername() const {
    return username;
}