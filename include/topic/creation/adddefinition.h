#ifndef EASYLEARNER_ADDDEFINITION_H
#define EASYLEARNER_ADDDEFINITION_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class AddDefinition; }
QT_END_NAMESPACE

class AddDefinition final : public QWidget {
Q_OBJECT

public:
    explicit AddDefinition(QWidget *parent = nullptr);

    ~AddDefinition() override;

public slots:

    void addDefinition();

    void changeButtonState() const;

    void goBack();

private:
    Ui::AddDefinition *ui;
};


#endif //EASYLEARNER_ADDDEFINITION_H
