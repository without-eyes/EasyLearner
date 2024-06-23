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

    static void addIntoDefinitionSet(const QString& term, const QString& definition);

    static std::map<QString, QString> getDefinitionSet();

    static void addIntoQuestionSet(const QString& question, const QString& answer);

    static std::map<QString, QString> getQuestionSet();

private slots:
    void startStudy();

    void addDefinition();

    void addQuestion();

    void showTopicContent();

    void goBack();

private:
    Ui::ManageTopic *ui;
    static std::map<QString, QString> definitionSet;
    static std::map<QString, QString> questionSet;
};


#endif //EASYLEARNER_MANAGETOPIC_H
