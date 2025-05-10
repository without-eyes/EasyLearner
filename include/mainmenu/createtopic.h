/**
    * @file: createtopic.h
    * @author: without eyes
    *
    * This file contains CreateTopic class for "Create Topic" window.
*/

#ifndef EASYLEARNER_CREATETOPIC_H
#define EASYLEARNER_CREATETOPIC_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CreateTopic; }
QT_END_NAMESPACE

class CreateTopic final : public QWidget {
Q_OBJECT

public:
    explicit CreateTopic(QWidget *parent = nullptr);

    ~CreateTopic() override;

private slots:

    void createNewTopic();

    void changeButtonState() const;

    void goBack();

private:
    Ui::CreateTopic *ui;
};


#endif //EASYLEARNER_CREATETOPIC_H
