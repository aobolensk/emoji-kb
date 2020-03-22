#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

class EmojiKeyboard : public QWidget {
private:
    QLabel label;
    QHBoxLayout layout;
public:
    EmojiKeyboard(QWidget *parent) :
        QWidget(parent) {
        this->label.setText("Hello! 👐");
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
