//
// Created by without-eyes on 23.06.24.
//

#ifndef EASYLEARNER_ADDQUESTION_H
#define EASYLEARNER_ADDQUESTION_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class AddQuestion; }
QT_END_NAMESPACE

class AddQuestion : public QWidget {
Q_OBJECT

public:
    explicit AddQuestion(QWidget *parent = nullptr);

    ~AddQuestion() override;

public slots:

    void addQuestion();

private:
    Ui::AddQuestion *ui;
};


#endif //EASYLEARNER_ADDQUESTION_H
