#include "paint.h"

Paint::Paint(QWidget *parent) : QWidget(parent) {
    palette.setColor(QPalette::Background, backgroundColor);
    setPalette(palette);
    setAutoFillBackground(true);
    animate = false;
    penWidth = 5;
    spacing = 0;

    setPen(QPen(lineColor, penWidth, Qt::PenStyle::SolidLine, Qt::PenCapStyle::SquareCap, Qt::PenJoinStyle::BevelJoin));
}

void Paint::setPaintData(int* n, int* idx, int size, int idxSize) {
    mutex.lock();

    numbers = n;
    indices = idx;
    this->size = size;
    this->idxSize = idxSize;

    mutex.unlock();
}

void Paint::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    int iColor{0};

    for (int i{0}; i < size; ++i) {
        pen.setColor(lineColor);
        painter.setPen(pen);

        bool contain{false};
        for (int j{0}; j < idxSize; ++j) {
//            if (indices[j] == i) {contain = true;}
        }

        if (animate && contain) {
            pen.setColor(colorList[iColor]);
            painter.setPen(pen);
            ++iColor;
        }

        painter.drawLine((i-1)*penWidth, this->height(), (i-1)*penWidth, this->height() - numbers[i]);
    }
}

void Paint::onNumberSizeChange(int size) {
    penWidth = this->width() / size - spacing;
    this->update();
}

void Paint::setBrush(const QBrush &brush) {
    this->brush = brush;
}

void Paint::setPen(const QPen &pen) {
    this->pen = pen;
}
