cmake_minimum_required(VERSION 3.10)

# Define the project name
project(TaskListManager)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# Add the executable
add_executable(tasklist_manager src/main.cpp src/task.cpp src/task_manager.cpp)
