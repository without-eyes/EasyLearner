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
        Multimedia
        REQUIRED)

qt5_add_resources(RESOURCES resources/resources.qrc)

if(WIN32)
    set(WIN_ICON resources/resources.rc
            src/utils/soundplayer.cpp
            include/utils/soundplayer.h)
endif()

add_executable(EasyLearner src/core/main.cpp
        ${WIN_ICON}
        ${RESOURCES}
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
        src/topic/base/contentmanager.cpp
        include/topic/base/contentmanager.h
        src/utils/database.cpp
        include/utils/database.h
        src/utils/randomizer.cpp
        include/utils/randomizer.h
        src/topic/study/studydefinitions.cpp
        include/topic/study/studydefinitions.h
        forms/StudyDefinitions.ui
        include/topic/creation/icontentaddition.h
        src/topic/creation/icontentaddition.cpp
        src/topic/content/itopiccontentmanagement.cpp
        include/topic/content/itopiccontentmanagement.h
        src/topic/study/istudycontent.cpp
        include/topic/study/istudycontent.h
        src/core/mainwindow.cpp
        include/core/mainwindow.h
        include/core/pageindex.h
        src/utils/soundplayer.cpp
        include/utils/soundplayer.h
)

target_include_directories(EasyLearner PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(EasyLearner
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        Qt5::Multimedia
)

