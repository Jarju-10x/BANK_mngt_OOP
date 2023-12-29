cmake_minimum_required(VERSION 3.5)
project(BANK)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/Main.cpp
    header/bankclass.cpp
    header/Menu.cpp
)

set(HEADERS
    Includes/bankclass.h
    Includes/Menu.h
)


include_directories(Includes)


add_executable(BANK ${SOURCES} ${HEADERS})

target_include_directories(BANK PUBLIC Includes)
target_compile_options(BANK PRIVATE -Wall)
