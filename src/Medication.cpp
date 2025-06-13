// Medication.cpp
#include "Medication.h"

Medication::Medication(const std::string& id,
                       const std::string& name,
                       const std::string& dosage,
                       const std::string& frequency,
                       int totalPills,
                       const std::string& fillDate,
                       int refillThreshold)
  : id(id)
  , name(name)
  , dosage(dosage)
  , frequency(frequency)
  , totalPills(totalPills)
  , fillDate(fillDate)
  , refillThreshold(refillThreshold)
{}

std::string Medication::getId()              const { return id; }
std::string Medication::getName()            const { return name; }
std::string Medication::getDosage()          const { return dosage; }
std::string Medication::getFrequency()       const { return frequency; }
int         Medication::getTotalPills()      const { return totalPills; }
std::string Medication::getFillDate()        const { return fillDate; }
int         Medication::getRefillThreshold() const { return refillThreshold; }

bool Medication::isRefillNeeded() const {
    return totalPills <= refillThreshold;
}

std::chrono::system_clock::time_point Medication::getNextDoseTime() const {
    // TODO: parse `frequency` (e.g., "8h") and compute next dose
    // For now, return "now" as a placeholder:
    return std::chrono::system_clock::now();
}