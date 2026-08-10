cmake_minimum_required(VERSION 4.3.3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS on)

project(DEFERTEST LANGUAGES CXX)

if(CMAKE_BUILD_TYPE MATCHES Release)
    Message("Build Type: Release")
    add_compile_options(-O3)
elseif(CMAKE_BUILD_TYPE MATCHES Debug)
    Message("Build Type: Debug")
    add_compile_options(-Og)
endif()
add_compile_options()

find_package(PkgConfig)

aux_source_directory(src SOURCES_FILES)

message(${CMAKE_CURRENT_LIST_DIR})
message("src: ${SOURCES_FILES}")

include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCES_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
message("Libs: ${LIBS_FILES}")
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS_FILES})
target_link_options(${PROJECT_NAME} PRIVATE -flto)
