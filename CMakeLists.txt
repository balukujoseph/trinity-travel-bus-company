cmake_minimum_required(VERSION 3.16)
project(TrinityTravels)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to Cucumber-CPP
set(CUCUMBER_CPP_DIR "C:/Users/BALUKU/vcpkg/cucumber-cpp")

# Include directories
include_directories(
    ${CUCUMBER_CPP_DIR}/include
    ${CUCUMBER_CPP_DIR}/build/src
    ${CMAKE_SOURCE_DIR}/src
)

# Link directories
link_directories(${CUCUMBER_CPP_DIR}/build/src/Debug)

# Add executable
add_executable(step_runner
    src/step_definitions.cpp
    src/ai_recommender.cpp
)

# Link libraries
target_link_libraries(step_runner
    cucumber-cpp
    cucumber-cpp-internal
    ws2_32
)
