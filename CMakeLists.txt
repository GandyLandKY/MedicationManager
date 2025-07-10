################################################################################################ start of prior cmake settings
# cmake_minimum_required(VERSION 3.10)
# project(MedicationManager)

# set(CMAKE_CXX_STANDARD 17)

# include_directories(include)
# add_executable(MedicationManager src/main.cpp src/MedicationReminder.cpp)
################################################################################################end of prior cmake settings

cmake_minimum_required(VERSION 3.14)
project(MedicationManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Copy data.json to build dir
configure_file(${PROJECT_SOURCE_DIR}/data.json ${CMAKE_BINARY_DIR}/data.json COPYONLY)

# Grab all .cpp files
file(GLOB ALL_SRC_FILES
  ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# For main app: exclude validate_data.cpp
set(APP_SRC_FILES ${ALL_SRC_FILES})
list(REMOVE_ITEM APP_SRC_FILES ${PROJECT_SOURCE_DIR}/src/validate_data.cpp)

# For test: exclude main.cpp
set(VALIDATE_SRC_FILES ${ALL_SRC_FILES})
list(REMOVE_ITEM VALIDATE_SRC_FILES ${PROJECT_SOURCE_DIR}/src/main.cpp)

# Main app
add_executable(MedicationManager
  ${APP_SRC_FILES}
)

# Test executable
add_executable(ValidateData
  ${VALIDATE_SRC_FILES}
)

enable_testing()
add_test(NAME ValidateDataTest COMMAND ValidateData)
