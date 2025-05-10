/********************************************************************************
** Form generated from reading UI file 'TopicStudy.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPICSTUDY_H
#define UI_TOPICSTUDY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopicStudy
{
public:
    QLabel *label;
    QPushButton *qndButton;
    QPushButton *questionsButton;
    QPushButton *definitionsButton;
    QPushButton *goBackButton;

    void setupUi(QWidget *TopicStudy)
    {
        if (TopicStudy->objectName().isEmpty())
            TopicStudy->setObjectName(QString::fromUtf8("TopicStudy"));
        TopicStudy->resize(400, 300);
        label = new QLabel(TopicStudy);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 30, 131, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        qndButton = new QPushButton(TopicStudy);
        qndButton->setObjectName(QString::fromUtf8("qndButton"));
        qndButton->setGeometry(QRect(100, 90, 191, 41));
        questionsButton = new QPushButton(TopicStudy);
        questionsButton->setObjectName(QString::fromUtf8("questionsButton"));
        questionsButton->setGeometry(QRect(100, 140, 191, 41));
        definitionsButton = new QPushButton(TopicStudy);
        definitionsButton->setObjectName(QString::fromUtf8("definitionsButton"));
        definitionsButton->setGeometry(QRect(100, 190, 191, 41));
        goBackButton = new QPushButton(TopicStudy);
        goBackButton->setObjectName(QString::fromUtf8("goBackButton"));
        goBackButton->setGeometry(QRect(100, 240, 191, 41));

        retranslateUi(TopicStudy);

        QMetaObject::connectSlotsByName(TopicStudy);
    } // setupUi

    void retranslateUi(QWidget *TopicStudy)
    {
        TopicStudy->setWindowTitle(QCoreApplication::translate("TopicStudy", "TopicStudy", nullptr));
        label->setText(QCoreApplication::translate("TopicStudy", "Study", nullptr));
        qndButton->setText(QCoreApplication::translate("TopicStudy", "Questions and definitions", nullptr));
        questionsButton->setText(QCoreApplication::translate("TopicStudy", "Questions only", nullptr));
        definitionsButton->setText(QCoreApplication::translate("TopicStudy", "Definitions only", nullptr));
        goBackButton->setText(QCoreApplication::translate("TopicStudy", "Go back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TopicStudy: public Ui_TopicStudy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPICSTUDY_H
