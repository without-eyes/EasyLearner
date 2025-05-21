/**
    * @file: content.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of Content class.
*/

#include "topic/base/content.h"

#include <QSqlRecord>

#include "utils/database.h"

Database Content::database;
QString Content::currentTopic;
std::map<QString, std::map<QString, QString>> Content::topicDefinitionMap;
std::map<QString, std::map<QString, QString>> Content::topicQuestionMap;

Content::Content() = default;

void Content::addIntoDefinitionMap(const QString &term, const QString &definition) {
    topicDefinitionMap[currentTopic][term] = definition;
    database.addTerm(term, definition);
}

void Content::deleteFromDefinitionMap(const QString &term) {
    topicDefinitionMap[currentTopic].erase(term);
    database.deleteTerm(term);
}

std::map<QString, QString> Content::getDefinitionMap() {
    return topicDefinitionMap[currentTopic];
}

void Content::addIntoQuestionMap(const QString &question, const QString &answer) {
    topicQuestionMap[currentTopic][question] = answer;
    database.addQuestion(question, answer);
}

void Content::deleteFromQuestionMap(const QString &question) {
    topicQuestionMap[currentTopic].erase(question);
    database.deleteQuestion(question);
}


std::map<QString, QString> Content::getQuestionMap() {
    return topicQuestionMap[currentTopic];
}

void Content::setCurrentTopic(const QString &topic) {
    currentTopic = topic;
}

QString Content::getCurrentTopic() {
    return currentTopic;
}

void Content::loadContentFromDatabase() {
    const Database database;
    loadDefinitionsFromModel(database.getAllTerms(currentTopic));
    loadQuestionsFromModel(database.getAllQuestions(currentTopic));
}

void Content::loadDefinitionsFromModel(const QSqlTableModel* model) {
    topicDefinitionMap[currentTopic].clear();

    const int termCol = model->fieldIndex("term");
    const int definitionCol = model->fieldIndex("definition");

    for (int i = 0; i < model->rowCount(); ++i) {
        QString term = model->record(i).value(termCol).toString();
        QString definition = model->record(i).value(definitionCol).toString();
        topicDefinitionMap[currentTopic][term] = definition;
    }
}

void Content::loadQuestionsFromModel(const QSqlTableModel*model) {
    topicQuestionMap[currentTopic].clear();

    const int rowCount = model->rowCount();
    const int questionCol = model->fieldIndex("question");
    const int answerCol = model->fieldIndex("answer");

    for (int i = 0; i < rowCount; ++i) {
        QString question = model->record(i).value(questionCol).toString();
        QString answer = model->record(i).value(answerCol).toString();
        topicQuestionMap[currentTopic][question] = answer;
    }

}
