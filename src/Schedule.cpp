// Schedule.cpp
#include "Schedule.h"

Schedule::Schedule(const std::string& id,
                   const std::string& userID,
                   const std::string& scheduleName,
                   const std::string& startDate,
                   const std::string& endDate)
  : id(id)
  , userID(userID)
  , scheduleName(scheduleName)
  , startDate(startDate)
  , endDate(endDate)
{}

void Schedule::addMedication(const Medication& medication) {
    medications.push_back(medication);
}

bool Schedule::deleteMedication(const std::string& medID) {
    auto it = std::find_if(
        medications.begin(),
        medications.end(),
        [&](auto const& m){ return m.getId() == medID; }
    );
    if (it != medications.end()) {
        medications.erase(it);
        return true;
    }
    return false;
}

const std::vector<Medication>& Schedule::getMedications() const {
    return medications;
}

bool Schedule::updateMedication(const std::string& medID, const Medication& updatedMed) {
    auto it = std::find_if(
        medications.begin(),
        medications.end(),
        [&](auto const& m){ return m.getId() == medID; }
    );
    if (it != medications.end()) {
        *it = updatedMed;
        return true;
    }
    return false;
}

std::vector<Medication> Schedule::searchMedication(const std::string& nameKeyword) const {
    std::vector<Medication> results;
    for (auto const& m : medications) {
        if (m.getName().find(nameKeyword) != std::string::npos) {
            results.push_back(m);
        }
    }
    return results;
}

// Accessors / Mutators
std::string Schedule::getId() const          { return id; }
std::string Schedule::getUserID() const      { return userID; }
std::string Schedule::getScheduleName() const{ return scheduleName; }
void Schedule::setScheduleName(const std::string& newName) { scheduleName = newName; }
std::string Schedule::getStartDate() const   { return startDate; }
void Schedule::setStartDate(const std::string& newStart)   { startDate = newStart; }
std::string Schedule::getEndDate() const     { return endDate; }
void Schedule::setEndDate(const std::string& newEnd)       { endDate = newEnd; }