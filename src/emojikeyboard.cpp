#include <QDebug>
#include <QPushButton>
#include <QScrollArea>
#include "emojikeyboard.h"
#include "emoji.h"

EmojiKeyboard::EmojiKeyboard() :
    QWidget(nullptr) {
    QString str = "";

    QVector <Emoji*> emojis;
    for(unsigned char i = 0x81; i < 0xC0; ++i) {
        char a[5] = {};
        snprintf(a, 5, "\xF0\x9F\x98%c", i);
        emojis.push_back(new Emoji(a));
    }
    for(unsigned char i = 0x81; i < 0x90; ++i) {
        char a[5] = {};
        snprintf(a, 5, "\xF0\x9F\x99%c", i);
        emojis.push_back(new Emoji(a));
    }
    for(unsigned char i = 0x9A; i < 0x9B; ++i) {
        for(unsigned char j = 0x81; j < 0xC0; ++j) {
            char a[5] = {};
            snprintf(a, 5, "\xF0\x9F%c%c", i, j);
            emojis.push_back(new Emoji(a));
        }
    }
    for(unsigned char i = 0x8C; i < 0x8F; ++i) {
        for(unsigned char j = 0x81; j < 0xC0; ++j) {
            char a[5] = {};
            snprintf(a, 5, "\xF0\x9F%c%c", i, j);
            emojis.push_back(new Emoji(a));
        }
    }
    for (int r = 0; r < (emojis.size() + 15) / 16; ++r) {
        QHBoxLayout *row = new QHBoxLayout(nullptr);
        for (int i = r * 16; i < qMin(emojis.size(), (r + 1) * 16); ++i) {
            row->addWidget(emojis[i]);
        }
        this->layout.addLayout(row);
    }

    this->label.setText(str);
    this->setLayout(&this->layout);
}
