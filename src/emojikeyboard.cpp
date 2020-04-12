#include <QDebug>
#include "emojikeyboard.h"
#include "emoji.h"

#define X(name) #name,
QString emojiTabName[] = {
    TABS
};
#undef X

// Source: https://en.wikipedia.org/wiki/ISO_3166-1
static QVector <const char *> flags_list = {
    "AD", "AE", "AF", "AG", "AI", "AL", "AM", "AO", "AQ", "AR", "AS", "AT", "AU", "AW", "AX", "AZ",
    "BA", "BB", "BD", "BE", "BF", "BG", "BH", "BI", "BJ", "BL", "BM", "BN", "BO", "BQ", "BQ", "BR",
    "BS", "BT", "BV", "BW", "BY", "BZ", "CA", "CC", "CD", "CF", "CG", "CH", "CI", "CK", "CL", "CM",
    "CN", "CO", "CR", "CU", "CV", "CW", "CX", "CY", "CZ", "DE", "DJ", "DK", "DM", "DO", "DZ", "EC",
    "EE", "EG", "EH", "ER", "ES", "ET", "FI", "FJ", "FK", "FM", "FO", "FR", "GA", "GB", "GD", "GE",
    "GF", "GG", "GH", "GI", "GL", "GM", "GN", "GP", "GQ", "GR", "GS", "GT", "GU", "GW", "GY", "HK",
    "HM", "HN", "HR", "HT", "HU", "ID", "IE", "IL", "IM", "IN", "IO", "IQ", "IR", "IS", "IT", "JE",
    "JM", "JO", "JP", "KE", "KG", "KH", "KI", "KM", "KN", "KP", "KR", "KW", "KY", "KZ", "LA", "LB",
    "LC", "LI", "LK", "LR", "LS", "LT", "LU", "LV", "LY", "MA", "MC", "MD", "ME", "MF", "MG", "MH",
    "MK", "ML", "MM", "MN", "MO", "MP", "MQ", "MR", "MS", "MT", "MU", "MV", "MW", "MX", "MY", "MZ",
    "NA", "NC", "NE", "NF", "NG", "NI", "NL", "NO", "NP", "NR", "NU", "NZ", "OM", "PA", "PE", "PF",
    "PG", "PH", "PK", "PL", "PM", "PN", "PR", "PS", "PT", "PW", "PY", "QA", "RE", "RO", "RS", "RU",
    "RW", "SA", "SB", "SC", "SD", "SE", "SG", "SH", "SI", "SJ", "SK", "SL", "SM", "SN", "SO", "SR",
    "SS", "ST", "SV", "SX", "SY", "SZ", "TC", "TD", "TF", "TG", "TH", "TJ", "TK", "TL", "TM", "TN",
    "TO", "TR", "TT", "TV", "TW", "TZ", "UA", "UG", "UM", "US", "UY", "UZ", "VA", "VC", "VE", "VG",
    "VI", "VN", "VU", "WF", "WS", "YE", "YT", "ZA", "ZM", "ZW"
};

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
    case EmojiTab::Flags: {
        for (int i = 0; i < flags_list.size(); ++i) {
            emojis.push_back(new Emoji(alpha[flags_list[i][0] - 'A'] + alpha[flags_list[i][1] - 'A']));
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
