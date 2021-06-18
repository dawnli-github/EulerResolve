cmake_minimum_required(VERSION 3.14)



include_directories(${PROJECT_SOURCE_DIR}/include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

set(SRC 
    ${PROJECT_SOURCE_DIR}/src/ReadFile.cpp
    ${PROJECT_SOURCE_DIR}/src/Graph.cpp
    ${PROJECT_SOURCE_DIR}/src/Person.cpp
    ${PROJECT_SOURCE_DIR}/src/EulerResolve.cpp
)
add_library(test 
    ${SRC}
)

message(${PROJECT_SOURCE_DIR})

link_libraries(test)

add_executable(run ${PROJECT_SOURCE_DIR}/main.cpp)