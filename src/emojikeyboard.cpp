#include <QDebug>
#include "emojikeyboard.h"
#include "emoji.h"

EmojiKeyboard::EmojiKeyboard(const EmojiGroup &emojis) :
    QWidget(nullptr) {

    const int ROW_COUNT = 25;
    for (int r = 0; r < (emojis.data.size() + ROW_COUNT - 1) / ROW_COUNT; ++r) {
        QHBoxLayout *row = new QHBoxLayout(nullptr);
        for (int i = r * ROW_COUNT; i < qMin(emojis.data.size(), (r + 1) * ROW_COUNT); ++i) {
            row->addWidget(new Emoji(emojis.data[i]));
        }
        this->layout.addLayout(row);
    }

    this->setLayout(&this->layout);
}
