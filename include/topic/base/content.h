/**
    * @file: content.h
    * @author: without eyes
    *
    * This file contains Content class that manipulates with
    * questions-answers and terms-definitions.
*/

#ifndef EASYLEARNER_CONTENT_H
#define EASYLEARNER_CONTENT_H

#include <map>
#include "utils/database.h"

class Content {
public:
    explicit Content();

    static void addIntoDefinitionMap(const QString &term, const QString &definition);

    static void deleteFromDefinitionMap(const QString &term);

    static std::map<QString, QString> getDefinitionMap();

    static void addIntoQuestionMap(const QString &question, const QString &answer);

    static void deleteFromQuestionMap(const QString &question);

    static std::map<QString, QString> getQuestionMap();

    static void setCurrentTopic(const QString &topic);

    static QString getCurrentTopic();

    static void loadContentFromDatabase();

private:
    static Database database;
    static QString currentTopic;
    static std::map<QString, std::map<QString, QString>> topicDefinitionMap;
    static std::map<QString, std::map<QString, QString>> topicQuestionMap;

    static void loadDefinitionsFromModel(const QSqlTableModel* model);

    static void loadQuestionsFromModel(const QSqlTableModel* model);
};


#endif //EASYLEARNER_CONTENT_H
