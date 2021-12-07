cmake_minimum_required(VERSION 3.14)
project(csce240_f21_p1)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/47f819c3ca54fb602f432904443e00a0a1fe2f42.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
	  login
	  main.cpp
)
target_link_libraries(
	login
	gtest_main
)

include(GoogleTest)
gtest_discover_tests(login)
