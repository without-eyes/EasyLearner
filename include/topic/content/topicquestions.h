#ifndef EASYLEARNER_TOPICQUESTIONS_H
#define EASYLEARNER_TOPICQUESTIONS_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class TopicQuestions; }
QT_END_NAMESPACE

class TopicQuestions : public QWidget {
Q_OBJECT

public slots:

    void deleteQuestion();

    void goBack();

    void changeButtonState();

public:
    explicit TopicQuestions(QWidget *parent = nullptr);

    ~TopicQuestions() override;

private:
    Ui::TopicQuestions *ui;

    void showQuestionList();
};


#endif //EASYLEARNER_TOPICQUESTIONS_H
