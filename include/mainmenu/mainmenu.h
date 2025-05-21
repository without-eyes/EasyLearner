/**
    * @file: mainmenu.h
    * @author: without eyes
    *
    * This file contains MainMenu class for "Main Menu" window.
*/

#ifndef EASYLEARNER_MAINMENU_H
#define EASYLEARNER_MAINMENU_H

#include <QSqlTableModel>
#include <QWidget>
#include "core/pageindex.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu final : public QWidget {
Q_OBJECT


public:
    explicit MainMenu(QWidget *parent = nullptr);

    ~MainMenu() override;

    void addTopicIntoList(const QString &topic);

signals:
    void requestPageChange(PageIndex index);

    void setTopic(const QString &topic);

    void loadTopicContent();

public slots:
    void changeButtonState();

private slots:
    void pickTopic();

    void createTopic();

    void deleteTopic();

private:
    Ui::MainMenu *ui;
    static QList<QString> topicList;

    void showTableContent() const;

    static void loadTopicsFromModel(const QSqlTableModel* model);
};


#endif //EASYLEARNER_MAINMENU_H
