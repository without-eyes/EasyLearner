//
// Created by without-eyes on 10.06.24.
//

#ifndef EASYLEARNER_CREATETOPIC_H
#define EASYLEARNER_CREATETOPIC_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class CreateTopic; }
QT_END_NAMESPACE

class CreateTopic : public QWidget {
Q_OBJECT

public:
    explicit CreateTopic(QWidget *parent = nullptr);

    ~CreateTopic() override;

private:
    Ui::CreateTopic *ui;
};


#endif //EASYLEARNER_CREATETOPIC_H
