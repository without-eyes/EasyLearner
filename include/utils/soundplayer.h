/**
    * @file: soundplayer.h
    * @author: without eyes
    *
    * This file contains SoundPlayer class that plays sounds.
*/

#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QMediaPlayer>
#include <qobject.h>

class SoundPlayer final : public QObject {
public:
    SoundPlayer();

    void playCorrectAnswerSound();

    void playBadAnswerSound();

    void playFinishedStudySound();

private:
    QMediaPlayer* player;

    void playSound(const QString& soundName) const;

};

#endif //SOUNDPLAYER_H
