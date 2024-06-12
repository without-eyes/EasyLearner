#ifndef EASYLEARNER_MANAGETOPIC_H
#define EASYLEARNER_MANAGETOPIC_H

#include <QWidget>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class ManageTopic; }
QT_END_NAMESPACE

class ManageTopic : public QWidget {
Q_OBJECT

public:
    explicit ManageTopic(QWidget *parent = nullptr);

    ~ManageTopic() override;

    void setTopicName(const QString& topicName);

public slots:
    void startStudy();

    void addDefinition();

    void addQuestion();

    void showTopicQuestions();

    void goBack();

private:
    Ui::ManageTopic *ui;
};


#endif //EASYLEARNER_MANAGETOPIC_H
