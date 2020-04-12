#ifndef EMOJIKEYBOARD_H_
#define EMOJIKEYBOARD_H_
#include <QVBoxLayout>
#include <QWidget>

#define TABS                                    \
    X(Emoticons)                                \
    X(Characters)                               \
    X(Flags)                                    \
    X(Other)                                    \
    X(Invalid)

#define X(name) name,
enum class EmojiTab {
    TABS
};
#undef X

extern QString emojiTabName[];

class EmojiKeyboard : public QWidget {
private:
    QVBoxLayout layout;
public:
    EmojiKeyboard(EmojiTab tab);
};

#endif // EMOJIKEYBOARD_H_
