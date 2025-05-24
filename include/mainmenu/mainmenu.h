/**
    * @file: mainmenu.h
    * @author: without eyes
    *
    * This file contains MainMenu class for "Main Menu" window.
*/

#ifndef EASYLEARNER_MAINMENU_H
#define EASYLEARNER_MAINMENU_H

#include <QWidget>
#include "core/pageindex.h"
#include "topic/base/contentmanager.h"

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

    void setContentManagerSignal(const std::shared_ptr<ContentManager>& contentManager);

public slots:
    void changeButtonState();

private:
    Ui::MainMenu *ui;
    std::shared_ptr<ContentManager> contentManager;

    void pickTopic();

    void createTopic();

    void deleteTopic();

    void showTableContent();
};


#endif //EASYLEARNER_MAINMENU_H
