add_library(mwe_googletest_math "")

target_sources(
        mwe_googletest_math
        PRIVATE my_math.cpp
        PUBLIC ${CMAKE_CURRENT_LIST_DIR}/my_math.h
)

target_include_directories(
        mwe_googletest_math
        PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)
