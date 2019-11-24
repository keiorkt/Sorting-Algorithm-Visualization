#ifndef SORTING_H
#define SORTING_H

#include <QObject>
#include <QThread>
#include <QMutex>

const int ANIM_SPEED_STEP = 100;
const int MAX_ANIM_DELAY = ANIM_SPEED_STEP * 100;
const int MAX_ANIM_SPEED =  100;
const int MAX_SIZE = 800;

const int DEFAULT_ANIM_SPEED = 99;
const int DEFAULT_SIZE= 142;

class Sorting : public QThread {
    Q_OBJECT

private:
    QObject* parent;
    QString algorithm;
    QStringList algorithms = {"Bubble Sort","Insertion Sort","Selection Sort","Quicksort","Cocktail Sort"};
    int size = DEFAULT_SIZE;
    int* arr;
    int animDelay = ANIM_SPEED_STEP;
    int numberMin = 10;
    int numberMax = 600;

    void shuffle(int arr[],int size);

    void swap(int arr[],int size,int i,int j);

public:
    explicit Sorting(QObject* parent = nullptr);
    QStringList getAlgorithms() {return algorithms;}

    void run() override;

    void setSize(int size) {this->size = size;}
    void setAnimSpeed(int speed) {this->animDelay = MAX_ANIM_DELAY - speed * ANIM_SPEED_STEP;}
    void setAlgorithm(QString option) {algorithm = option;}
    void createArray();
    int getDefaultSize() {return DEFAULT_SIZE;}
    int getDefaultAnimSpeed() {return DEFAULT_ANIM_SPEED;}

    void sort_bubble(int* arr,int size);
    void sort_insertion(int* arr,int size);
    void sort_selection(int* arr,int size);
    void sort_quick(int* arr,int size,int start,int end);
    void sort_cocktail(int* arr,int size);

    void coloring(int* arr,int size,int* colorindex);

signals:
    void changed(int* arr,int size,int* index);
    void done();
};

#endif // SORTING_H
