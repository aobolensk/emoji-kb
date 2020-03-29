#ifndef EMOJIKEYBOARD_H_
#define EMOJIKEYBOARD_H_
#include <QVBoxLayout>
#include <QWidget>

class EmojiKeyboard : public QWidget {
private:
    QVBoxLayout layout;
public:
    EmojiKeyboard();
};

#endif // EMOJIKEYBOARD_H_
