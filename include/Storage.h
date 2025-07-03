// Storage.h
#pragma once

#include "Account.h"
#include <vector>
#include <string>

class Storage {
public:
  /// Load all accounts from `filename`. Returns empty vector on I/O errors.
  static std::vector<Account> load(const std::string& filename);

  /// Save all accounts into `filename` (overwrites).
  static void save(const std::vector<Account>& accounts,
                   const std::string& filename);
};