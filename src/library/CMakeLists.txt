set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/library)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/library)

add_executable(library
    main.cpp)
target_link_libraries(library
    Book)

add_library(Book SHARED
    book.cpp)
target_link_libraries(Book
    Page)

add_library(Page SHARED
    page.cpp)
