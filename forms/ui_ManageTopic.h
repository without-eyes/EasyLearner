/********************************************************************************
** Form generated from reading UI file 'ManageTopic.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGETOPIC_H
#define UI_MANAGETOPIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageTopic
{
public:
    QPushButton *studyButton;
    QPushButton *addDefinitionButton;
    QPushButton *addQuestionButton;
    QPushButton *showContentButton;
    QLabel *label;
    QPushButton *goBackButton;

    void setupUi(QWidget *ManageTopic)
    {
        if (ManageTopic->objectName().isEmpty())
            ManageTopic->setObjectName(QString::fromUtf8("ManageTopic"));
        ManageTopic->resize(400, 300);
        studyButton = new QPushButton(ManageTopic);
        studyButton->setObjectName(QString::fromUtf8("studyButton"));
        studyButton->setGeometry(QRect(100, 70, 211, 31));
        addDefinitionButton = new QPushButton(ManageTopic);
        addDefinitionButton->setObjectName(QString::fromUtf8("addDefinitionButton"));
        addDefinitionButton->setGeometry(QRect(100, 110, 211, 31));
        addQuestionButton = new QPushButton(ManageTopic);
        addQuestionButton->setObjectName(QString::fromUtf8("addQuestionButton"));
        addQuestionButton->setGeometry(QRect(100, 150, 211, 31));
        showContentButton = new QPushButton(ManageTopic);
        showContentButton->setObjectName(QString::fromUtf8("showContentButton"));
        showContentButton->setGeometry(QRect(100, 190, 211, 31));
        label = new QLabel(ManageTopic);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 20, 211, 41));
        label->setAlignment(Qt::AlignCenter);
        goBackButton = new QPushButton(ManageTopic);
        goBackButton->setObjectName(QString::fromUtf8("goBackButton"));
        goBackButton->setGeometry(QRect(100, 230, 211, 31));

        retranslateUi(ManageTopic);

        QMetaObject::connectSlotsByName(ManageTopic);
    } // setupUi

    void retranslateUi(QWidget *ManageTopic)
    {
        ManageTopic->setWindowTitle(QCoreApplication::translate("ManageTopic", "ManageTopic", nullptr));
        studyButton->setText(QCoreApplication::translate("ManageTopic", "Study", nullptr));
        addDefinitionButton->setText(QCoreApplication::translate("ManageTopic", "Add new defenition", nullptr));
        addQuestionButton->setText(QCoreApplication::translate("ManageTopic", "Add new question", nullptr));
        showContentButton->setText(QCoreApplication::translate("ManageTopic", "Show topic content", nullptr));
        label->setText(QCoreApplication::translate("ManageTopic", "Topic name", nullptr));
        goBackButton->setText(QCoreApplication::translate("ManageTopic", "Go back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageTopic: public Ui_ManageTopic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGETOPIC_H
