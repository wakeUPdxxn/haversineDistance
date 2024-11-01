project(SimpleTest)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(This SimpleTest)

set(FETCHCONTENT_BASE_DIR "${CMAKE_BINARY_DIR}/googletest")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)

# Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
include_directories(../${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} SimpleTest.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE haversineDistance gtest gtest_main)

add_test(
	NAME ${This}
	COMMAND ${This}
)