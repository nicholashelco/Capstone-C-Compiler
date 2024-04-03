cmake_minimum_required(VERSION 3.22)
project(Capstone_C_Compiler)

set(CMAKE_CXX_STANDARD 17)

# Code for flex and bison integration given by Dr. Kramer on 3/2/2024.

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

BISON_TARGET(TestParser YaccCode.ypp ${CMAKE_CURRENT_BINARY_DIR}/YaccCode.tab.cpp)
FLEX_TARGET(TestScanner FlexCode.l   ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cc)
ADD_FLEX_BISON_DEPENDENCY(TestScanner TestParser)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(Capstone_C_Compiler main.cpp ${BISON_TestParser_OUTPUTS} ${FLEX_TestScanner_OUTPUTS}
        driver.cpp
        driver.h
        driver.h SyntaxTree.cpp SyntaxTree.h)
#target_link_libraries(Capstone_C_Compiler ${FLEX_LIBRARIES})
