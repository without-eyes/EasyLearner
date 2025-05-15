/**
    * @file: studycontent.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of StudyContent class.
*/

#include "topic/study/studycontent.h"

void StudyContent::checkAnswer() {}
void StudyContent::showNextTask() {}
void StudyContent::changeButtonState() const {}
void StudyContent::pickRandomTask() {}

bool StudyContent::compareAnswers(QString correctAnswer, QString &userAnswer) {
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