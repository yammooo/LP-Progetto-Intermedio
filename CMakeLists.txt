cmake_minimum_required(VERSION 3.0.0)
project(ProgettoIntermedio VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories(include)
add_executable(ProgettoIntermedio src/book.cpp src/date.cpp src/main.cpp src/book_shelf.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
