#include <QDebug>
#include "emojikeyboard.h"
#include "emoji.h"

#define X(name) #name,
QString emojiTabName[] = {
    TABS
};
#undef X

EmojiKeyboard::EmojiKeyboard(EmojiTab tabs) :
    QWidget(nullptr) {
    QVector <Emoji*> emojis;
    switch (tabs) {
    case EmojiTab::Emoticons: {
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
    } break;
    case EmojiTab::Other: {
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
    } break;
    }
    const int ROW_COUNT = 16;
    for (int r = 0; r < (emojis.size() + ROW_COUNT - 1) / ROW_COUNT; ++r) {
        QHBoxLayout *row = new QHBoxLayout(nullptr);
        for (int i = r * ROW_COUNT; i < qMin(emojis.size(), (r + 1) * ROW_COUNT); ++i) {
            row->addWidget(emojis[i]);
        }
        this->layout.addLayout(row);
    }

    this->setLayout(&this->layout);
}
