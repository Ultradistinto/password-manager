cmake_minimum_required(VERSION 3.10)
project(PasswordManager)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Main application
add_executable(password_manager 
    src/main.c
    src/my_string.c
    src/my_txt.c
    src/my_linked_list.c
)
target_include_directories(password_manager PRIVATE include)

# Unit tests
add_executable(tests
    tests/my_string_tests.c
    tests/my_linked_list_tests.c
    tests/my_txt_tests.c
    tests/test_runner.c

    src/my_string.c
    src/my_linked_list.c
    src/my_txt.c
    src/my_comparator.c
)
target_include_directories(tests PRIVATE include)