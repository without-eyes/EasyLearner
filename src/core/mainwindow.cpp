/**
    * @file: mainwindow.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of MainWindow class.
*/

#include "core/mainwindow.h"

#include <qfile.h>
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

MainWindow::MainWindow() {
    addEveryWidgetToStack();
    setWindowNameArray();
    connectSignalsToSlots();
    configureMainWindow();
}

void MainWindow::addEveryWidgetToStack() {
    widgets = {
        new MainMenu(),
        new TopicCreation(this),
        new TopicManagement(this),
        new TopicContent(this),
        new TopicDefinitions(this),
        new TopicQuestions(this),
        new DefinitionAddition(this),
        new QuestionAddition(this),
        new TopicStudy(this),
        new StudyDefinitions(this),
        new StudyQuestions(this),
    };

    stackedWidget = new QStackedWidget(this);
    for (const auto widget : widgets) {
        stackedWidget->addWidget(widget);
    }
}

void MainWindow::setWindowNameArray() {
    windowNames[MAIN_MENU_PAGE] = "EasyLearner - Main Menu";
    windowNames[TOPIC_CREATION_PAGE] = "EasyLearner - Topic Creation";
    windowNames[TOPIC_MANAGEMENT_PAGE] = "EasyLearner - Topic Management";
    windowNames[TOPIC_CONTENT_PAGE] = "EasyLearner - Content";
    windowNames[TOPIC_DEFINITIONS_PAGE] = "EasyLearner - Definitions";
    windowNames[TOPIC_QUESTIONS_PAGE] = "EasyLearner - Questions";
    windowNames[DEFINITION_ADDITION_PAGE] = "EasyLearner - Definition Addition";
    windowNames[QUESTION_ADDITION_PAGE] = "EasyLearner - Question Addition";
    windowNames[TOPIC_STUDY_PAGE] = "EasyLearner - Studying";
    windowNames[STUDY_DEFINITIONS_PAGE] = "EasyLearner - Definition Studying";
    windowNames[STUDY_QUESTIONS_PAGE] = "EasyLearner - Question Studying";
}

void MainWindow::connectPageChangeSignals() {
    connect(qobject_cast<MainMenu*>(widgets[MAIN_MENU_PAGE]), &MainMenu::requestPageChange, this, &MainWindow::changePage);
    connect(qobject_cast<TopicCreation*>(widgets[TOPIC_CREATION_PAGE]), &TopicCreation::requestPageChange, this, &MainWindow::changePage);
    connect(qobject_cast<TopicManagement*>(widgets[TOPIC_MANAGEMENT_PAGE]), &TopicManagement::requestPageChange, this, &MainWindow::changePage);
    connect(qobject_cast<TopicContent*>(widgets[TOPIC_CONTENT_PAGE]), &TopicContent::requestPageChange, this, &MainWindow::changePage);
    connect(qobject_cast<TopicDefinitions*>(widgets[TOPIC_DEFINITIONS_PAGE]), &TopicDefinitions::requestPageChange, this, &MainWindow::changePage);
    connect(qobject_cast<TopicQuestions*>(widgets[TOPIC_QUESTIONS_PAGE]), &TopicQuestions::requestPageChange, this, &MainWindow::changePage);
    connect(qobject_cast<DefinitionAddition*>(widgets[DEFINITION_ADDITION_PAGE]), &DefinitionAddition::requestPageChange, this, &MainWindow::changePage);
    connect(qobject_cast<QuestionAddition*>(widgets[QUESTION_ADDITION_PAGE]), &QuestionAddition::requestPageChange, this, &MainWindow::changePage);
    connect(qobject_cast<TopicStudy*>(widgets[TOPIC_STUDY_PAGE]), &TopicStudy::requestPageChange, this, &MainWindow::changePage);
    connect(qobject_cast<StudyDefinitions*>(widgets[STUDY_DEFINITIONS_PAGE]), &StudyDefinitions::requestPageChange, this, &MainWindow::changePage);
    connect(qobject_cast<StudyQuestions*>(widgets[STUDY_QUESTIONS_PAGE]), &StudyQuestions::requestPageChange, this, &MainWindow::changePage);
}

