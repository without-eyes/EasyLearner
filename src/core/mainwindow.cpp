/**
    * @file: mainwindow.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of MainWindow class.
*/

#include "core/mainwindow.h"

MainWindow::MainWindow() {
    allocateFields();
    addEveryWidgetToStack();
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

void MainWindow::connectSignalsToSlots() {
    connect(mainMenu, &MainMenu::requestPageChange, stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(topicCreation, &TopicCreation::requestPageChange, stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(topicManagement, &TopicManagement::requestPageChange, stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(topicContent, &TopicContent::requestPageChange, stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(topicDefinitions, &TopicDefinitions::requestPageChange, stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(topicQuestions, &TopicQuestions::requestPageChange, stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(definitionAddition, &DefinitionAddition::requestPageChange, stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(questionAddition, &QuestionAddition::requestPageChange, stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(topicStudy, &TopicStudy::requestPageChange, stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(studyDefinitions, &StudyDefinitions::requestPageChange, stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(studyQuestions, &StudyQuestions::requestPageChange, stackedWidget, &QStackedWidget::setCurrentIndex);

    connect(topicCreation, &TopicCreation::topicCreated, mainMenu, &MainMenu::addTopicIntoList);
    connect(topicCreation, &TopicCreation::topicCreated, mainMenu, &MainMenu::changeButtonState);
    connect(mainMenu, &MainMenu::setTopic, topicManagement, &TopicManagement::setTopic);
    connect(mainMenu, &MainMenu::loadTopicContent, topicManagement, &TopicManagement::loadTopicContent);

    connect(topicManagement, &TopicManagement::updateDefinitionMapShowing, topicDefinitions, &TopicDefinitions::showContentList);
    connect(topicContent, &TopicContent::updateDefinitionMapShowing, topicDefinitions, &TopicDefinitions::showContentList);
    connect(definitionAddition, &DefinitionAddition::updateDefinitionMapShowing, topicDefinitions, &TopicDefinitions::showContentList);
    connect(definitionAddition, &DefinitionAddition::updateStudyDefinitionsButton, topicStudy, &TopicStudy::updateStudyDefinitionsButton);
    connect(topicDefinitions, &TopicDefinitions::updateStudyDefinitionsButton, topicStudy, &TopicStudy::updateStudyDefinitionsButton);
    connect(topicStudy, &TopicStudy::startDefinitionsStudy, studyDefinitions, &StudyDefinitions::studyDefinition);

    connect(topicManagement, &TopicManagement::updateQuestionMapShowing, topicQuestions, &TopicQuestions::showContentList);
    connect(topicContent, &TopicContent::updateQuestionMapShowing, topicQuestions, &TopicQuestions::showContentList);
    connect(questionAddition, &QuestionAddition::updateQuestionMapShowing, topicQuestions, &TopicQuestions::showContentList);
    connect(questionAddition, &QuestionAddition::updateStudyQuestionsButton, topicStudy, &TopicStudy::updateStudyQuestionsButton);
    connect(topicQuestions, &TopicQuestions::updateStudyButton, topicStudy, &TopicStudy::updateStudyQuestionsButton);
    connect(topicStudy, &TopicStudy::startQuestionsStudy, studyQuestions, &StudyQuestions::studyQuestion);
}

void MainWindow::configureMainWindow() {
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowIcon(QIcon(":/assets/img/icon.png"));
    setCentralWidget(stackedWidget);
    resize(400, 300);
}