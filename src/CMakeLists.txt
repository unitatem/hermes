set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME}
    main.cpp)
target_link_libraries(${PROJECT_NAME}
    Book)

add_library(Book SHARED
    book.cpp)
target_link_libraries(Book
    Page)

add_library(Page SHARED
    page.cpp)
