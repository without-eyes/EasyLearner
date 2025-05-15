/**
    * @file: content.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of Content class.
*/

#include "topic/base/content.h"

QString Content::currentTopic;
std::map<QString, std::map<QString, QString>> Content::topicDefinitionMap;
std::map<QString, std::map<QString, QString>> Content::topicQuestionMap;

Content::Content(const QString &topicName) {

}

void Content::addIntoDefinitionMap(const QString &term, const QString &definition) {
    topicDefinitionMap[currentTopic][term] = definition;
}

void Content::deleteFromDefinitionMap(const QString &term) {
    topicDefinitionMap[currentTopic].erase(term);
}

std::map<QString, QString> Content::getDefinitionMap() {
    return topicDefinitionMap[currentTopic];
}

void Content::addIntoQuestionMap(const QString &question, const QString &answer) {
    topicQuestionMap[currentTopic][question] = answer;
}

void Content::deleteFromQuestionMap(const QString &question) {
    topicQuestionMap[currentTopic].erase(question);
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




