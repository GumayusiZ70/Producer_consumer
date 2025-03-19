cmake_minimum_required(VERSION 3.28.3)
project(producer_consumer_project)

set(CMAKE_CXX_STANDARD 11)

# 指定头文件路径
include_directories(inc)

# 查找src目录下所有.cpp 文件并添加main.cpp
file(GLOB SOURCES "src/*.cpp" "main.cpp")

# 创建可执行文件
add_executable(producer_consumer_project ${SOURCES})
