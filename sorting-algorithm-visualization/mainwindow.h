#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QTime>
#include <vector>
#include <string>
#include "sorting.h"
#include "paint.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Sorting* s;
    Paint paint;
    QTime timer;
    bool isRunning {false};

public slots:
    void onNumbersChanged(int*, int, int*, int);
    void onChangeAlgorithm(QString);
    void onSortingFinished();
    void onNumberSizeChange(int);

private slots:
    void on_buttonStart_pressed();
    void on_buttonShuffle_pressed();

signals:
    void StartSorting();
};
#endif // MAINWINDOW_H
