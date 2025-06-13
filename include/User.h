//User.h

#pragma once

#include <string>
#include <vector>
#include <algorithm> //for std::find_if
#include "Schedule.h"

class User {
    private:
        std::string id;
        std::string username;
        std::vector<Schedule> schedules;

    public:
        User(const std::string& id, const std::string& username);

        //operations
        void addSchedule(const Schedule& schedule);
        bool deleteSchedule(const std::string& scheduleID);
        const std::vector<Schedule>& getSchedules() const;
        bool editScheduleName(const std::string& scheduleID, const std::string& newName);

        //accessors
        std::string getId() const;
        std::string getUsername() const;

};