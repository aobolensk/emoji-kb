#include <QDebug>
#include "emoji.h"

Emoji::Emoji(const QString &emoji) {
    this->setText(emoji);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->adjustSize();
    this->setFixedSize(this->size());
}

void Emoji::mousePressEvent(QMouseEvent* event) {
    qDebug() << this;
}
