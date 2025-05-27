/**
    * @file: mainwindow.h
    * @author: without eyes
    *
    * This file contains MainWindow class that is main
    * window of EasyLearner.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "mainmenu/mainmenu.h"
#include "topic/study/studyquestions.h"

class MainWindow final : public QMainWindow {
public:
    MainWindow();

private:
    QStackedWidget* stackedWidget{};
    std::vector<QWidget*> widgets;
    std::array<QString, 11> windowNames;

    void addEveryWidgetToStack();

    void setWindowNameArray();

    void connectPageChangeSignals();

    void connectMainMenuSignals();

    void connectTopicManagementSignals();

    void connectTopicStudySignals();

    void connectOtherSignals();

    void connectSignalsToSlots();

    void configureMainWindow();

    void setAppStyle();

    void changePage(PageIndex index);
};



#endif //MAINWINDOW_H
