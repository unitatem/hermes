cmake_minimum_required (VERSION 3.10)
project(hermes VERSION 1.0.0 LANGUAGES CXX)

include_directories(include)

add_executable(hermes
    src/main.cpp
    src/stock_exchange_market.cpp
)
target_compile_options(hermes
    PRIVATE
        -Wall
        -Wextra
        -Werror
        -Wshadow
        -Wnon-virtual-dtor
        -pedantic
)
