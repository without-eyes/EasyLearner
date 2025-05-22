/**
    * @file: database.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of Database class.
*/

#include "utils/database.h"

#include <QSharedPointer>
#include <QSqlQuery>

Database::Database() {
    createDatabase();
}

void Database::createDatabase() {
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        database = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        database = QSqlDatabase::addDatabase("QSQLITE");
    }

    database.setDatabaseName("easylearner.db");
    database.open();

    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;");

    query.exec("CREATE TABLE IF NOT EXISTS topics ("
               "id INTEGER PRIMARY KEY,"
               "topic TEXT);");

    query.exec("CREATE TABLE IF NOT EXISTS questionsandanswers ("
               "id INTEGER PRIMARY KEY,"
               "topic_id INTEGER,"
               "question TEXT,"
               "answer TEXT,"
               "FOREIGN KEY (topic_id) REFERENCES topics(id));");

    query.exec("CREATE TABLE IF NOT EXISTS termsanddefinitions ("
               "id INTEGER PRIMARY KEY,"
               "topic_id INTEGER,"
               "term TEXT,"
               "definition TEXT,"
               "FOREIGN KEY (topic_id) REFERENCES topics(id));");
}

void Database::addTopic(const QString& topic) {
    QSqlQuery query;
    query.prepare("INSERT INTO topics (topic) VALUES (:topic)");
    query.bindValue(":topic", topic);
    query.exec();
}

void Database::addTerm(QString term, QString definition) {
    QSqlQuery query;
    query.exec("SELECT id FROM topics ORDER BY id DESC LIMIT 1");
    if (query.next()) {
        const int topicId = query.value(0).toInt();

        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO termsanddefinitions (topic_id, term, definition) "
                            "VALUES (:topic_id, :term, :definition)");
        insertQuery.bindValue(":topic_id", topicId);
        insertQuery.bindValue(":term", term);
        insertQuery.bindValue(":definition", definition);

        insertQuery.exec();
    }
}

void Database::addQuestion(const QString& question, const QString& answer) {
    QSqlQuery query;
    query.exec("SELECT id FROM topics ORDER BY id DESC LIMIT 1");
    if (query.next()) {
        const int topicId = query.value(0).toInt();

        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO questionsandanswers (topic_id, question, answer) "
                            "VALUES (:topic_id, :question, :answer)");
        insertQuery.bindValue(":topic_id", topicId);
        insertQuery.bindValue(":question", question);
        insertQuery.bindValue(":answer", answer);

        insertQuery.exec();
    }
}

void Database::deleteTopic(const QString& topic) {
    QSqlQuery query;
    query.prepare("DELETE FROM topics WHERE topic = :topic");
    query.bindValue(":topic", topic);
    query.exec();
}

void Database::deleteTerm(const QString& term) {
    QSqlQuery query;
    query.prepare("DELETE FROM termsanddefinitions WHERE term = :term");
    query.bindValue(":term", term);
    query.exec();
}

void Database::deleteQuestion(const QString& question) {
    QSqlQuery query;
    query.prepare("DELETE FROM questionsandanswers WHERE question = :question");
    query.bindValue(":question", question);
    query.exec();
}

QSharedPointer<QSqlTableModel> Database::getAllTopics() const {
    QSharedPointer<QSqlTableModel> model(new QSqlTableModel(nullptr, database));
    model->setTable("topics");
    model->select();
    return model;
}

QSharedPointer<QSqlTableModel> Database::getAllTerms(const QString& topic) const {
    QSqlQuery idQuery(database);
    idQuery.prepare("SELECT id FROM topics WHERE topic = :topic");
    idQuery.bindValue(":topic", topic);
    if (!idQuery.exec() || !idQuery.next()) {
        return nullptr;
    }

    const int topicId = idQuery.value(0).toInt();

    QSharedPointer<QSqlTableModel> model(new QSqlTableModel(nullptr, database));
    model->setTable("termsanddefinitions");
    model->setFilter(QString("topic_id = %1").arg(topicId));
    model->setSort(model->fieldIndex("topic_id"), Qt::AscendingOrder);
    model->select();

    return model;
}

QSharedPointer<QSqlTableModel> Database::getAllQuestions(const QString& topic) const {
    QSqlQuery idQuery(database);
    idQuery.prepare("SELECT id FROM topics WHERE topic = :topic");
    idQuery.bindValue(":topic", topic);
    if (!idQuery.exec() || !idQuery.next()) {
        return nullptr;
    }

    const int topicId = idQuery.value(0).toInt();

    QSharedPointer<QSqlTableModel> model(new QSqlTableModel(nullptr, database));
    model->setTable("questionsandanswers");
    model->setFilter(QString("topic_id = %1").arg(topicId));
    model->setSort(model->fieldIndex("topic_id"), Qt::AscendingOrder);
    model->select();

    return model;
}