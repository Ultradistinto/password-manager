cmake_minimum_required(VERSION 3.10)
project(PasswordManager)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(password_manager 
    src/main.c
    src/my_string.c
    src/my_txt.c
    ) 