project(haversineDistance)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(HEADERS include/haversine.hpp)
set(SRC src/haversine.cpp)
set(-DCMAKE_INSTALL_PREFIX=${PROJECT_SOURCE_DIR})

add_library(${PROJECT_NAME} STATIC ${SRC} ${HEADERS})
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${HEADERS})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory
                       ${PROJECT_SOURCE_DIR}/lib)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy
                       $<TARGET_FILE_NAME:${PROJECT_NAME}>
                       ${PROJECT_SOURCE_DIR}/lib/)


enable_testing()
add_subdirectory(tests)

install(TARGETS ${PROJECT_NAME} 
	PUBLIC_HEADER
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME} 
)

