/**
    * @file: topiccontentmanagement.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicContentManagement class.
*/

#include "topic/content/topiccontentmanagement.h"

void TopicContentManagement::setContentManager(const std::shared_ptr<ContentManager> &contentManager) {
    this->contentManager = contentManager;
}

void TopicContentManagement::deleteContent() {}
void TopicContentManagement::goBack() {}
void TopicContentManagement::changeButtonState() const {}
void TopicContentManagement::showContentList() {}