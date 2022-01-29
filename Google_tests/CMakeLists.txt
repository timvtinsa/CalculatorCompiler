# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../test)
include_directories(../src)

# 'Google_Tests_run' is the target name
# 'test.cpp' is a source file with tests
add_executable(Google_Tests_run
        ../test/test.cpp
        ../test/TAutomate.h
        ../src/utils/CSVReader.cpp
        ../src/utils/CSVReader.h
        ../src/calculator/Automate.cpp
        ../src/calculator/Automate.h
        ../src/calculator/Lexer.cpp
        ../src/calculator/Lexer.h
        ../src/calculator/Symbole.cpp
        ../src/calculator/Symbole.h
        ../src/calculator/Etat.cpp
        ../src/calculator/Etat.h
        ../src/calculator/Expression.cpp
        ../src/calculator/Expression.h
        )
target_link_libraries(Google_Tests_run gtest gtest_main)