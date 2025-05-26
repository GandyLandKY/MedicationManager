#include "MedicationReminder.h"
#include <iostream>

int main() {
    MedicationReminder reminder;
    reminder.sendReminder();
    std::cout << "Medication Assistant running..." << std::endl;
    return 0;
}
