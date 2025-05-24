/**
    * @file: contentaddition.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of ContentAddition class.
*/

#include "topic/creation/contentaddition.h"

void ContentAddition::setContentManager(const std::shared_ptr<ContentManager> &contentManager) {
    this->contentManager = contentManager;
}

void ContentAddition::addNewContent() {}
void ContentAddition::changeButtonState() const {}
void ContentAddition::goBack() {}