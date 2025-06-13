// Schedule.h
#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "Medication.h"

class Schedule {
private:
    std::string id;
    std::vector<Medication> medications;
    std::string userID;
    std::string startDate;      // e.g. "2025-06-13"
    std::string endDate;        // e.g. "2025-12-31"
    std::string scheduleName;

public:
    // Constructor
    Schedule(const std::string& id,
             const std::string& userID,
             const std::string& scheduleName,
             const std::string& startDate,
             const std::string& endDate);

    // Medication management
    void addMedication(const Medication& medication);
    bool deleteMedication(const std::string& medID);
    const std::vector<Medication>& getMedications() const;
    bool updateMedication(const std::string& medID, const Medication& updatedMed);
    std::vector<Medication> searchMedication(const std::string& nameKeyword) const;

    // Accessors / Mutators
    std::string getId() const;
    std::string getUserID() const;
    std::string getScheduleName() const;
    void setScheduleName(const std::string& newName);
    std::string getStartDate() const;
    void setStartDate(const std::string& newStart);
    std::string getEndDate() const;
    void setEndDate(const std::string& newEnd);
};