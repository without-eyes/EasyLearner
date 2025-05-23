/**
    * @file: topiccontent.h
    * @author: without eyes
    *
    * This file contains TopicContent class for "Topic ContentManager" window.
*/

#ifndef EASYLEARNER_TOPICCONTENT_H
#define EASYLEARNER_TOPICCONTENT_H

#include <QWidget>
#include "core/pageindex.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TopicContent; }
QT_END_NAMESPACE

class TopicContent final : public QWidget {
Q_OBJECT

signals:
    void requestPageChange(PageIndex index);

    void updateDefinitionMapShowing();

    void updateQuestionMapShowing();

public:
    explicit TopicContent(QWidget *parent = nullptr);

    ~TopicContent() override;

public slots:

    void showDefinition();

    void showQuestionsAnswers();

    void goBack();

private:
    Ui::TopicContent *ui;
};


#endif //EASYLEARNER_TOPICCONTENT_H
