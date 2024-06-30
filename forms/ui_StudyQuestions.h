/********************************************************************************
** Form generated from reading UI file 'StudyQuestions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDYQUESTIONS_H
#define UI_STUDYQUESTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudyQuestions {
public:
    QLabel *questionLabel;
    QLineEdit *answerLineEdit;
    QPushButton *checkButton;
    QLabel *correctnessLabel;

    void setupUi(QWidget *StudyQuestions) {
        if (StudyQuestions->objectName().isEmpty())
            StudyQuestions->setObjectName(QString::fromUtf8("StudyQuestions"));
        StudyQuestions->resize(400, 300);
        questionLabel = new QLabel(StudyQuestions);
        questionLabel->setObjectName(QString::fromUtf8("questionLabel"));
        questionLabel->setGeometry(QRect(40, 70, 311, 61));
        answerLineEdit = new QLineEdit(StudyQuestions);
        answerLineEdit->setObjectName(QString::fromUtf8("answerLineEdit"));
        answerLineEdit->setGeometry(QRect(40, 140, 321, 25));
        checkButton = new QPushButton(StudyQuestions);
        checkButton->setObjectName(QString::fromUtf8("checkButton"));
        checkButton->setGeometry(QRect(120, 210, 161, 51));
        correctnessLabel = new QLabel(StudyQuestions);
        correctnessLabel->setObjectName(QString::fromUtf8("correctnessLabel"));
        correctnessLabel->setGeometry(QRect(40, 170, 321, 31));

        retranslateUi(StudyQuestions);

        QMetaObject::connectSlotsByName(StudyQuestions);
    } // setupUi

    void retranslateUi(QWidget *StudyQuestions) {
        StudyQuestions->setWindowTitle(QCoreApplication::translate("StudyQuestions", "StudyQuestions", nullptr));
        questionLabel->setText(QString());
        answerLineEdit->setInputMask(QString());
        answerLineEdit->setText(QString());
        answerLineEdit->setPlaceholderText(QCoreApplication::translate("StudyQuestions", "Answer...", nullptr));
        checkButton->setText(QCoreApplication::translate("StudyQuestions", "Check", nullptr));
        correctnessLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StudyQuestions : public Ui_StudyQuestions {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDYQUESTIONS_H
