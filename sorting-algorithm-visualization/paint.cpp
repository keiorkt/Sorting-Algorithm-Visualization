#include "paint.h"

Paint::Paint(QWidget *parent) : QWidget(parent) {
    palette.setColor(QPalette::Background, backgroundColor);
    setPalette(palette);
    setAutoFillBackground(true);
    animation = false;
    penWidth = 1;
    spacing = 0;
    setPen(QPen(lineColor, penWidth, Qt::PenStyle::SolidLine, Qt::PenCapStyle::SquareCap, Qt::PenJoinStyle::BevelJoin));
}

void Paint::setPaintData(int* n, int* idx, int size, int sizeIndices) {
    mutex.lock();

    this->numbers = n;
    this->indices = idx;
    this->size = size;
    this->sizeIndices = sizeIndices;

    mutex.unlock();
}

void Paint::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    int iColor{0};
    int space = (this->width()-(penWidth*(size-1)))/2;
    for (int i{0}; i < size; ++i) {
        pen.setColor(lineColor);
        pen.setWidth(penWidth);
        painter.setPen(pen);

        bool contain{false};
        for (int j{0}; j < sizeIndices; ++j) {
            if (indices[j] == i) {contain = true;}
        }

        if (animation && contain) {
            pen.setColor(colors[iColor]);
            painter.setPen(pen);
            ++iColor;
        }
        if (paintType == "Bar") {
            painter.drawLine((i)*penWidth+space, this->height(), (i)*penWidth+space, this->height() - numbers[i]);
        }
        else if (paintType == "Star") {
            painter.drawPoint((i)*penWidth+space, this->height() - numbers[i]);
        }
        else {
            painter.drawLine((i)*penWidth+space, this->height()-1, (i)*penWidth+space, this->height() - numbers[i]-1);
        }
    }
}
