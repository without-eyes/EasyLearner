/**
    * @file: database.h
    * @author: without eyes
    *
    * This file contains Database class that works with MySQL database.
*/

#ifndef EASYLEARNER_DATABASE_H
#define EASYLEARNER_DATABASE_H

#include <QSqlTableModel>

class Database {
public:
    Database();

    void createDatabase();

    void addTopic(const QString& topic);

    void addTerm(QString term, QString definition);

    void addQuestion(const QString& question, const QString& answer);

    void deleteTopic(const QString& topic);

    void deleteTerm(const QString& term);

    void deleteQuestion(const QString& question);

    QSqlTableModel* getAllTopics() const;

    QSqlTableModel* getAllTerms(const QString& topic) const;

    QSqlTableModel* getAllQuestions(const QString& topic) const;

private:
    QSqlDatabase database;
};


#endif //EASYLEARNER_DATABASE_H
