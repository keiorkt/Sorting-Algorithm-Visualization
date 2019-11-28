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
    QString shuffleType;
    QStringList algorithms = {"Bubble Sort","Insertion Sort","Selection Sort","Quicksort","Cocktail Sort","Merge Sort","Heap Sort"};
    QStringList shuffles = {"Random", "Reverse", "Almost sorted"};
    int size = DEFAULT_SIZE;
    int* arr;
    int animDelay = ANIM_SPEED_STEP;
    int numberMin = 10;
    int numberMax = 600;

    void shuffle(int* arr,int size);

    void swap(int* arr,int size,int i,int j);
    void merge(int* arr,int size,int start,int end);
    void heapify(int* arr,int size,int heapsize,int i);

public:
    explicit Sorting(QObject* parent = nullptr);
    QStringList getAlgorithms() {return algorithms;}
    QStringList getShuffles() {return shuffles;}

    void run() override;

    void setSize(int size) {this->size = size;}
    void setAnimSpeed(int speed) {this->animDelay = MAX_ANIM_DELAY - speed * ANIM_SPEED_STEP;}
    void setAlgorithm(QString option) {algorithm = option;}
    void setShuffle(QString option) {shuffleType = option;}
    void createArray();
    int getDefaultSize() {return DEFAULT_SIZE;}
    int getDefaultAnimSpeed() {return DEFAULT_ANIM_SPEED;}
    int getMaxAnimSpeed() {return MAX_ANIM_SPEED;}

    void sort_bubble(int* arr,int size);
    void sort_insertion(int* arr,int size);
    void sort_selection(int* arr,int size);
    void sort_quick(int* arr,int size,int start,int end);
    void sort_cocktail(int* arr,int size);
    void sort_merge(int* arr,int size,int start,int end);
    void sort_heap(int* arr,int size);

    void coloring(int* arr,int size_arr,int* colorindex,int size_color);

signals:
    void changed(int* arr,int size_arr,int* index,int size_color);
    void done();
};

#endif // SORTING_H
