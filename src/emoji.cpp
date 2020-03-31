#include <QApplication>
#include <QClipboard>
#include <QDebug>
#include "emoji.h"

Emoji::Emoji(const QString &emoji) {
    this->setText(emoji);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->adjustSize();
    this->setFixedSize(this->size());
}

void Emoji::mousePressEvent(QMouseEvent* event) {
    (void) event;
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(this->text());
    qDebug() << this;
}
