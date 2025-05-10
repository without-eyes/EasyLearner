#ifndef EASYLEARNER_TOPICDEFINITIONS_H
#define EASYLEARNER_TOPICDEFINITIONS_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class TopicDefinitions; }
QT_END_NAMESPACE

class TopicDefinitions : public QWidget {
Q_OBJECT

public slots:

    void deleteDefinition() const;

    void goBack();

    void changeButtonState() const;

public:
    explicit TopicDefinitions(QWidget *parent = nullptr);

    ~TopicDefinitions() override;

private:
    Ui::TopicDefinitions *ui;

    void showDefinitionList();
};


#endif