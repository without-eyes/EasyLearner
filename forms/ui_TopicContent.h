/********************************************************************************
** Form generated from reading UI file 'TopicContent.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPICCONTENT_H
#define UI_TOPICCONTENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopicContent {
public:
    QLabel *label;
    QPushButton *definitionButton;
    QPushButton *qaButton;
    QPushButton *goBackButton;

    void setupUi(QWidget *TopicContent) {
        if (TopicContent->objectName().isEmpty())
            TopicContent->setObjectName(QString::fromUtf8("TopicContent"));
        TopicContent->resize(400, 300);
        label = new QLabel(TopicContent);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 40, 141, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        definitionButton = new QPushButton(TopicContent);
        definitionButton->setObjectName(QString::fromUtf8("definitionButton"));
        definitionButton->setGeometry(QRect(120, 120, 161, 41));
        qaButton = new QPushButton(TopicContent);
        qaButton->setObjectName(QString::fromUtf8("qaButton"));
        qaButton->setGeometry(QRect(120, 170, 161, 41));
        goBackButton = new QPushButton(TopicContent);
        goBackButton->setObjectName(QString::fromUtf8("goBackButton"));
        goBackButton->setGeometry(QRect(120, 220, 161, 41));

        retranslateUi(TopicContent);

        QMetaObject::connectSlotsByName(TopicContent);
    } // setupUi

    void retranslateUi(QWidget *TopicContent) {
        TopicContent->setWindowTitle(QCoreApplication::translate("TopicContent", "TopicContent", nullptr));
        label->setText(QCoreApplication::translate("TopicContent", "Topic content", nullptr));
        definitionButton->setText(QCoreApplication::translate("TopicContent", "Definition", nullptr));
        qaButton->setText(QCoreApplication::translate("TopicContent", "Questions-Answers", nullptr));
        goBackButton->setText(QCoreApplication::translate("TopicContent", "Go back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TopicContent : public Ui_TopicContent {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPICCONTENT_H
