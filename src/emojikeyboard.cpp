#include "emojikeyboard.h"
#include "emoji.h"

EmojiKeyboard::EmojiKeyboard() :
    QWidget(nullptr) {
    QString str = "";
    int index = 0;
    QVector <Emoji*> e;
    for(unsigned char i = 0x81; i < 0x8F; ++i) {
        char a[5] = {};
        snprintf(a, 5, "\xF0\x9F\x98%c", i);
        e.push_back(new Emoji(a));
        this->layout.addWidget(e.back());
    }
    this->label.setText(str);
    this->setLayout(&this->layout);
}