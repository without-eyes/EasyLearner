/**
    * @file: contentmanager.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of ContentManager class.
*/

#include "topic/base/contentmanager.h"

#include <QSqlRecord>
#include <QSharedPointer>
#include "utils/database.h"

ContentManager::ContentManager() = default;

void ContentManager::addIntoDefinitionMap(const QString &term, const QString &definition) {
    topicDefinitionMap[currentTopic][term] = definition;
    database.addTerm(term, definition);
}

void ContentManager::deleteFromDefinitionMap(const QString &term) {
    topicDefinitionMap[currentTopic].erase(term);
    database.deleteTerm(term);
}

std::map<QString, QString> ContentManager::getDefinitionMap() {
    return topicDefinitionMap[currentTopic];
}

void ContentManager::addIntoQuestionMap(const QString &question, const QString &answer) {
    topicQuestionMap[currentTopic][question] = answer;
    database.addQuestion(question, answer);
}

void ContentManager::deleteFromQuestionMap(const QString &question) {
    topicQuestionMap[currentTopic].erase(question);
    database.deleteQuestion(question);
}


std::map<QString, QString> ContentManager::getQuestionMap() {
    return topicQuestionMap[currentTopic];
}

void ContentManager::setCurrentTopic(const QString &topic) {
    currentTopic = topic;
}

QString ContentManager::getCurrentTopic() {
    return currentTopic;
}

QList<QString> ContentManager::getTopicList() {
    return topicList;
}

void ContentManager::createTopic(const QString &topic) {
    topicList.push_back(topic);
}

void ContentManager::deleteTopic(const QString &topic) {
    topicList.removeOne(topic);
    Database database;
    database.deleteTopic(topic);
}

void ContentManager::loadContentFromDatabase() {
    const Database database;
    loadDefinitionsFromModel(database.getAllTerms(currentTopic));
    loadQuestionsFromModel(database.getAllQuestions(currentTopic));
}

void ContentManager::loadDefinitionsFromModel(const QSharedPointer<QSqlTableModel>& model) {
    topicDefinitionMap[currentTopic].clear();

    const int termCol = model->fieldIndex("term");
    const int definitionCol = model->fieldIndex("definition");

    for (int i = 0; i < model->rowCount(); ++i) {
        QString term = model->record(i).value(termCol).toString();
        const QString definition = model->record(i).value(definitionCol).toString();
        topicDefinitionMap[currentTopic][term] = definition;
    }
}

void ContentManager::loadQuestionsFromModel(const QSharedPointer<QSqlTableModel>& model) {
    topicQuestionMap[currentTopic].clear();

    const int rowCount = model->rowCount();
    const int questionCol = model->fieldIndex("question");
    const int answerCol = model->fieldIndex("answer");

    for (int i = 0; i < rowCount; ++i) {
        QString question = model->record(i).value(questionCol).toString();
        const QString answer = model->record(i).value(answerCol).toString();
        topicQuestionMap[currentTopic][question] = answer;
    }

}

void ContentManager::loadTopicsFromModel(const QSharedPointer<QSqlTableModel> &model) {
    topicList.clear();

    const int topicCol = model->fieldIndex("topic");
    for (int i = 0; i < model->rowCount(); ++i) {
        QString topic = model->record(i).value(topicCol).toString();
        topicList.push_back(topic);
    }
}
