/**
    * @file: itopiccontentmanagement.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of ITopicContentManagement class.
*/

#include "topic/content/itopiccontentmanagement.h"

void ITopicContentManagement::setContentManager(const std::shared_ptr<ContentManager> &contentManager) {
    this->contentManager = contentManager;
}

void ITopicContentManagement::deleteContent() {}
void ITopicContentManagement::goBack() {}
void ITopicContentManagement::changeButtonState() const {}
void ITopicContentManagement::showContentList() {}