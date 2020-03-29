#include <QApplication>
#include "emojikeyboard.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QFont f = app.font();
    f.setPointSize(32);
    app.setFont(f);
    EmojiKeyboard e;
    e.show();
    return app.exec();
}
