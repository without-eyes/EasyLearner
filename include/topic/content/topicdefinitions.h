/**
    * @file: topicdefinitions.h
    * @author: without eyes
    *
    * This file contains TopicDefinitions class for "Topic Definitions" window.
*/

#ifndef EASYLEARNER_TOPICDEFINITIONS_H
#define EASYLEARNER_TOPICDEFINITIONS_H

#include <QWidget>
#include "topiccontentmanagement.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TopicDefinitions; }
QT_END_NAMESPACE

class TopicDefinitions final : public QWidget, public TopicContentManagement {
Q_OBJECT

public slots:

    void deleteContent() const override;

    void goBack() override;

    void changeButtonState() const override;

public:
    explicit TopicDefinitions(QWidget *parent = nullptr);

    ~TopicDefinitions() override;

private:
    Ui::TopicDefinitions *ui;

    void showContentList() override;
};


#endif