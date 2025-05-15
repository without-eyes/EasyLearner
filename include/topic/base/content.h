/**
    * @file: content.h
    * @author: without eyes
    *
    * This file contains Content class that manipulates with
    * questions-answers and terms-definitions.
*/

#ifndef EASYLEARNER_CONTENT_H
#define EASYLEARNER_CONTENT_H

#include <QString>
#include <map>

class Content {
public:
    explicit Content(const QString &topicName);

    static void addIntoDefinitionMap(const QString &term, const QString &definition);

    static void deleteFromDefinitionMap(const QString &term);

    static std::map<QString, QString> getDefinitionMap();

    static void addIntoQuestionMap(const QString &question, const QString &answer);

    static void deleteFromQuestionMap(const QString &question);

    static std::map<QString, QString> getQuestionMap();

    static void setCurrentTopic(const QString &topic);

    static QString getCurrentTopic();

private:
    static QString currentTopic;
    static std::map<QString, std::map<QString, QString>> topicDefinitionMap;
    static std::map<QString, std::map<QString, QString>> topicQuestionMap;
};


#endif //EASYLEARNER_CONTENT_H
