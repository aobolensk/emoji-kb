#include <QApplication>
#include <QClipboard>
#include <QDebug>
#include "emoji.h"

Emoji::Emoji(const QString &emoji, const QString &tooltip) {
    this->setText(emoji);
    this->setToolTip(tooltip);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->adjustSize();
    this->setFixedSize(this->size());
    QFont font = this->font();
    font.setPointSize(18);
    this->setFont(font);
}

void Emoji::mousePressEvent(QMouseEvent* event) {
    (void) event;
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(this->text());
    qDebug() << this;
}
