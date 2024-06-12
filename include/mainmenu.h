//
// Created by without-eyes on 09.06.24.
//

#ifndef EASYLEARNER_MAINMENU_H
#define EASYLEARNER_MAINMENU_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QWidget {
Q_OBJECT



public:
    explicit MainMenu(QWidget *parent = nullptr);

    ~MainMenu() override;

    static void addTopicIntoList(const QString& topic);

public slots:
    void pickTopic();
    void createTopic();

private:
    Ui::MainMenu *ui;
    static QList<QString> topicList;

    void showTableContent();
};


#endif //EASYLEARNER_MAINMENU_H
