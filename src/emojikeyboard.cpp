#include <QDebug>
#include "emojikeyboard.h"
#include "emoji.h"

#define X(name) #name,
QString emojiTabName[] = {
    TABS
};
#undef X

EmojiKeyboard::EmojiKeyboard(EmojiTab tab) :
    QWidget(nullptr) {
    QVector <Emoji*> emojis;
    QVector <QString> alpha(26);
    for(uint8_t i = 0xA6, index = 0; i < 0xC0; ++i, ++index) {
        char a[5] = {};
        snprintf(a, 5, "\xF0\x9F\x87%c", i);
        alpha[index] = a;
    }
    switch (tab) {
    case EmojiTab::Emoticons: {
        for(uint8_t i = 0x81; i < 0xC0; ++i) {
            char a[5] = {};
            snprintf(a, 5, "\xF0\x9F\x98%c", i);
            emojis.push_back(new Emoji(a));
        }
        for(uint8_t i = 0x81; i < 0x90; ++i) {
            char a[5] = {};
            snprintf(a, 5, "\xF0\x9F\x99%c", i);
            emojis.push_back(new Emoji(a));
        }
        for(uint8_t i = 0x91; i < 0xB0; ++i) {
            char a[5] = {};
            snprintf(a, 5, "\xF0\x9F\xA4%c", i);
            emojis.push_back(new Emoji(a));
        }
        for(uint8_t i : std::initializer_list<uint8_t>({0xB0, 0xB3, 0xB4, 0xB5, 0xB6, 0xBA})) {
            char a[5] = {};
            snprintf(a, 5, "\xF0\x9F\xA5%c", i);
            emojis.push_back(new Emoji(a));
        }
    } break;
    case EmojiTab::Characters: {
        for(uint8_t i = 0xA6; i < 0xC0; ++i) {
            char a[5] = {};
            snprintf(a, 5, "\xF0\x9F\x87%c", i);
            emojis.push_back(new Emoji(a));
        }
        for(uint8_t i = 0x91; i < 0x9B; ++i) {
            char a[5] = {};
            snprintf(a, 5, "\xF0\x9F\x86%c", i);
            emojis.push_back(new Emoji(a));
        }
    } break;
    case EmojiTab::Other: {
        for(uint8_t i = 0x9A; i < 0x9B; ++i) {
            for(uint8_t j = 0x81; j < 0xC0; ++j) {
                char a[5] = {};
                snprintf(a, 5, "\xF0\x9F%c%c", i, j);
                emojis.push_back(new Emoji(a));
            }
        }
        for(uint8_t i = 0x91; i < 0xB0; ++i) {
            char a[5] = {};
            snprintf(a, 5, "\xF0\x9F\xA5%c", i);
            emojis.push_back(new Emoji(a));
        }
        for(uint8_t i = 0x8C; i < 0x8F; ++i) {
            for(uint8_t j = 0x81; j < 0xC0; ++j) {
                char a[5] = {};
                snprintf(a, 5, "\xF0\x9F%c%c", i, j);
                emojis.push_back(new Emoji(a));
            }
        }
    } break;
    case EmojiTab::Invalid: break;
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
