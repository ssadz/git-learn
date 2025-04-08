cmake_minimum_required(VERSION 3.10)
project(GitLearn)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行文件
add_executable(calculator 
    main.cpp
    Welcome.cpp
    Calculator.cpp
)

# 包含头文件目录
target_include_directories(calculator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}) 