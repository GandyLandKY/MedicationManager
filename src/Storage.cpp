// Storage.cpp
#include "Storage.h"

#include <fstream>
#include <iomanip>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::vector<Account> Storage::load(const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) return {};          // couldn't open → return empty

    json root;
    ifs >> root;

    std::vector<Account> accounts;
    for (auto const& aj : root["accounts"]) {
        // 1) build the Account
        Account acct(
            aj.at("id").get<std::string>(),
            aj.at("email").get<std::string>(),
            aj.at("password").get<std::string>()
        );

        // 2) for each user profile…
        for (auto const& uj : aj["userProfiles"]) {
            User u(
              uj.at("id").get<std::string>(),
              uj.at("username").get<std::string>()
            );

            // 3) for each schedule…
            for (auto const& sj : uj["schedules"]) {
                Schedule s(
                  sj.at("id").get<std::string>(),
                  u.getId(),
                  sj.at("scheduleName").get<std::string>(),
                  sj.at("startDate").get<std::string>(),
                  sj.at("endDate").get<std::string>()
                );

                // 4) for each medication…
                for (auto const& mj : sj["medications"]) {
                    Medication m(
                      mj.at("id").get<std::string>(),
                      mj.at("name").get<std::string>(),
                      mj.at("dosage").get<std::string>(),
                      mj.at("frequency").get<std::string>(),
                      mj.at("totalPills").get<int>(),
                      mj.at("fillDate").get<std::string>(),
                      mj.at("refillThreshold").get<int>()
                    );
                    s.addMedication(m);
                }

                u.addSchedule(s);
            }

            acct.addUser(u);
        }

        accounts.push_back(std::move(acct));
    }

    return accounts;
}

void Storage::save(const std::vector<Account>& accounts,
                   const std::string& filename) {
    json root = json::object();
    root["accounts"] = json::array();

    for (auto const& acct : accounts) {
        json aj;
        aj["id"]       = acct.getId();
        aj["email"]    = acct.getEmail();
        aj["password"] = acct.getPassword();

        aj["userProfiles"] = json::array();
        for (auto const& u : acct.getUserProfiles()) {
            json uj;
            uj["id"]       = u.getId();
            uj["username"] = u.getUsername();

            uj["schedules"] = json::array();
            for (auto const& s : u.getSchedules()) {
                json sj;
                sj["id"]           = s.getId();
                sj["scheduleName"] = s.getScheduleName();
                sj["startDate"]    = s.getStartDate();
                sj["endDate"]      = s.getEndDate();

                sj["medications"] = json::array();
                for (auto const& m : s.getMedications()) {
                    json mj;
                    mj["id"]              = m.getId();
                    mj["name"]            = m.getName();
                    mj["dosage"]          = m.getDosage();
                    mj["frequency"]       = m.getFrequency();
                    mj["totalPills"]      = m.getTotalPills();
                    mj["fillDate"]        = m.getFillDate();
                    mj["refillThreshold"] = m.getRefillThreshold();
                    sj["medications"].push_back(mj);
                }

                uj["schedules"].push_back(sj);
            }

            aj["userProfiles"].push_back(uj);
        }

        root["accounts"].push_back(aj);
    }

    std::ofstream ofs(filename);
    ofs << std::setw(4) << root << "\n";
}