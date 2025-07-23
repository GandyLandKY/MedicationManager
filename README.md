## This is not a working solution, it is a school project emphasizing project collaboration, not coding.

#MedicationManager

## Overview
MedicationManager is a simple C++ application designed to demonstrate medication management functionality, with room for expansion. The core application includes a basic reminder system and can be extended to support scheduling, alerts, and database integration.

## Project Scope
- Basic medication reminder system
- Foundation for notification system (console-based for now)
- Designed for expansion with UI or database backends
- Continuous Integration via GitHub Actions

## Initial Class Design
- `MedicationReminder`: Handles reminder messages and logic
- `main.cpp`: Entry point to trigger reminders and initialize app flow

## Build Instructions (CMake)
```bash
cmake -S . -B build
cmake --build build
./build/MedicationManager
```

## GitHub and Git Setup (For New Users)

Great setup how-to by one of better professors here at UofL, very informative.
https://www.youtube.com/watch?v=lS_7f_ubnHY

### 1. Install Git
- Download Git: https://git-scm.com/downloads
- Confirm install:
```bash
git --version
```

### 2. Set Up GitHub Account
- Go to https://github.com and create an account

### 3. Configure Git Locally
```bash
git config --global user.name "Your Name"
git config --global user.email "your-email@example.com"
```

### 4. Set Up SSH Key
```bash
ssh-keygen -t ed25519 -C "your-email@louisville.edu"
# Press Enter through all prompts
```
Add your public key to GitHub:
```bash
cat ~/.ssh/id_ed25519.pub
```
Copy the contents and paste it here: https://github.com/settings/keys

### 5. Clone the Repository
```bash
git clone git@github.com:your-username/MedicationManager.git
```

## GitHub Actions
The repository includes a GitHub Actions workflow that builds the project using CMake on every push or pull request to the `main` branch.

## Next Steps
- Build additional modules like `Scheduler`, `DatabaseConnector`
- Connect to cloud services like Azure or Firebase for lightweight data needs
- Build a basic web or desktop UI