void MainWindow::connectMainMenuSignals() {
    connect(qobject_cast<MainMenu*>(widgets[MAIN_MENU_PAGE]), &MainMenu::setTopic, qobject_cast<TopicManagement*>(widgets[TOPIC_MANAGEMENT_PAGE]), &TopicManagement::setTopic);
    connect(qobject_cast<MainMenu*>(widgets[MAIN_MENU_PAGE]), &MainMenu::loadTopicContent, qobject_cast<TopicManagement*>(widgets[TOPIC_MANAGEMENT_PAGE]), &TopicManagement::loadTopicContent);
    connect(qobject_cast<MainMenu*>(widgets[MAIN_MENU_PAGE]), &MainMenu::setContentManagerSignal, qobject_cast<TopicManagement*>(widgets[TOPIC_MANAGEMENT_PAGE]), &TopicManagement::setContentManager);
    connect(qobject_cast<MainMenu*>(widgets[MAIN_MENU_PAGE]), &MainMenu::setContentManagerSignal, qobject_cast<TopicCreation*>(widgets[TOPIC_CREATION_PAGE]), &TopicCreation::setContentManager);
}

void MainWindow::connectTopicManagementSignals() {
    connect(qobject_cast<TopicManagement*>(widgets[TOPIC_MANAGEMENT_PAGE]), &TopicManagement::setContentManagerSignal, qobject_cast<TopicStudy*>(widgets[TOPIC_STUDY_PAGE]), &TopicStudy::setContentManager);
    connect(qobject_cast<TopicManagement*>(widgets[TOPIC_MANAGEMENT_PAGE]), &TopicManagement::setContentManagerSignal, qobject_cast<TopicDefinitions*>(widgets[TOPIC_DEFINITIONS_PAGE]), &TopicDefinitions::setContentManager);
    connect(qobject_cast<TopicManagement*>(widgets[TOPIC_MANAGEMENT_PAGE]), &TopicManagement::setContentManagerSignal, qobject_cast<DefinitionAddition*>(widgets[DEFINITION_ADDITION_PAGE]), &DefinitionAddition::setContentManager);
    connect(qobject_cast<TopicManagement*>(widgets[TOPIC_MANAGEMENT_PAGE]), &TopicManagement::updateDefinitionMapShowing, qobject_cast<TopicDefinitions*>(widgets[TOPIC_DEFINITIONS_PAGE]), &TopicDefinitions::showContentList);
    connect(qobject_cast<TopicManagement*>(widgets[TOPIC_MANAGEMENT_PAGE]), &TopicManagement::updateStudyDefinitionsButton, qobject_cast<TopicStudy*>(widgets[TOPIC_STUDY_PAGE]), &TopicStudy::updateStudyDefinitionsButton);
    connect(qobject_cast<TopicManagement*>(widgets[TOPIC_MANAGEMENT_PAGE]), &TopicManagement::setContentManagerSignal, qobject_cast<TopicQuestions*>(widgets[TOPIC_QUESTIONS_PAGE]), &TopicQuestions::setContentManager);
    connect(qobject_cast<TopicManagement*>(widgets[TOPIC_MANAGEMENT_PAGE]), &TopicManagement::setContentManagerSignal, qobject_cast<QuestionAddition*>(widgets[QUESTION_ADDITION_PAGE]), &QuestionAddition::setContentManager);
    connect(qobject_cast<TopicManagement*>(widgets[TOPIC_MANAGEMENT_PAGE]), &TopicManagement::updateQuestionMapShowing, qobject_cast<TopicQuestions*>(widgets[TOPIC_QUESTIONS_PAGE]), &TopicQuestions::showContentList);
    connect(qobject_cast<TopicManagement*>(widgets[TOPIC_MANAGEMENT_PAGE]), &TopicManagement::updateStudyQuestionsButton, qobject_cast<TopicStudy*>(widgets[TOPIC_STUDY_PAGE]), &TopicStudy::updateStudyQuestionsButton);
}

