cmake_minimum_required(VERSION 3.28)
project(EasyLearner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(EasyLearner src/main.cpp
        src/mainmenu.cpp
        include/mainmenu.h
        forms/MainMenu.ui
        src/createtopic.cpp
        include/createtopic.h
        forms/CreateTopic.ui
        src/managetopic.cpp
        include/managetopic.h
        forms/ManageTopic.ui
        src/adddefinition.cpp
        include/adddefinition.h
        forms/AddDefinition.ui)
target_link_libraries(EasyLearner
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

