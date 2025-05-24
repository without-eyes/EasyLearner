/**
    * @file: mainwindow.h
    * @author: without eyes
    *
    * This file contains MainWindow class that is main
    * window of EasyLearner.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "mainmenu/mainmenu.h"
#include "mainmenu/topiccreation.h"
#include "topic/base/topicmanagement.h"
#include "topic/content/topiccontent.h"
#include "topic/content/topicdefinitions.h"
#include "topic/content/topicquestions.h"
#include "topic/creation/definitionaddition.h"
#include "topic/creation/questionaddition.h"
#include "topic/study/studydefinitions.h"
#include "topic/study/studyquestions.h"
#include "topic/study/topicstudy.h"

class MainWindow final : public QMainWindow {
public:
    MainWindow();

private:
    QStackedWidget* stackedWidget;
    MainMenu* mainMenu;
    TopicCreation* topicCreation;
    TopicManagement* topicManagement;
    TopicContent* topicContent;
    TopicDefinitions* topicDefinitions;
    TopicQuestions* topicQuestions;
    DefinitionAddition* definitionAddition;
    QuestionAddition* questionAddition;
    TopicStudy* topicStudy;
    StudyDefinitions* studyDefinitions;
    StudyQuestions* studyQuestions;
    std::array<QString, 11> windowNames;

    void allocateFields();

    void addEveryWidgetToStack() const;

    void setWindowNameArray();

    void connectPageChangeSignals();

    void connectMainMenuSignals();

    void connectTopicManagementSignals();

    void connectTopicStudySignals();

    void connectOtherSignals();

    void connectSignalsToSlots();

    void configureMainWindow();

    void setAppStyle();

    void changePage(PageIndex index);
};



#endif //MAINWINDOW_H
