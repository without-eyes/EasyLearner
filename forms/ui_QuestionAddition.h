/********************************************************************************
** Form generated from reading UI file 'QuestionAddition.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONADDITION_H
#define UI_QUESTIONADDITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionAddition
{
public:
    QLabel *label;
    QLineEdit *questionLineEdit;
    QLabel *label_3;
    QPushButton *createButton;
    QLineEdit *answerLineEdit;
    QLabel *label_2;
    QPushButton *goBackButton;

    void setupUi(QWidget *QuestionAddition)
    {
        if (QuestionAddition->objectName().isEmpty())
            QuestionAddition->setObjectName(QString::fromUtf8("QuestionAddition"));
        QuestionAddition->resize(400, 300);
        label = new QLabel(QuestionAddition);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 40, 191, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setTabletTracking(false);
        label->setAlignment(Qt::AlignCenter);
        questionLineEdit = new QLineEdit(QuestionAddition);
        questionLineEdit->setObjectName(QString::fromUtf8("questionLineEdit"));
        questionLineEdit->setGeometry(QRect(110, 120, 201, 21));
        label_3 = new QLabel(QuestionAddition);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 160, 61, 17));
        createButton = new QPushButton(QuestionAddition);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(100, 200, 211, 31));
        answerLineEdit = new QLineEdit(QuestionAddition);
        answerLineEdit->setObjectName(QString::fromUtf8("answerLineEdit"));
        answerLineEdit->setGeometry(QRect(110, 160, 201, 21));
        label_2 = new QLabel(QuestionAddition);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 120, 71, 20));
        goBackButton = new QPushButton(QuestionAddition);
        goBackButton->setObjectName(QString::fromUtf8("goBackButton"));
        goBackButton->setGeometry(QRect(100, 240, 211, 31));

        retranslateUi(QuestionAddition);

        QMetaObject::connectSlotsByName(QuestionAddition);
    } // setupUi

    void retranslateUi(QWidget *AddQuestion)
    {
        AddQuestion->setWindowTitle(QCoreApplication::translate("QuestionAddition", "QuestionAddition", nullptr));
        label->setText(QCoreApplication::translate("QuestionAddition", "Add new Question", nullptr));
        label_3->setText(QCoreApplication::translate("QuestionAddition", "Answer:", nullptr));
        createButton->setText(QCoreApplication::translate("QuestionAddition", "Create", nullptr));
        label_2->setText(QCoreApplication::translate("QuestionAddition", "Question:", nullptr));
        goBackButton->setText(QCoreApplication::translate("QuestionAddition", "Go back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionAddition: public Ui_QuestionAddition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONADDITION_H
