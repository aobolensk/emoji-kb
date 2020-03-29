#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

class Emoji {
private:
    QLabel text;
    
};

class EmojiKeyboard : public QWidget {
private:
    QLabel label;
    QHBoxLayout layout;
public:
    EmojiKeyboard(QWidget *parent) :
        QWidget(parent) {
        QString str = "";
        for(unsigned char i = 0x81; i < 0xBF; ++i) {
            if (!(i & 0x0F)) {
                str += '\n';
            }
            char a[100] = {};
            snprintf(a, 100, "\xF0\x9F\x98%c", i);
            str += a;
        }
        printf("%d\n", str.size());
        this->label.setText(str);
        this->layout.addWidget(&this->label);
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
