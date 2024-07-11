#include "../../include/utils/database.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

Database::Database() {
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("127.0.0.1");
    database.setDatabaseName("easylearner");
    database.setUserName("root");
    database.setPassword("password");
    if (!database.open()) {
        qDebug() << database.lastError().text();
    } else {
        qDebug() << "Success!";
    }
}

void Database::addTopic(QString topic) {
//    QSqlQuery query = QSqlQuery(database);
//    if (!query.exec()) {
//        qDebug() << query.lastError().databaseText();
//        qDebug() << query.lastError().driverText();
//    }
//
//    while (query.next()) {
//        qDebug() << query.
//    }
}

void Database::addTerm(QString term, QString definition) {

}

void Database::addQuestion(QString question, QString answer) {

}

void Database::deleteTopic(QString topic) {

}

void Database::deleteTerm(QString term, QString definition) {

}

void Database::deleteQuestion(QString question, QString answer) {

}

void Database::getAllTopics() {

}

void Database::getAllTerms() {

}

void Database::getAllQuestions() {

}

