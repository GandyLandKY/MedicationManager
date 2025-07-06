################################################################################################ start of prior cmake settings
# cmake_minimum_required(VERSION 3.10)
# project(MedicationManager)

# set(CMAKE_CXX_STANDARD 17)

# include_directories(include)
# add_executable(MedicationManager src/main.cpp src/MedicationReminder.cpp)
################################################################################################end of prior cmake settings

cmake_minimum_required(VERSION 3.14)
project(MedicationManager LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Where to find your headers (including nlohmann/json.hpp now)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Grab every .cpp under src/
file(GLOB SRC_FILES
  ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# Build the executable
add_executable(MedicationManager
  ${SRC_FILES}
)