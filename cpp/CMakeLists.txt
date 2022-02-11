cmake_minimum_required( VERSION 3.10 )

project(cpps CXX)

set(
    target
    tester
)

set(
    sources
    sender.cpp
    receiver.cpp
    main.cpp
)

set(
    headers
    sender.h
    receiver.h
)

add_executable(${target} ${sources})

target_include_directories(
    ${target}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
)

