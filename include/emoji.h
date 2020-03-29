#ifndef EMOJI_H_
#define EMOJI_H_
#include <QLabel>

class Emoji : public QLabel {
public:
    Emoji() = delete;
    Emoji(const QString &emoji);
    void mousePressEvent(QMouseEvent* event);
};

#endif // EMOJI_H_
