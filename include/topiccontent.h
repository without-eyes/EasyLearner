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

    static void addIntoDefinitionMap(const QString& term, const QString& definition);

    static std::map<QString, QString> getDefinitionMap();

    static void addIntoQuestionMap(const QString& question, const QString& answer);

    static std::map<QString, QString> getQuestionMap();

public slots:
    void showDefinition();

    void showQuestionsAnswers();

    void goBack();

private:
    Ui::TopicContent *ui;
    static std::map<QString, QString> definitionMap;
    static std::map<QString, QString> questionMap;
};


#endif //EASYLEARNER_TOPICCONTENT_H
