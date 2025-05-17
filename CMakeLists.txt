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
        Sql
        REQUIRED)

add_executable(EasyLearner src/core/main.cpp
        src/mainmenu/mainmenu.cpp
        include/mainmenu/mainmenu.h
        forms/MainMenu.ui
        src/mainmenu/topiccreation.cpp
        include/mainmenu/topiccreation.h
        forms/TopicCreation.ui
        src/topic/base/topicmanagement.cpp
        include/topic/base/topicmanagement.h
        forms/TopicManagement.ui
        src/topic/creation/definitionaddition.cpp
        include/topic/creation/definitionaddition.h
        forms/DefinitionAddition.ui
        src/topic/content/topiccontent.cpp
        include/topic/content/topiccontent.h
        forms/TopicContent.ui
        src/topic/content/topicdefinitions.cpp
        include/topic/content/topicdefinitions.h
        forms/TopicDefinitions.ui
        src/topic/creation/questionaddition.cpp
        include/topic/creation/questionaddition.h
        forms/QuestionAddition.ui
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
        include/topic/base/content.h
        src/utils/database.cpp
        include/utils/database.h
        src/utils/randomizer.cpp
        include/utils/randomizer.h
        src/topic/study/studydefinitions.cpp
        include/topic/study/studydefinitions.h
        forms/StudyDefinitions.ui
        include/topic/creation/contentaddition.h
        src/topic/creation/contentaddition.cpp
        src/topic/content/topiccontentmanagement.cpp
        include/topic/content/topiccontentmanagement.h
        src/topic/study/studycontent.cpp
        include/topic/study/studycontent.h
        src/core/mainwindow.cpp
        include/core/mainwindow.h
)

target_include_directories(EasyLearner PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(EasyLearner
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
)

