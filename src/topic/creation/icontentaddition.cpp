/**
    * @file: icontentaddition.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of IContentAddition class.
*/

#include "topic/creation/icontentaddition.h"

void IContentAddition::setContentManager(const std::shared_ptr<ContentManager> &contentManager) {
    this->contentManager = contentManager;
}

void IContentAddition::addNewContent() {}
void IContentAddition::changeButtonState() const {}
void IContentAddition::goBack() {}