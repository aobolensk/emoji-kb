#include <QApplication>
#include <QScrollArea>
#include "emojikeyboard.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QFont f = app.font();
    f.setPointSize(24);
    app.setFont(f);
    QScrollArea scroll;
    EmojiKeyboard e;
    scroll.setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll.setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll.setWidgetResizable(true);
    scroll.setWidget(&e);
    scroll.show();
    return app.exec();
}
