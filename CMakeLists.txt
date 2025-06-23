################################################################################################ start of prior cmake settings
# cmake_minimum_required(VERSION 3.10)
# project(MedicationManager)

# set(CMAKE_CXX_STANDARD 17)

# include_directories(include)
# add_executable(MedicationManager src/main.cpp src/MedicationReminder.cpp)
################################################################################################end of prior cmake settings

cmake_minimum_required(VERSION 3.10)
project(MedicationManager)

set(CMAKE_CXX_STANDARD 17)

# where to find your headers:
include_directories(${PROJECT_SOURCE_DIR}/include)

# grab every .cpp in src/:
file(GLOB SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# build the executable from all .cpp’s:
add_executable(MedicationManager
    ${SRC_FILES}
)
