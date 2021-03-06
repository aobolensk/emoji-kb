#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "emojireader.h"

void EmojiReader::read(const QString &file_path, /*out*/ QVector <EmojiGroup> &emojis) {
    QFile file(file_path);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        in.setCodec("UTF-8");
        EmojiGroup g;
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.size() == 0) {
                continue;
            }
            if (line.startsWith("# group")) {
                if (g.name != "") {
                    emojis.push_back(g);
                }
                g.name = line.right(line.size() - 9);
                g.data.clear();
            } else if (!line.startsWith("#")) {
                int start = line.indexOf('#');
                if (start != -1) {
                    start += 2;
                    int fin = line.indexOf(' ', start);
                    int start2 = line.indexOf(' ', fin + 1) + 1;
                    g.data.push_back(new Emoji(line.mid(start, fin - start), line.mid(start2, line.size())));
                }
            }
        }
        emojis.push_back(g);
        file.close();
    }
}