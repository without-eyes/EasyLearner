/**
*    @file: soundplayer.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of Database class.
*/

#include "utils/soundplayer.h"

SoundPlayer::SoundPlayer() {
    player = new QMediaPlayer(this);
    player->setVolume(20);
}

void SoundPlayer::playCorrectAnswerSound() {
    playSound("correct_answer.mp3");
}

void SoundPlayer::playBadAnswerSound() {
    playSound("bad_answer.mp3");
}

void SoundPlayer::playFinishedStudySound() {
    playSound("finished_study.mp3");
}

void SoundPlayer::playSound(const QString &soundName) const {
    player->setMedia(QUrl("qrc:/assets/sounds/" + soundName));
    player->play();
}