void MainWindow::connectTopicStudySignals() {
    connect(qobject_cast<TopicStudy*>(widgets[TOPIC_STUDY_PAGE]), &TopicStudy::setDefinitionMap, qobject_cast<StudyDefinitions*>(widgets[STUDY_DEFINITIONS_PAGE]), &StudyDefinitions::setTaskMap);
    connect(qobject_cast<TopicStudy*>(widgets[TOPIC_STUDY_PAGE]), &TopicStudy::setQuestionMap, qobject_cast<StudyQuestions*>(widgets[STUDY_QUESTIONS_PAGE]), &StudyQuestions::setTaskMap);
    connect(qobject_cast<TopicStudy*>(widgets[TOPIC_STUDY_PAGE]), &TopicStudy::startDefinitionsStudy, qobject_cast<StudyDefinitions*>(widgets[STUDY_DEFINITIONS_PAGE]), &StudyDefinitions::studyDefinition);
    connect(qobject_cast<TopicStudy*>(widgets[TOPIC_STUDY_PAGE]), &TopicStudy::startQuestionsStudy, qobject_cast<StudyQuestions*>(widgets[STUDY_QUESTIONS_PAGE]), &StudyQuestions::studyQuestion);
}

void MainWindow::connectOtherSignals() {
    connect(qobject_cast<TopicCreation*>(widgets[TOPIC_CREATION_PAGE]), &TopicCreation::topicCreated, qobject_cast<MainMenu*>(widgets[MAIN_MENU_PAGE]), &MainMenu::addTopicIntoList);
    connect(qobject_cast<TopicCreation*>(widgets[TOPIC_CREATION_PAGE]), &TopicCreation::topicCreated, qobject_cast<MainMenu*>(widgets[MAIN_MENU_PAGE]), &MainMenu::changeButtonState);
    connect(qobject_cast<TopicContent*>(widgets[TOPIC_CONTENT_PAGE]), &TopicContent::updateDefinitionMapShowing, qobject_cast<TopicDefinitions*>(widgets[TOPIC_DEFINITIONS_PAGE]), &TopicDefinitions::showContentList);
    connect(qobject_cast<DefinitionAddition*>(widgets[DEFINITION_ADDITION_PAGE]), &DefinitionAddition::updateDefinitionMapShowing, qobject_cast<TopicDefinitions*>(widgets[TOPIC_DEFINITIONS_PAGE]), &TopicDefinitions::showContentList);
    connect(qobject_cast<TopicContent*>(widgets[TOPIC_CONTENT_PAGE]), &TopicContent::updateQuestionMapShowing, qobject_cast<TopicQuestions*>(widgets[TOPIC_QUESTIONS_PAGE]), &TopicQuestions::showContentList);
    connect(qobject_cast<QuestionAddition*>(widgets[QUESTION_ADDITION_PAGE]), &QuestionAddition::updateQuestionMapShowing, qobject_cast<TopicQuestions*>(widgets[TOPIC_QUESTIONS_PAGE]), &TopicQuestions::showContentList);
}

void MainWindow::connectSignalsToSlots() {
    connectPageChangeSignals();
    connectMainMenuSignals();
    connectTopicManagementSignals();
    connectTopicStudySignals();
    connectOtherSignals();
}

void MainWindow::configureMainWindow() {
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowIcon(QIcon(":/assets/img/icon.png"));
    setWindowTitle(windowNames[0]);
    setCentralWidget(stackedWidget);
    resize(400, 300);
    this->setFixedSize(this->size());
    setAppStyle();
}

void MainWindow::setAppStyle() {
    if (QFile file(":/assets/style.qss"); file.open(QFile::ReadOnly | QFile::Text)) {
        const QString style = file.readAll();
        this->setStyleSheet(style);
        file.close();
    }
}

void MainWindow::changePage(const PageIndex index) {
    setWindowTitle(windowNames[index]);
    stackedWidget->setCurrentIndex(index);
}