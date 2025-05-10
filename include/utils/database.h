#ifndef EASYLEARNER_DATABASE_H
#define EASYLEARNER_DATABASE_H

#include <QSqlTableModel>

class Database {
public:
    Database();

    void addTopic(QString topic);

    void addTerm(QString term, QString definition);

    void addQuestion(QString question, QString answer);

    void deleteTopic(QString topic);

    void deleteTerm(QString term, QString definition);

    void deleteQuestion(QString question, QString answer);

    QSqlTableModel getAllTopics();

    QSqlTableModel getAllTerms();

    QSqlTableModel getAllQuestions();

private:
    static QSqlDatabase database;
};


#endif //EASYLEARNER_DATABASE_H
