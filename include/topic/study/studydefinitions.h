/**
    * @file: studydefinitions.h
    * @author: without eyes
    *
    * This file contains StudyDefinitions class for "Study Definitions" window.
*/

#ifndef EASYLEARNER_STUDYDEFINITIONS_H
#define EASYLEARNER_STUDYDEFINITIONS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class StudyDefinitions; }
QT_END_NAMESPACE

class StudyDefinitions final : public QWidget {
    Q_OBJECT

public:
    explicit StudyDefinitions(QWidget *parent = nullptr);

    ~StudyDefinitions() override;

    static void setDefinitionsMap(const std::map<QString, QString> &map);

public slots:
    void checkAnswer();

    void showNextDefinition();

    void changeButtonState() const;

private:
    void pickRandomDefinition();

    Ui::StudyDefinitions *ui;
    static std::map<QString, QString> definitionsMap;
    QString term;
    QString definition;
};

#endif // EASYLEARNER_STUDYDEFINITIONS_H
