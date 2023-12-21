cmake_minimum_required(VERSION 3.14)

project ("SLIDES")

set(CMAKE_CXX_STANDARD 17)
if(MSVC)
    add_compile_options("/Zc:__cplusplus")
    add_compile_options("/permissive-")
endif()
set(Qt6_DIR "C:/Qt/6.6.1/msvc2019_64")
set(Qt6GuiTools_DIR "C:/Qt/6.6.1/msvc2019_64/lib/cmake/Qt6GuiTools")
set(CMAKE_PREFIX_PATH "C:/Qt/6.6.1/msvc2019_64")

find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)

file(GLOB SOURCE_FILES "*.cpp" "Application/*.cpp" "Application/**/*.cpp" "Application/**/**/*.cpp" "Application/**/**/**/*.cpp" "Application/**/**/**/**/*.cpp")

set(GLOB HEADERS "*.hpp" "Application/*.hpp" "Application/**/*.hpp" "Application/**/**/*.hpp" "Application/**/**/**/*.hpp" "Application/**/**/**/**/*.hpp")

link_directories(
    "C:/Qt/6.6.1/msvc2019_64/lib"        # Qt library directory
)
add_executable(SLIDES ${SOURCE_FILES} ${HEADERS})

target_include_directories(SLIDES PRIVATE include)

target_link_libraries(SLIDES Qt6::Core Qt6::Widgets)








