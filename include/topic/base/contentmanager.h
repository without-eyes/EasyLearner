/**
    * @file: contentmanager.h
    * @author: without eyes
    *
    * This file contains ContentManager class that manipulates with
    * questions-answers and terms-definitions.
*/

#ifndef EASYLEARNER_CONTENT_H
#define EASYLEARNER_CONTENT_H

#include <map>
#include "utils/database.h"

class ContentManager {
public:
    explicit ContentManager();

    void addIntoDefinitionMap(const QString &term, const QString &definition);

    void deleteFromDefinitionMap(const QString &term);

    std::map<QString, QString> getDefinitionMap();

    void addIntoQuestionMap(const QString &question, const QString &answer);

    void deleteFromQuestionMap(const QString &question);

    std::map<QString, QString> getQuestionMap();

    void setCurrentTopic(const QString &topic);

    QString getCurrentTopic();

    QList<QString> getTopicList();

    void pickTopic(const QString &topic);

    void createTopic(const QString &topic);

    void deleteTopic(const QString &topic);

    void loadContentFromDatabase();

    void loadTopicsFromModel(const QSharedPointer<QSqlTableModel>& model);

private:
    Database database;
    QString currentTopic;
    QList<QString> topicList;
    std::map<QString, std::map<QString, QString>> topicDefinitionMap;
    std::map<QString, std::map<QString, QString>> topicQuestionMap;

    void loadDefinitionsFromModel(const QSharedPointer<QSqlTableModel>& model);

    void loadQuestionsFromModel(const QSharedPointer<QSqlTableModel>& model);
};


#endif //EASYLEARNER_CONTENT_H
