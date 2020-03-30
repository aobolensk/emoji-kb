#include <QApplication>
#include <QScrollArea>
#include <QTabWidget>
#include "emojikeyboard.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QFont f = app.font();
    f.setPointSize(18);
    app.setFont(f);
    QTabWidget tabs;
    for (size_t tab = 0; tab != static_cast<int>(EmojiTab::Invalid); ++tab) {
        EmojiKeyboard *e = new EmojiKeyboard(static_cast<EmojiTab>(tab));
        QScrollArea *scroll = new QScrollArea;
        scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scroll->setWidgetResizable(true);
        scroll->setWidget(e);
        tabs.addTab(e, emojiTabName[tab]);
    }
    tabs.show();
    return app.exec();
}
