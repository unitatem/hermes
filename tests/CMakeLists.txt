enable_testing()

include(googletest/googletest.cmake)
fetch_googletest(${PROJECT_BINARY_DIR}/googletest)
include(GoogleTest)

add_subdirectory(library)
add_subdirectory(visitor)
