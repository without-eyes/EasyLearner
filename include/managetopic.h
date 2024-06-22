#ifndef EASYLEARNER_MANAGETOPIC_H
#define EASYLEARNER_MANAGETOPIC_H

#include <QWidget>
#include <QLabel>
#include <set>


QT_BEGIN_NAMESPACE
namespace Ui { class ManageTopic; }
QT_END_NAMESPACE

class ManageTopic : public QWidget {
Q_OBJECT

public:
    explicit ManageTopic(QWidget *parent = nullptr);

    ~ManageTopic() override;

    void setTopicName(const QString& topicName);

    void addIntoDefinitionSet(const QString& term, const QString& definition);

private slots:
    void startStudy();

    void addDefinition();

    void addQuestion();

    void showTopicContent();

    void goBack();

private:
    Ui::ManageTopic *ui;
    std::map<QString, QString> definitionSet;
};


#endif //EASYLEARNER_MANAGETOPIC_H
