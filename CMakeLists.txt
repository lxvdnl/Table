cmake_minimum_required(VERSION 3.10)
project(Table)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_DIR src)

set(SOURCES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/TSortedTable.cpp
    ${SOURCE_DIR}/TUnsortedTable.cpp
    ${SOURCE_DIR}/TBalanceTree.cpp
    ${SOURCE_DIR}/THashTable.cpp
    ${SOURCE_DIR}/TTable.cpp
    
)

set(HEADERS
    headers/TSortedTable.h
    headers/TUnsortedTable.h
    headers/TBalanceTree.h
    headers/THashTable.h
    headers/TTable.h
    submodules/TList/TList.h
)

include_directories(
    ${SOURCE_DIR}/../headers
    ${SOURCE_DIR}/../submodules/TList
)

add_executable(Table ${SOURCES} ${HEADERS})

set(TABLE_EXAMPLES ${SOURCE_DIR}/../tableExamples/Table.txt)

configure_file(${TABLE_EXAMPLES} ${CMAKE_CURRENT_BINARY_DIR}/tableExamples/Table.txt COPYONLY)