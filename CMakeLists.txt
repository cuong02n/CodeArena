cmake_minimum_required(VERSION 3.10)
project(Codeforces)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE ALL_CPP_FILES "codeforces/working/*.cpp")

foreach(SOURCE_FILE ${ALL_CPP_FILES})
    get_filename_component(ABS_PATH "${SOURCE_FILE}" ABSOLUTE)


    file(RELATIVE_PATH REL_PATH "${CMAKE_SOURCE_DIR}/codeforces" "${ABS_PATH}")

    string(REPLACE "/" "_" EXEC_NAME "${REL_PATH}")
    string(REPLACE ".cpp" "" EXEC_NAME "${EXEC_NAME}")

    add_executable(${EXEC_NAME} "${ABS_PATH}"
            codeforces/working/2118/2118C.cpp
    )
endforeach()
