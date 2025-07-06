#include "Storage.h"
#include <iostream>
#include <cstdlib>

int main() {
    auto accounts = Storage::load("../data.json");

    if (accounts.empty()) {
        std::cerr << "data.json has no accounts.\n";
        return 1;
    }

    for (const auto& account : accounts) {
        if (account.getId().empty() || account.getEmail().empty() || account.getPassword().empty()) {
            std::cerr << "Account missing required fields.\n";
            return 1;
        }

        const auto& users = account.getUserProfiles();
        if (users.empty()) {
            std::cerr << "Account has no userProfiles.\n";
            return 1;
        }

        for (const auto& user : users) {
            if (user.getId().empty() || user.getUsername().empty()) {
                std::cerr << "User missing ID or username.\n";
                return 1;
            }

            const auto& schedules = user.getSchedules();
            if (schedules.empty()) {
                std::cerr << "User has no schedules.\n";
                return 1;
            }

            for (const auto& schedule : schedules) {
                if (schedule.getId().empty() || schedule.getScheduleName().empty() ||
                    schedule.getStartDate().empty() || schedule.getEndDate().empty()) {
                    std::cerr << "Schedule missing required fields.\n";
                    return 1;
                }

                const auto& meds = schedule.getMedications();
                if (meds.empty()) {
                    std::cerr << "Schedule has no medications.\n";
                    return 1;
                }

                for (const auto& med : meds) {
                    if (med.getId().empty() || med.getName().empty() || med.getDosage().empty() ||
                        med.getFrequency().empty() || med.getFillDate().empty()) {
                        std::cerr << "Medication missing required fields.\n";
                        return 1;
                    }

                    if (med.getTotalPills() < 0 || med.getRefillThreshold() < 0) {
                        std::cerr << "Medication has invalid numeric fields.\n";
                        return 1;
                    }
                }
            }
        }
    }

    std::cout << "data.json is valid.\n";
    return 0;
}
