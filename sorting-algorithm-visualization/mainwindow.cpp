#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->centralWidget()->setContentsMargins(0,0,0,0);
    setWindowTitle("Sorting Algorithm Visualization");

    ui->labelExecTime->setText("Execution time: 00ms  ");

    s = new Sorting(this);

    ui->lyPainter->addWidget(&paint);
    ui->comboAlgos->addItems(s->getAlgorithms());
    ui->spinAnimSpeed->setValue(s->getDefaultAnimSpeed());
    ui->sliderAnimSpeed->setMaximum(s->getMaxAnimSpeed());
    ui->spinAnimSpeed->setMaximum(s->getMaxAnimSpeed());

    s->setAlgorithm(ui->comboAlgos->currentText());
    paint.setSizePolicy(QSizePolicy::Policy::Expanding,QSizePolicy::Policy::Expanding);
    paint.setPenWidth(5);
    paint.setSpacing(2);
    paint.update();

    // CONNECT
    connect(s, SIGNAL(changed(int*, int, int*, int)),
            this, SLOT(onNumbersChanged(int*, int, int*, int)));

    connect(s, SIGNAL(done()),
            this, SLOT(onSortingFinished()));

    connect(ui->comboAlgos, SIGNAL(currentTextChanged(QString)),
            this, SLOT(onChangeAlgorithm(QString)));

    s->createArray();
}

void MainWindow::onNumberSizeChange(int newValue) {
    paint.setPenWidth(this->width() / newValue);
    paint.update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNumbersChanged(int* nums, int size, int* idx, int idxSize) {
    paint.setPaintData(nums, idx, size, idxSize);
    paint.update();
}

void MainWindow::onSortingFinished() {
    ui->labelExecTime->setText(QString::fromStdString("Execution time: "+ std::to_string(timer.elapsed()) +" ms   "));
    paint.setAnim(false);
    paint.setLineColor(Qt::green);
    paint.update();
    isRunning = false;
    ui->buttonShuffle->setDisabled(false);
    ui->buttonStart->setText("Start");
}


void MainWindow::onChangeAlgorithm(QString algorithmName) {
    s->setAlgorithm(algorithmName);
}

void MainWindow::on_buttonStart_pressed() {
    if (!isRunning) {
        isRunning = true;
        ui->buttonStart->setText("Stop");
        ui->buttonShuffle->setDisabled(true);

        s->setAnimSpeed(ui->spinAnimSpeed->value());

        paint.setAnim(true);
        paint.resetColor();

        timer.start();
        s->start();
    }
    else {
        isRunning = false;
        paint.setAnim(false);
        ui->buttonShuffle->setDisabled(false);
        paint.resetColor();
        ui->buttonStart->setText("Start");
        s->terminate();
    }
}

void MainWindow::on_buttonShuffle_pressed() {
    paint.resetColor();
    s->createArray();
}
