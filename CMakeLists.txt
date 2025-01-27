cmake_minimum_required(VERSION 3.10)
project(HASHING-PROJECT)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find and link libsodium
find_package(PkgConfig REQUIRED)
pkg_check_modules(SODIUM REQUIRED libsodium)

include_directories(${SODIUM_INCLUDE_DIRS})
link_directories(${SODIUM_LIBRARY_DIRS})
add_definitions(${SODIUM_CFLAGS_OTHER})

# Add executable and link libsodium
add_executable(HASHING-PROJECT src/hashing-converter.cpp)
target_link_libraries(HASHING-PROJECT ${SODIUM_LIBRARIES})
