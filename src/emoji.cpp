#include <QDebug>
#include "emoji.h"

Emoji::Emoji(const QString &emoji) {
    this->setText(emoji);
}

void Emoji::mousePressEvent(QMouseEvent* event) {
    qDebug() << this;
}
