cmake_minimum_required(VERSION 3.10)

# Define the project
project(TaskListManager)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Qt setup
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


find_package(Qt6 COMPONENTS Widgets REQUIRED)

# SQLite setup
find_package(SQLite3 REQUIRED)

find_package(Qt6 COMPONENTS Widgets Sql REQUIRED)




# Include directories
include_directories(include)

# Ensure MOC processes task_manager_gui.h
set(MOC_HEADERS include/task_manager_gui.h)
qt6_wrap_cpp(MOC_SOURCES ${MOC_HEADERS})



# Add source files
set(SOURCES
    src/main.cpp
    src/task_model.cpp
    src/task_view.cpp
    src/task_controller.cpp
    src/task_manager_gui.cpp
    
    ${MOC_SOURCES}
)

# Add headers for MOC processing
set(HEADERS
    include/task_model.h
    include/task_view.h
    include/task_controller.h
    include/task_manager_gui.h
    
)

# Add executable
add_executable(tasklist_manager ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(tasklist_manager PRIVATE Qt6::Widgets Qt6::Sql SQLite::SQLite3)
































