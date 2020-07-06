#ifndef EMOJIREADER_H_
#define EMOJIREADER_H_
#include <QString>
#include <QVector>

struct EmojiGroup {
    QString name;
    QVector <QString> data;
};


struct EmojiReader {
    static void read(const QString &file_path, /*out*/ QVector <EmojiGroup> &emojis);
};

#endif // EMOJIREADER_H_
