project(haversineDistance)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(HEADERS ./src/haversine.hpp)
set(SRC ./src/haversine.cpp)

add_library(${PROJECT_NAME} STATIC ${SRC} ${HEADERS})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E  make_directory
			./include)


ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                       ../src/haversine.hpp
                       ./include)

enable_testing()
add_subdirectory(tests)

install(TARGETS ${PROJECT_NAME} 
	ARCHIVE DESTINATION ${PROJECT_NAME}/lib
)

