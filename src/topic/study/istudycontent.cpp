/**
    * @file: istudycontent.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of IStudyContent class.
*/

#include "topic/study/istudycontent.h"

void IStudyContent::checkAnswer() {}
void IStudyContent::showNextTask() {}
void IStudyContent::changeButtonState() const {}
void IStudyContent::pickRandomTask() {}

bool IStudyContent::compareAnswers(QString correctAnswer, QString &userAnswer) {
    if (correctAnswer == userAnswer) {
        return true;
    }

    const int correctLen = correctAnswer.length();
    const int userLen = userAnswer.length();

    if (std::abs(correctLen - userLen) > 1) {
        return false;
    }

    int mistakesCount = 0;
    int i = 0, j = 0;
    while (i < correctLen && j < userLen) {
        if (correctAnswer[i] == userAnswer[j]) {
            i++;
            j++;
            continue;
        }

        mistakesCount++;
        if (mistakesCount > 1) {
            return false;
        }

        if (correctLen > userLen) {
            i++;
        } else if (userLen > correctLen) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    return true;
}