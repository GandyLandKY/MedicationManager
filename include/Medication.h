// Medication.h
#pragma once

#include <string>
#include <chrono>

class Medication {
private:
    std::string id;
    std::string name;
    std::string dosage;        // e.g. "10mg"
    std::string frequency;     // e.g. "8h", "2x/day" (you decide parsing)
    int totalPills;
    std::string fillDate;      // e.g. "2025-06-13"
    int refillThreshold;       // when totalPills <= this, refill is needed

public:
    // Constructor
    Medication(const std::string& id,
               const std::string& name,
               const std::string& dosage,
               const std::string& frequency,
               int totalPills,
               const std::string& fillDate,
               int refillThreshold);

    // Accessors
    std::string getId()              const;
    std::string getName()            const;
    std::string getDosage()          const;
    std::string getFrequency()       const;
    int         getTotalPills()      const;
    std::string getFillDate()        const;
    int         getRefillThreshold() const;

    // Core operations
    bool isRefillNeeded() const;
    std::chrono::system_clock::time_point getNextDoseTime() const;
};