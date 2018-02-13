cmake_minimum_required(VERSION 3.2)

project(TopologyWars)
include_directories(include)

find_package(Qt5Widgets)
include_directories(${Qt5Widgets_INCLUDE_DIRS})

# Suggested for CMake & QT but not undersood or needed yet
#add_definitions(${Qt5Widgets_DEFINITIONS})
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
#qt5_generate_moc(main.cpp main.moc)

add_executable(TopologyWars 
        src/main.cpp
        src/window.cpp
        )

target_link_libraries(TopologyWars Qt5::Widgets)
