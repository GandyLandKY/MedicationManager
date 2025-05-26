cmake_minimum_required(VERSION 3.10)
project(MedicationManager)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(MedicationManager src/main.cpp src/MedicationReminder.cpp)
