cmake_minimum_required(VERSION 3.12)

project ("SLIDES")

file(GLOB SOURCE_FILES "*.cpp" "Application/*.cpp" "Application/**/*.cpp" "Application/**/**/*.cpp" "Application/**/**/**/*.cpp" "Application/**/**/**/**/*.cpp")

set(GLOB HEADERS "*.hpp" "Application/*.hpp" "Application/**/*.hpp" "Application/**/**/*.hpp" "Application/**/**/**/*.hpp" "Application/**/**/**/**/*.hpp")

add_executable(SLIDES ${SOURCE_FILES} ${HEADERS})

set_property(TARGET SLIDES PROPERTY CXX_STANDARD 20)

target_include_directories(SLIDES PRIVATE include)


# TODO: Add tests and install targets if needed.
