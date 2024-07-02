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

add_executable(EasyLearner src/mainmenu/main.cpp
        src/mainmenu/mainmenu.cpp
        include/mainmenu/mainmenu.h
        forms/MainMenu.ui
        src/mainmenu/createtopic.cpp
        include/mainmenu/createtopic.h
        forms/CreateTopic.ui
        src/topic/base/managetopic.cpp
        include/topic/base/managetopic.h
        forms/ManageTopic.ui
        src/topic/creation/adddefinition.cpp
        include/topic/creation/adddefinition.h
        forms/AddDefinition.ui
        src/topic/content/topiccontent.cpp
        include/topic/content/topiccontent.h
        forms/TopicContent.ui
        src/topic/content/topicdefinitions.cpp
        include/topic/content/topicdefinitions.h
        forms/TopicDefinitions.ui
        src/topic/creation/addquestion.cpp
        include/topic/creation/addquestion.h
        forms/AddQuestion.ui
        src/topic/content/topicquestions.cpp
        include/topic/content/topicquestions.h
        forms/TopicQuestions.ui
        src/topic/study/topicstudy.cpp
        include/topic/study/topicstudy.h
        forms/TopicStudy.ui
        src/topic/study/studyquestions.cpp
        include/topic/study/studyquestions.h
        forms/StudyQuestions.ui
        src/topic/base/content.cpp
        include/topic/base/content.h)
target_link_libraries(EasyLearner
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

