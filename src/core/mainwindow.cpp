/**
    * @file: mainwindow.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of MainWindow class.
*/

#include "core/mainwindow.h"

#include <qfile.h>

MainWindow::MainWindow() {
    allocateFields();
    addEveryWidgetToStack();
    setWindowNameArray();
    connectSignalsToSlots();
    configureMainWindow();
}

void MainWindow::allocateFields() {
    stackedWidget = new QStackedWidget(this);
    mainMenu = new MainMenu(this);
    topicCreation = new TopicCreation(this);
    topicManagement = new TopicManagement(this);
    topicContent = new TopicContent(this);
    topicDefinitions = new TopicDefinitions(this);
    topicQuestions = new TopicQuestions(this);
    definitionAddition = new DefinitionAddition(this);
    questionAddition = new QuestionAddition(this);
    topicStudy = new TopicStudy(this);
    studyDefinitions = new StudyDefinitions(this);
    studyQuestions = new StudyQuestions(this);
}

void MainWindow::addEveryWidgetToStack() const {
    stackedWidget->addWidget(mainMenu);
    stackedWidget->addWidget(topicCreation);
    stackedWidget->addWidget(topicManagement);
    stackedWidget->addWidget(topicContent);
    stackedWidget->addWidget(topicDefinitions);
    stackedWidget->addWidget(topicQuestions);
    stackedWidget->addWidget(definitionAddition);
    stackedWidget->addWidget(questionAddition);
    stackedWidget->addWidget(topicStudy);
    stackedWidget->addWidget(studyDefinitions);
    stackedWidget->addWidget(studyQuestions);
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
    connect(mainMenu, &MainMenu::requestPageChange, this, &MainWindow::changePage);
    connect(topicCreation, &TopicCreation::requestPageChange, this, &MainWindow::changePage);
    connect(topicManagement, &TopicManagement::requestPageChange, this, &MainWindow::changePage);
    connect(topicContent, &TopicContent::requestPageChange, this, &MainWindow::changePage);
    connect(topicDefinitions, &TopicDefinitions::requestPageChange, this, &MainWindow::changePage);
    connect(topicQuestions, &TopicQuestions::requestPageChange, this, &MainWindow::changePage);
    connect(definitionAddition, &DefinitionAddition::requestPageChange, this, &MainWindow::changePage);
    connect(questionAddition, &QuestionAddition::requestPageChange, this, &MainWindow::changePage);
    connect(topicStudy, &TopicStudy::requestPageChange, this, &MainWindow::changePage);
    connect(studyDefinitions, &StudyDefinitions::requestPageChange, this, &MainWindow::changePage);
    connect(studyQuestions, &StudyQuestions::requestPageChange, this, &MainWindow::changePage);
}

void MainWindow::connectMainMenuSignals() {
    connect(mainMenu, &MainMenu::setTopic, topicManagement, &TopicManagement::setTopic);
    connect(mainMenu, &MainMenu::loadTopicContent, topicManagement, &TopicManagement::loadTopicContent);
    connect(mainMenu, &MainMenu::setContentManagerSignal, topicManagement, &TopicManagement::setContentManager);
    connect(mainMenu, &MainMenu::setContentManagerSignal, topicCreation, &TopicCreation::setContentManager);
}

void MainWindow::connectTopicManagementSignals() {
    connect(topicManagement, &TopicManagement::setContentManagerSignal, topicStudy, &TopicStudy::setContentManager);
    connect(topicManagement, &TopicManagement::setContentManagerSignal, topicDefinitions, &TopicDefinitions::setContentManager);
    connect(topicManagement, &TopicManagement::setContentManagerSignal, definitionAddition, &DefinitionAddition::setContentManager);
    connect(topicManagement, &TopicManagement::updateDefinitionMapShowing, topicDefinitions, &TopicDefinitions::showContentList);
    connect(topicManagement, &TopicManagement::updateStudyDefinitionsButton, topicStudy, &TopicStudy::updateStudyDefinitionsButton);
    connect(topicManagement, &TopicManagement::setContentManagerSignal, topicQuestions, &TopicQuestions::setContentManager);
    connect(topicManagement, &TopicManagement::setContentManagerSignal, questionAddition, &QuestionAddition::setContentManager);
    connect(topicManagement, &TopicManagement::updateQuestionMapShowing, topicQuestions, &TopicQuestions::showContentList);
    connect(topicManagement, &TopicManagement::updateStudyQuestionsButton, topicStudy, &TopicStudy::updateStudyQuestionsButton);
}

void MainWindow::connectTopicStudySignals() {
    connect(topicStudy, &TopicStudy::setDefinitionMap, studyDefinitions, &StudyDefinitions::setTaskMap);
    connect(topicStudy, &TopicStudy::setQuestionMap, studyQuestions, &StudyQuestions::setTaskMap);
    connect(topicStudy, &TopicStudy::startDefinitionsStudy, studyDefinitions, &StudyDefinitions::studyDefinition);
    connect(topicStudy, &TopicStudy::startQuestionsStudy, studyQuestions, &StudyQuestions::studyQuestion);
}

void MainWindow::connectOtherSignals() {
    connect(topicCreation, &TopicCreation::topicCreated, mainMenu, &MainMenu::addTopicIntoList);
    connect(topicCreation, &TopicCreation::topicCreated, mainMenu, &MainMenu::changeButtonState);
    connect(topicContent, &TopicContent::updateDefinitionMapShowing, topicDefinitions, &TopicDefinitions::showContentList);
    connect(definitionAddition, &DefinitionAddition::updateDefinitionMapShowing, topicDefinitions, &TopicDefinitions::showContentList);
    connect(topicContent, &TopicContent::updateQuestionMapShowing, topicQuestions, &TopicQuestions::showContentList);
    connect(questionAddition, &QuestionAddition::updateQuestionMapShowing, topicQuestions, &TopicQuestions::showContentList);
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
