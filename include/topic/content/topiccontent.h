#ifndef EASYLEARNER_TOPICCONTENT_H
#define EASYLEARNER_TOPICCONTENT_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class TopicContent; }
QT_END_NAMESPACE

class TopicContent final : public QWidget {
Q_OBJECT

public:
    explicit TopicContent(QWidget *parent = nullptr);

    ~TopicContent() override;

public slots:

    void showDefinition();

    void showQuestionsAnswers();

    void goBack();

private:
    Ui::TopicContent *ui;
};


#endif //EASYLEARNER_TOPICCONTENT_H
