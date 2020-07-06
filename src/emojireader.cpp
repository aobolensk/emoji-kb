#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "emojireader.h"

void EmojiReader::read(const QString &file_path, /*out*/ QVector <EmojiGroup> &emojis) {
    QFile file(file_path);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        EmojiGroup g;
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.size() == 0) {
                continue;
            }
            if (line.startsWith("# group")) {
                if (g.name != "") {
                    emojis.push_back(g);
                    return;
                }
                g.name = line.right(line.size() - 9);
            } else if (!line.startsWith("#")) {
                int start = line.indexOf('#');
                if (start != -1) {
                    start += 2;
                    int fin = line.indexOf(' ', start);
                    g.data.push_back(line.mid(start, fin - start));
                }
            }
        }
        file.close();
    }
}