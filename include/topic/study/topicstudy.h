#ifndef EASYLEARNER_TOPICSTUDY_H
#define EASYLEARNER_TOPICSTUDY_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class TopicStudy; }
QT_END_NAMESPACE

class TopicStudy final : public QWidget {
Q_OBJECT

public:
    explicit TopicStudy(QWidget *parent = nullptr);

    ~TopicStudy() override;

public slots:

    void studyQuestionsAndDefinitions();

    void studyQuestions();

    void studyDefinitions();

    void goBack();

private:
    Ui::TopicStudy *ui;
};


#endif //EASYLEARNER_TOPICSTUDY_H
