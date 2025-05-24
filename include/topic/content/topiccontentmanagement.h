#ifndef TOPICCONTENTMANAGMENT_H
#define TOPICCONTENTMANAGMENT_H

#include <memory>
#include <QWidget>
#include "topic/base/contentmanager.h"

class TopicContentManagement : public QWidget {
Q_OBJECT
public:
    explicit TopicContentManagement(QWidget *parent = nullptr) : QWidget(parent) {}

public slots:
    virtual void setContentManager(const std::shared_ptr<ContentManager> &contentManager);
    virtual void deleteContent();
    virtual void goBack();
    virtual void changeButtonState() const;

protected:
    std::shared_ptr<ContentManager> contentManager;

    virtual void showContentList();
};

#endif //TOPICCONTENTMANAGMENT_H