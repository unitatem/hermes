add_library(dedal_core "")

target_sources(
        dedal_core
        PRIVATE my_math.cpp
        PUBLIC ${CMAKE_CURRENT_LIST_DIR}/my_math.h
)

target_include_directories(
        dedal_core
        PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)
