#ifndef PAINT_H
#define PAINT_H

#include <QObject>
#include <QtWidgets>
#include <QMutex>
#include <QPainter>
#include <QMediaPlayer>
#include <list>
#include <vector>

const QColor DEFAULT_LINE_COLOR = Qt::lightGray;
const QColor DEFAULT_BACKGROUND_COLOR = Qt::black;
const int MAX_PEN_WIDTH = 100;

class Paint : public QWidget {
    Q_OBJECT
public:
    explicit Paint(QWidget *parent = nullptr);
    void setLineColor(QColor color) { lineColor = color;}
    void setAnimation(bool anim) { animation = anim;}
    void setPaintData(int*, int*, int, int);
    void setPenWidth(int width) { penWidth = width > MAX_PEN_WIDTH ? MAX_PEN_WIDTH : width;}
    void setSpacing(int space) { spacing = space;}
    void reset() {lineColor = DEFAULT_LINE_COLOR;}
    void setPaintType(QString option) {paintType = option;}
    QStringList getPaintTypes() {return paintTypes;}

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPalette palette;
    QBrush brush;
    QPen pen;
    QColor lineColor {DEFAULT_LINE_COLOR};
    QColor backgroundColor {DEFAULT_BACKGROUND_COLOR};
    QString paintType;
    QStringList paintTypes = {"Bar", "Star"};
    std::vector<QColor> colors = {Qt::red, Qt::green, Qt::cyan, Qt::magenta, Qt::yellow, Qt::white};

    bool animation;
    int penWidth;
    int spacing;

    int* numbers;
    int* indices;
    int size;
    int sizeIndices;

    void setPen(const QPen &pen){this->pen = pen;}
    void setBrush(const QBrush &brush){this->brush = brush;}
    QMutex mutex;
    QMediaPlayer* sortingsound;
};

#endif // PAINT_H
