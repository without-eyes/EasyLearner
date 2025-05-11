/********************************************************************************
** Form generated from reading UI file 'TopicCreation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPICCREATION_H
#define UI_TOPICCREATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopicCreation
{
public:
    QPushButton *createButton;
    QLineEdit *nameLineEdit;
    QLabel *label;
    QPushButton *goBackButton;

    void setupUi(QWidget *TopicCreation)
    {
        if (TopicCreation->objectName().isEmpty())
            TopicCreation->setObjectName(QString::fromUtf8("TopicCreation"));
        TopicCreation->resize(400, 300);
        createButton = new QPushButton(TopicCreation);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(110, 190, 201, 31));
        nameLineEdit = new QLineEdit(TopicCreation);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(110, 140, 201, 21));
        label = new QLabel(TopicCreation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 60, 201, 41));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        goBackButton = new QPushButton(TopicCreation);
        goBackButton->setObjectName(QString::fromUtf8("goBackButton"));
        goBackButton->setGeometry(QRect(110, 230, 201, 31));

        retranslateUi(TopicCreation);

        QMetaObject::connectSlotsByName(TopicCreation);
    } // setupUi

    void retranslateUi(QWidget *TopicCreation)
    {
        TopicCreation->setWindowTitle(QCoreApplication::translate("TopicCreation", "TopicCreation", nullptr));
        createButton->setText(QCoreApplication::translate("TopicCreation", "Create topic", nullptr));
        nameLineEdit->setText(QString());
        nameLineEdit->setPlaceholderText(QCoreApplication::translate("TopicCreation", "Enter topic name...", nullptr));
        label->setText(QCoreApplication::translate("TopicCreation", "Create topic", nullptr));
        goBackButton->setText(QCoreApplication::translate("TopicCreation", "Go back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TopicCreation: public Ui_TopicCreation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPICCREATION_H
