cmake_minimum_required(VERSION 3.10)
project(ProofLock)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProofLock
    app/main.cpp
    platform/Windows/ProcessUtils.cpp
)