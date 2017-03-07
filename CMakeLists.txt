cmake_minimum_required(VERSION 2.8.11)

# Include settings
include(AmnesiaConfig.cmake)

# Include testing utils
include(cmake/testing.cmake)

# Enable testing
enable_testing()

# Include the directory with all the tests
add_subdirectory(tests)

# Include the directory with all application code
add_subdirectory(src)

# Include the directory with all library code
add_subdirectory(lib)
