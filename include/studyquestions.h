#ifndef EASYLEARNER_STUDYQUESTIONS_H
#define EASYLEARNER_STUDYQUESTIONS_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class StudyQuestions; }
QT_END_NAMESPACE

class StudyQuestions : public QWidget {
Q_OBJECT

public:
    explicit StudyQuestions(QWidget *parent = nullptr);

    ~StudyQuestions() override;

private:
    Ui::StudyQuestions *ui;
};


#endif //EASYLEARNER_STUDYQUESTIONS_H
