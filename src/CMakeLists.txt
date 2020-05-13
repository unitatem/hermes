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
