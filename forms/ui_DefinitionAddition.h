/********************************************************************************
** Form generated from reading UI file 'DefinitionAddition.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFINITIONADDITION_H
#define UI_DEFINITIONADDITION_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DefinitionAddition
{
public:
    QLineEdit *termLineEdit;
    QLineEdit *definitionLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *goBackButton;
    QPushButton *createButton;

    void setupUi(QWidget *DefinitionAddition)
    {
        if (DefinitionAddition->objectName().isEmpty())
            DefinitionAddition->setObjectName(QString::fromUtf8("DefinitionAddition"));
        DefinitionAddition->resize(400, 300);
        termLineEdit = new QLineEdit(DefinitionAddition);
        termLineEdit->setObjectName(QString::fromUtf8("termLineEdit"));
        termLineEdit->setGeometry(QRect(110, 110, 201, 21));
        definitionLineEdit = new QLineEdit(DefinitionAddition);
        definitionLineEdit->setObjectName(QString::fromUtf8("definitionLineEdit"));
        definitionLineEdit->setGeometry(QRect(110, 150, 201, 21));
        label = new QLabel(DefinitionAddition);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 30, 191, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setTabletTracking(false);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(DefinitionAddition);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 110, 41, 17));
        label_3 = new QLabel(DefinitionAddition);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 150, 61, 17));
        goBackButton = new QPushButton(DefinitionAddition);
        goBackButton->setObjectName(QString::fromUtf8("goBackButton"));
        goBackButton->setGeometry(QRect(100, 240, 211, 31));
        createButton = new QPushButton(DefinitionAddition);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(100, 200, 211, 31));

        retranslateUi(DefinitionAddition);

        QMetaObject::connectSlotsByName(DefinitionAddition);
    } // setupUi

    void retranslateUi(QWidget *AddDefinition)
    {
        AddDefinition->setWindowTitle(QCoreApplication::translate("DefinitionAddition", "DefinitionAddition", nullptr));
        label->setText(QCoreApplication::translate("DefinitionAddition", "Add new definition", nullptr));
        label_2->setText(QCoreApplication::translate("DefinitionAddition", "Term:", nullptr));
        label_3->setText(QCoreApplication::translate("DefinitionAddition", "Definition:", nullptr));
        goBackButton->setText(QCoreApplication::translate("DefinitionAddition", "Go back", nullptr));
        createButton->setText(QCoreApplication::translate("DefinitionAddition", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DefinitionAddition: public Ui_DefinitionAddition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFINITIONADDITION_H
