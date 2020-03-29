#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include "emoji.h"

class EmojiKeyboard : public QWidget {
private:
    QLabel label;
    QHBoxLayout layout;
public:
    EmojiKeyboard(QWidget *parent) :
        QWidget(parent) {
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
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QFont f = app.font();
    f.setPointSize(32);
    app.setFont(f);
    EmojiKeyboard e(nullptr);
    e.show();
    return app.exec();
}
