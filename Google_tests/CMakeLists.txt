# 'Google_test' is the subproject name
project(Google_tests)

cmake_minimum_required(VERSION 3.13)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../test)
include_directories(../src)

# 'Google_Tests_run' is the target name
# 'test.cpp' is a source file with tests
add_executable(Google_Tests_run
        ../test/test.cpp
        ../src/utils/CSVReader.cpp
        ../src/utils/CSVReader.h
        ../src/calculator/Automaton.cpp
        ../src/calculator/Automaton.h
        ../src/calculator/Lexer.cpp
        ../src/calculator/Lexer.h
        ../src/calculator/Symbol.cpp
        ../src/calculator/Symbol.h
        ../src/calculator/State.cpp
        ../src/calculator/State.h
        ../src/calculator/Expression.cpp
        ../src/calculator/Expression.h
        )
target_link_libraries(Google_Tests_run gtest gtest_main)