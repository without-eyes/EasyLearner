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
#include "core/pageindex.h"
#include "topic/base/contentmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TopicDefinitions; }
QT_END_NAMESPACE

class TopicDefinitions final : public TopicContentManagement {
Q_OBJECT

signals:
    void requestPageChange(PageIndex index);

public slots:

    void deleteContent() override;

    void goBack() override;

    void changeButtonState() const override;

    void showContentList() override;

public:
    explicit TopicDefinitions(QWidget *parent = nullptr);

    ~TopicDefinitions() override;

private:
    Ui::TopicDefinitions *ui;
};


#endif