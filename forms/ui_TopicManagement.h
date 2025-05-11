/********************************************************************************
** Form generated from reading UI file 'TopicManagement.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPICMANAGEMENT_H
#define UI_TOPICMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopicManagement
{
public:
    QPushButton *studyButton;
    QPushButton *addDefinitionButton;
    QPushButton *addQuestionButton;
    QPushButton *showContentButton;
    QLabel *label;
    QPushButton *goBackButton;

    void setupUi(QWidget *TopicManagement)
    {
        if (TopicManagement->objectName().isEmpty())
            TopicManagement->setObjectName(QString::fromUtf8("TopicManagement"));
        TopicManagement->resize(400, 300);
        studyButton = new QPushButton(TopicManagement);
        studyButton->setObjectName(QString::fromUtf8("studyButton"));
        studyButton->setGeometry(QRect(100, 70, 211, 31));
        addDefinitionButton = new QPushButton(TopicManagement);
        addDefinitionButton->setObjectName(QString::fromUtf8("addDefinitionButton"));
        addDefinitionButton->setGeometry(QRect(100, 110, 211, 31));
        addQuestionButton = new QPushButton(TopicManagement);
        addQuestionButton->setObjectName(QString::fromUtf8("addQuestionButton"));
        addQuestionButton->setGeometry(QRect(100, 150, 211, 31));
        showContentButton = new QPushButton(TopicManagement);
        showContentButton->setObjectName(QString::fromUtf8("showContentButton"));
        showContentButton->setGeometry(QRect(100, 190, 211, 31));
        label = new QLabel(TopicManagement);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 20, 211, 41));
        label->setAlignment(Qt::AlignCenter);
        goBackButton = new QPushButton(TopicManagement);
        goBackButton->setObjectName(QString::fromUtf8("goBackButton"));
        goBackButton->setGeometry(QRect(100, 230, 211, 31));

        retranslateUi(TopicManagement);

        QMetaObject::connectSlotsByName(TopicManagement);
    } // setupUi

    void retranslateUi(QWidget *ManageTopic)
    {
        ManageTopic->setWindowTitle(QCoreApplication::translate("TopicManagement", "TopicManagement", nullptr));
        studyButton->setText(QCoreApplication::translate("TopicManagement", "Study", nullptr));
        addDefinitionButton->setText(QCoreApplication::translate("TopicManagement", "Add new defenition", nullptr));
        addQuestionButton->setText(QCoreApplication::translate("TopicManagement", "Add new question", nullptr));
        showContentButton->setText(QCoreApplication::translate("TopicManagement", "Show topic content", nullptr));
        label->setText(QCoreApplication::translate("TopicManagement", "Topic name", nullptr));
        goBackButton->setText(QCoreApplication::translate("TopicManagement", "Go back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TopicManagement: public Ui_TopicManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPICMANAGEMENT_H
