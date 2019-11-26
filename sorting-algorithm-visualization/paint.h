#ifndef PAINT_H
#define PAINT_H

#include <QObject>
#include <QtWidgets>
#include <QMutex>
#include <QPainter>
#include <list>
#include <vector>


const QColor defaultLineColor = Qt::lightGray;
const QColor defaultBgColor = Qt::black;

class Paint : public QWidget {
    Q_OBJECT
public:
    explicit Paint(QWidget *parent = nullptr);
    void setLineColor(QColor color) { lineColor = color;}
    void setAnim(bool isAnim) { animate = isAnim;}
    void setPaintData(int*, int*, int, int);
    void setPenWidth(int w) { penWidth = w;}
    void setSpacing(int s) { spacing = s;}
    void resetColor() {lineColor = defaultLineColor;}

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void onNumberSizeChange(int size);

private:
    QPen pen;
    QBrush brush;
    QPalette palette;

    QColor lineColor {defaultLineColor};
    QColor backgroundColor {defaultBgColor};
    std::vector<QColor> colorList = {Qt::red, Qt::green, Qt::cyan, Qt::magenta, Qt::yellow, Qt::white};

    bool animate;
    int penWidth;
    int spacing;

    int* numbers;
    int* indices;
    int size;
    int idxSize;

    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    QMutex mutex;
};

#endif // PAINT_H
