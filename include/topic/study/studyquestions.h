#ifndef EASYLEARNER_STUDYQUESTIONS_H
#define EASYLEARNER_STUDYQUESTIONS_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class StudyQuestions; }
QT_END_NAMESPACE

class StudyQuestions final : public QWidget {
Q_OBJECT

public:
    explicit StudyQuestions(QWidget *parent = nullptr);

    ~StudyQuestions() override;

    static void setTaskMap(const std::map<QString, QString> &taskMap);

public slots:

    void checkAnswer();

    void showNextTask();

    void changeButtonState() const;

private:
    void pickRandomTask();

    Ui::StudyQuestions *ui;
    static std::map<QString, QString> taskMap;
    QString question;
    QString answer;
};


#endif //EASYLEARNER_STUDYQUESTIONS_H
