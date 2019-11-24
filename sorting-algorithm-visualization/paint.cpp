#include "paint.h"

Paint::Paint(QWidget *parent) : QWidget(parent) {
    palette.setColor(QPalette::Background, backgroundColor);
    setPalette(palette);
    setAutoFillBackground(true);
    animate = false;
    penWidth =5;
    spacing = 0;

    setPen(QPen(lineColor, penWidth, Qt::PenStyle::SolidLine, Qt::PenCapStyle::SquareCap, Qt::PenJoinStyle::BevelJoin));
}

void Paint::setPaintData(std::vector<int> n, std::vector<int> idx) {
    mutex.lock();

    numbers = n;
    indices = idx;

    mutex.unlock();
}

void Paint::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    int iColor{0};

    for (int i{0}; i < numbers.size(); ++i) {
        pen.setColor(lineColor);
        painter.setPen(pen);

        bool contain{false};
        for (int x : indices) {
            if (x == i) {
                contain = true;
            }
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
