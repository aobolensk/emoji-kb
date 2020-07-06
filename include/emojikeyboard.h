#ifndef EMOJIKEYBOARD_H_
#define EMOJIKEYBOARD_H_
#include <QVBoxLayout>
#include <QWidget>
#include "emojireader.h"

class EmojiKeyboard : public QWidget {
    QVBoxLayout layout;
public:
    EmojiKeyboard(const EmojiGroup &emojis);
};

#endif // EMOJIKEYBOARD_H_
