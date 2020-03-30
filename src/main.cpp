#include <QApplication>
#include <QScrollArea>
#include <QTabWidget>
#include "emojikeyboard.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QFont f = app.font();
    f.setPointSize(18);
    app.setFont(f);
    QScrollArea scroll;
    EmojiKeyboard e;
    scroll.setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll.setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll.setWidgetResizable(true);
    scroll.setWidget(&e);
    QTabWidget tabs;
    tabs.addTab(&e, "Main tab");
    tabs.show();
    return app.exec();
}
