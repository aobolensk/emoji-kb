#ifndef EMOJIKEYBOARD_H_
#define EMOJIKEYBOARD_H_
#include <QVBoxLayout>
#include <QLabel>

class EmojiKeyboard : public QWidget {
private:
    QLabel label;
    QVBoxLayout layout;
public:
    EmojiKeyboard();
};

#endif // EMOJIKEYBOARD_H_
