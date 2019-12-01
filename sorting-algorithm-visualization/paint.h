#ifndef PAINT_H
#define PAINT_H

#include <QObject>
#include <QtWidgets>
#include <QMutex>
#include <QPainter>
#include <list>
#include <vector>

const QColor defaultLineColor = Qt::lightGray;
const QColor defaultBackgroundColor = Qt::black;

class Paint : public QWidget {
    Q_OBJECT
public:
    explicit Paint(QWidget *parent = nullptr);
    void setLineColor(QColor color) { lineColor = color;}
    void setAnimation(bool anim) { animation = anim;}
    void setPaintData(int*, int*, int, int);
    void setPenWidth(int width) { penWidth = width;}
    void setSpacing(int space) { spacing = space;}
    void reset() {lineColor = defaultLineColor;}
    void setPaintType(QString option) {paintType = option;}
    QStringList getPaintTypes() {return paintTypes;}

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void onNumberOfSizeChange(int size);

private:
    QPalette palette;
    QBrush brush;
    QPen pen;
    QColor lineColor {defaultLineColor};
    QColor backgroundColor {defaultBackgroundColor};
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
};

#endif // PAINT_H
