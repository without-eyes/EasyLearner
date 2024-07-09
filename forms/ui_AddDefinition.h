/********************************************************************************
** Form generated from reading UI file 'AddDefinition.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDEFINITION_H
#define UI_ADDDEFINITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddDefinition
{
public:
    QLineEdit *termLineEdit;
    QLineEdit *definitionLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *goBackButton;
    QPushButton *createButton;

    void setupUi(QWidget *AddDefinition)
    {
        if (AddDefinition->objectName().isEmpty())
            AddDefinition->setObjectName(QString::fromUtf8("AddDefinition"));
        AddDefinition->resize(400, 300);
        termLineEdit = new QLineEdit(AddDefinition);
        termLineEdit->setObjectName(QString::fromUtf8("termLineEdit"));
        termLineEdit->setGeometry(QRect(110, 110, 201, 21));
        definitionLineEdit = new QLineEdit(AddDefinition);
        definitionLineEdit->setObjectName(QString::fromUtf8("definitionLineEdit"));
        definitionLineEdit->setGeometry(QRect(110, 150, 201, 21));
        label = new QLabel(AddDefinition);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 30, 191, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setTabletTracking(false);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(AddDefinition);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 110, 41, 17));
        label_3 = new QLabel(AddDefinition);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 150, 61, 17));
        goBackButton = new QPushButton(AddDefinition);
        goBackButton->setObjectName(QString::fromUtf8("goBackButton"));
        goBackButton->setGeometry(QRect(100, 240, 211, 31));
        createButton = new QPushButton(AddDefinition);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(100, 200, 211, 31));

        retranslateUi(AddDefinition);

        QMetaObject::connectSlotsByName(AddDefinition);
    } // setupUi

    void retranslateUi(QWidget *AddDefinition)
    {
        AddDefinition->setWindowTitle(QCoreApplication::translate("AddDefinition", "AddDefinition", nullptr));
        label->setText(QCoreApplication::translate("AddDefinition", "Add new definition", nullptr));
        label_2->setText(QCoreApplication::translate("AddDefinition", "Term:", nullptr));
        label_3->setText(QCoreApplication::translate("AddDefinition", "Defition:", nullptr));
        goBackButton->setText(QCoreApplication::translate("AddDefinition", "Go back", nullptr));
        createButton->setText(QCoreApplication::translate("AddDefinition", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDefinition: public Ui_AddDefinition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDEFINITION_H
