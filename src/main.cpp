// src/main.cpp
#include "Storage.h"
#include <iostream>

int main() {
    // 1) Load from data.json (must be next to your binary or run from project root)
    auto accounts = Storage::load("data.json");

    // 2) If no accounts, seed a demo
    if (accounts.empty()) {
        std::cout << "No accounts found; creating a demo account.\n";
        Account demo("acct-000", "demo@example.com", "secret");
        accounts.push_back(demo);
    } else {
        std::cout << "Loaded " << accounts.size() << " account(s).\n";
    }

    // 3) (Optional) tweak something in memory
    //    e.g. accounts[0].setEmail("updated@example.com");

    // 4) Save everything back to data.json
    Storage::save(accounts, "data.json");
    std::cout << "Wrote " << accounts.size() << " account(s) to data.json\n";
    return 0;
}