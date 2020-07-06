#include <QApplication>
#include <QScrollArea>
#include <QTabWidget>
#include "emojikeyboard.h"
#include "emojireader.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QFont f = app.font();
    f.setPointSize(18);
    app.setFont(f);
    QTabWidget tabs;
    QVector <EmojiGroup> emojis;
    EmojiReader::read("../emoji-test.txt", emojis);
    for (int tab = 0; tab < emojis.size(); ++tab) {
        EmojiKeyboard *e = new EmojiKeyboard(emojis[tab]);
        QScrollArea *scroll = new QScrollArea;
        scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll->setWidgetResizable(false);
        scroll->setWidget(e);
        tabs.addTab(scroll, emojis[tab].name);
    }
    tabs.show();
    return app.exec();
}
