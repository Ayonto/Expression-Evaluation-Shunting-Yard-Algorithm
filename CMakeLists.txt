cmake_minimum_required(VERSION 3.28.0)
project(expr_eval VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(expr_eval main.cpp eval.cpp parse_out.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
