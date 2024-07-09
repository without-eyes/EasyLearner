/********************************************************************************
** Form generated from reading UI file 'TopicDefinitions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPICDEFINITIONS_H
#define UI_TOPICDEFINITIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopicDefinitions
{
public:
    QListWidget *listWidget;
    QPushButton *goBackButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *TopicDefinitions)
    {
        if (TopicDefinitions->objectName().isEmpty())
            TopicDefinitions->setObjectName(QString::fromUtf8("TopicDefinitions"));
        TopicDefinitions->resize(400, 300);
        listWidget = new QListWidget(TopicDefinitions);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 20, 361, 231));
        goBackButton = new QPushButton(TopicDefinitions);
        goBackButton->setObjectName(QString::fromUtf8("goBackButton"));
        goBackButton->setGeometry(QRect(200, 260, 181, 25));
        deleteButton = new QPushButton(TopicDefinitions);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(20, 260, 171, 25));

        retranslateUi(TopicDefinitions);

        QMetaObject::connectSlotsByName(TopicDefinitions);
    } // setupUi

    void retranslateUi(QWidget *TopicDefinitions)
    {
        TopicDefinitions->setWindowTitle(QCoreApplication::translate("TopicDefinitions", "TopicDefinitions", nullptr));
        goBackButton->setText(QCoreApplication::translate("TopicDefinitions", "Go back", nullptr));
        deleteButton->setText(QCoreApplication::translate("TopicDefinitions", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TopicDefinitions: public Ui_TopicDefinitions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPICDEFINITIONS_H
