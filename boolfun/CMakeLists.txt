cmake_minimum_required(VERSION 3.5)

project(boolfun_exe)

include_directories(headers src src/private_headers)

SET(CMAKE_CXX_FLAGS "-std=c++11")

set(HEADERS
        headers/bitslib.h
        headers/boolean_utils.h
        headers/GF.h
        headers/polynom.h
        headers/ttable.h
        headers/linear.h
        headers/ANF.h
        headers/ios.h
        )

set(PRIVATE_HEADERS
        src/private_headers/Field_polynom_table.h
        src/private_headers/GF_simple.h
        )

set(SOURCES
        src/GF.cpp
        src/GFSimple.cpp
        src/main.cpp
        src/polynom.cpp
        src/ttable.cpp
        src/linear.cpp
        src/ANF.cpp
        src/ios.cpp
        src/bitslib.cpp
        src/boolean_utils.cpp
        )

add_executable(boolfun_exe ${HEADERS} ${PRIVATE_HEADERS} ${SOURCES})