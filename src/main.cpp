#include "Account.h"
#include "User.h"
#include "Schedule.h"
#include "Medication.h"
#include "MedicationReminder.h"
#include <iostream>

int main() {
    // 1) Create an account
    Account acct("acct-001", "jane.doe@example.com");

    // 2) Add a user
    User alice("user-001", "Alice");
    acct.addUser(alice);

    // 3) Grab Alice’s profile, give her a schedule
    auto& users = acct.getUserProfiles();
    User& u = users.front();
    Schedule morn("sch-001", u.getId(), "Morning meds", "07:00", "07:05");
    u.addSchedule(morn);

    // 4) Add a medication
    Medication aspirin("med-001","Aspirin","100mg","24h",30,"2025-06-13",5);
    u.getSchedules()[0].addMedication(aspirin);

    // 5) Demonstrate functionality
    std::cout << "Email on file: " << acct.getEmail() << "\n";
    std::cout << "User “" << u.getUsername() << "” has "
              << u.getSchedules()[0].getMedications().size()
              << " meds in “" << u.getSchedules()[0].getScheduleName() << "”.\n";

    return 0;
}