/**
    * @file: mainwindow.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of MainWindow class.
*/

#include "../../include/core/mainwindow.h"

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

MainWindow::MainWindow() {
    this->setAttribute(Qt::WA_DeleteOnClose);

    const auto stack = new QStackedWidget(this);
    const auto mainMenu = new MainMenu(this);
    const auto topicCreation = new TopicCreation(this);
    const auto topicManagement = new TopicManagement(this);
    const auto topicContent = new TopicContent(this);
    const auto topicDefinitions = new TopicDefinitions(this);
    const auto topicQuestions = new TopicQuestions(this);
    const auto definitionAddition = new DefinitionAddition(this);
    const auto questionAddition = new QuestionAddition(this);
    const auto topicStudy = new TopicStudy(this);
    const auto studyDefinitions = new StudyDefinitions(this);
    const auto studyQuestions = new StudyQuestions(this);

    stack->addWidget(mainMenu);             // 0
    stack->addWidget(topicCreation);        // 1
    stack->addWidget(topicManagement);      // 2
    stack->addWidget(topicContent);         // 3
    stack->addWidget(topicDefinitions);     // 4
    stack->addWidget(topicQuestions);       // 5
    stack->addWidget(definitionAddition);   // 6
    stack->addWidget(questionAddition);     // 7
    stack->addWidget(topicStudy);           // 8
    stack->addWidget(studyDefinitions);     // 9
    stack->addWidget(studyQuestions);       // 10

    connect(mainMenu, &MainMenu::requestPageChange, stack, &QStackedWidget::setCurrentIndex);
    connect(topicCreation, &TopicCreation::requestPageChange, stack, &QStackedWidget::setCurrentIndex);
    connect(topicManagement, &TopicManagement::requestPageChange, stack, &QStackedWidget::setCurrentIndex);
    connect(topicContent, &TopicContent::requestPageChange, stack, &QStackedWidget::setCurrentIndex);
    connect(topicDefinitions, &TopicDefinitions::requestPageChange, stack, &QStackedWidget::setCurrentIndex);
    connect(topicQuestions, &TopicQuestions::requestPageChange, stack, &QStackedWidget::setCurrentIndex);
    connect(definitionAddition, &DefinitionAddition::requestPageChange, stack, &QStackedWidget::setCurrentIndex);
    connect(questionAddition, &QuestionAddition::requestPageChange, stack, &QStackedWidget::setCurrentIndex);
    connect(topicStudy, &TopicStudy::requestPageChange, stack, &QStackedWidget::setCurrentIndex);
    connect(studyDefinitions, &StudyDefinitions::requestPageChange, stack, &QStackedWidget::setCurrentIndex);
    connect(studyQuestions, &StudyQuestions::requestPageChange, stack, &QStackedWidget::setCurrentIndex);

    connect(topicCreation, &TopicCreation::topicCreated, mainMenu, &MainMenu::addTopicIntoList);
    connect(mainMenu, &MainMenu::setTopic, topicManagement, &TopicManagement::setTopic);

    connect(definitionAddition, &DefinitionAddition::updateDefinitionMapShowing, topicDefinitions, &TopicDefinitions::showContentList);
    connect(definitionAddition, &DefinitionAddition::updateStudyDefinitionsButton, topicStudy, &TopicStudy::updateStudyDefinitionsButton);
    connect(topicDefinitions, &TopicDefinitions::updateStudyDefinitionsButton, topicStudy, &TopicStudy::updateStudyDefinitionsButton);
    connect(topicStudy, &TopicStudy::startDefinitionsStudy, studyDefinitions, &StudyDefinitions::studyDefinition);

    connect(questionAddition, &QuestionAddition::updateQuestionMapShowing, topicQuestions, &TopicQuestions::showContentList);
    connect(questionAddition, &QuestionAddition::updateStudyQuestionsButton, topicStudy, &TopicStudy::updateStudyQuestionsButton);
    connect(topicQuestions, &TopicQuestions::updateStudyButton, topicStudy, &TopicStudy::updateStudyQuestionsButton);
    connect(topicStudy, &TopicStudy::startQuestionsStudy, studyQuestions, &StudyQuestions::studyQuestion);

    this->setCentralWidget(stack);
    this->resize(400, 300);
}