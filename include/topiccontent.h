#ifndef EASYLEARNER_TOPICCONTENT_H
#define EASYLEARNER_TOPICCONTENT_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class TopicContent; }
QT_END_NAMESPACE

class TopicContent : public QWidget {
Q_OBJECT

public:
    explicit TopicContent(QWidget *parent = nullptr);

    ~TopicContent() override;

    static void addIntoDefinitionSet(const QString& term, const QString& definition);

    static std::map<QString, QString> getDefinitionSet();

    static void addIntoQuestionSet(const QString& question, const QString& answer);

    static std::map<QString, QString> getQuestionSet();

public slots:
    void showDefinition();

    void showQuestionsAnswers();

    void goBack();

private:
    Ui::TopicContent *ui;
    static std::map<QString, QString> definitionSet;
    static std::map<QString, QString> questionSet;
};


#endif //EASYLEARNER_TOPICCONTENT_H
