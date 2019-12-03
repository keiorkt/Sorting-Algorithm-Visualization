#include "paint.h"

// set an initial value for some of the member variables
// initialize `sortingsound`
Paint::Paint(QWidget *parent) : QWidget(parent) {
    palette.setColor(QPalette::Background, backgroundColor);
    setPalette(palette);
    setAutoFillBackground(true);
    animate = false;
    penWidth = 1;
    spacing = 0;
    setPen(QPen(lineColor, penWidth, Qt::PenStyle::SolidLine, Qt::PenCapStyle::SquareCap, Qt::PenJoinStyle::BevelJoin));
    sortingsound = new QMediaPlayer;
    sortingsound->setMedia(QUrl("qrc:/sounds/sorting.mp3"));
}

// setter function for the important varialbes to draw elements.
void Paint::setPaintData(int* n, int* idx, int size, int sizeIndices) {
    this->numbers = n;
    this->colorIndices = idx;
    this->size = size;
    this->sizeColorIndices = sizeIndices;
}

// iterate through numbers array and draw elements according to colorIndices and the current setting of paintType
// dynamically calculates proper value of spacing for better visualization
// make a sorting sound at the end
void Paint::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    int colorIdx{0};
    int space = (this->width()-(penWidth*(size-1)))/2;
    for (int i{0}; i < size; ++i) {
        pen.setColor(lineColor);
        pen.setWidth(penWidth);
        painter.setPen(pen);

        bool contain{false};
        for (int j{0}; j < sizeColorIndices; ++j) {
            if (colorIndices[j] == i) {contain = true;}
        }

        if (animate && contain) {
            pen.setColor(colors[colorIdx]);
            painter.setPen(pen);
            ++colorIdx;
        }


        if (paintType == "Bar") {
            painter.drawLine((i)*penWidth+space, this->height(),
                             (i)*penWidth+space, this->height() - numbers[i]);
        }
        else if (paintType == "Star") {
            painter.drawPoint((i)*penWidth+space, this->height() - numbers[i]);
        }
        else {
            painter.drawLine((i)*penWidth+space, this->height()-1,
                             (i)*penWidth+space, this->height() - numbers[i]-1);
        }


        if (animate) {
            if (sortingsound->state() == QMediaPlayer::PlayingState) {
                sortingsound->setPosition(0);
            } else if (sortingsound->state() == QMediaPlayer::StoppedState) {
                sortingsound->play();
            }
        }
    }
}
