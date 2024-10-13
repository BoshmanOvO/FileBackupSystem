cmake_minimum_required(VERSION 3.29)
project(Comm)

set(CMAKE_CXX_STANDARD 20)

add_executable(Comm main.cpp
        FileBackups/BlockInfo.cpp
        FileBackups/FIleBackup.cpp
        FileBackups/MainBackup.cpp
        FileBackups/BlockInfo.h
        FileBackups/FileBackup.h
        FileBackups/MainBackup.h
)
