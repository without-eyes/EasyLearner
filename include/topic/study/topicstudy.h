/**
    * @file: topicstudy.h
    * @author: without eyes
    *
    * This file contains StudyTopic class for "Study Topic" window.
*/

#ifndef EASYLEARNER_TOPICSTUDY_H
#define EASYLEARNER_TOPICSTUDY_H

#include <QWidget>
#include "core/pageindex.h"
#include "topic/base/contentmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TopicStudy; }
QT_END_NAMESPACE

class TopicStudy final : public QWidget {
Q_OBJECT

signals:
    void requestPageChange(PageIndex index);

    void startQuestionsStudy();

    void startDefinitionsStudy();

    void setDefinitionMap(const std::map<QString, QString>& definitionMap);

    void setQuestionMap(const std::map<QString, QString>& questionMap);

public:
    explicit TopicStudy(QWidget *parent = nullptr);

    ~TopicStudy() override;

public slots:
    void setContentManager(const std::shared_ptr<ContentManager> &contentManager);

    void updateStudyQuestionsButton() const;

    void updateStudyDefinitionsButton() const;

    void studyQuestions();

    void studyDefinitions();

    void goBack();

private:
    Ui::TopicStudy *ui;
    std::shared_ptr<ContentManager> contentManager;
};


#endif //EASYLEARNER_TOPICSTUDY_H
