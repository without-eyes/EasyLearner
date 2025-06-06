/**
    * @file: topicmanagement.h
    * @author: without eyes
    *
    * This file contains TopicManagement class for "Topic Management" window.
*/

#ifndef EASYLEARNER_TOPICMANAGEMENT_H
#define EASYLEARNER_TOPICMANAGEMENT_H

#include <QLabel>
#include <set>

#include "contentmanager.h"
#include "core/pageindex.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TopicManagement; }
QT_END_NAMESPACE

class TopicManagement final : public QWidget {
Q_OBJECT

public:
    explicit TopicManagement(QWidget *parent = nullptr);

    ~TopicManagement() override;

signals:
    void requestPageChange(PageIndex index);

    void updateDefinitionMapShowing();

    void updateQuestionMapShowing();

    void updateStudyDefinitionsButton();

    void updateStudyQuestionsButton();

    void setContentManagerSignal(const std::shared_ptr<ContentManager> &contentManager);

public slots:
    void setContentManager(const std::shared_ptr<ContentManager> &contentManager);

    void loadTopicContent();

    void setTopic(const QString &topic) const;

    void startStudy();

    void addDefinition();

    void addQuestion();

    void showTopicContent();

    void goBack();

private:
    Ui::TopicManagement *ui;
    std::shared_ptr<ContentManager> contentManager;
};


#endif //EASYLEARNER_TOPICMANAGEMENT_H
