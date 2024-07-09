/********************************************************************************
** Form generated from reading UI file 'TopicQuestions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPICQUESTIONS_H
#define UI_TOPICQUESTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopicQuestions
{
public:
    QListWidget *listWidget;
    QPushButton *deleteButton;
    QPushButton *goBackButton;

    void setupUi(QWidget *TopicQuestions)
    {
        if (TopicQuestions->objectName().isEmpty())
            TopicQuestions->setObjectName(QString::fromUtf8("TopicQuestions"));
        TopicQuestions->resize(400, 300);
        listWidget = new QListWidget(TopicQuestions);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 20, 361, 231));
        deleteButton = new QPushButton(TopicQuestions);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(20, 260, 171, 25));
        goBackButton = new QPushButton(TopicQuestions);
        goBackButton->setObjectName(QString::fromUtf8("goBackButton"));
        goBackButton->setGeometry(QRect(200, 260, 181, 25));

        retranslateUi(TopicQuestions);

        QMetaObject::connectSlotsByName(TopicQuestions);
    } // setupUi

    void retranslateUi(QWidget *TopicQuestions)
    {
        TopicQuestions->setWindowTitle(QCoreApplication::translate("TopicQuestions", "TopicQuestions", nullptr));
        deleteButton->setText(QCoreApplication::translate("TopicQuestions", "Delete", nullptr));
        goBackButton->setText(QCoreApplication::translate("TopicQuestions", "Go back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TopicQuestions: public Ui_TopicQuestions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPICQUESTIONS_H
