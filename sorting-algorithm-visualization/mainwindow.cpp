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

    sorting = new Sorting(this);

    ui->lyPainter->addWidget(&paint);
    ui->comboAlgos->addItems(sorting->getAlgorithms());
    ui->comboShuffle->addItems(sorting->getShuffles());
    ui->spinAnimSpeed->setValue(sorting->getDefaultAnimSpeed());
    ui->sliderAnimSpeed->setMaximum(sorting->getMaxAnimSpeed());
    ui->spinAnimSpeed->setMaximum(sorting->getMaxAnimSpeed());

    sorting->setAlgorithm(ui->comboAlgos->currentText());
    sorting->setShuffle(ui->comboShuffle->currentText());
    paint.setSizePolicy(QSizePolicy::Policy::Expanding,QSizePolicy::Policy::Expanding);
    paint.setPenWidth(5);
    paint.setSpacing(2);
    paint.update();

    // CONNECT
    connect(sorting, SIGNAL(changed(int*, int, int*, int)),
            this, SLOT(onNumbersChanged(int*, int, int*, int)));

    connect(sorting, SIGNAL(done()),
            this, SLOT(onSortingFinished()));

    connect(ui->comboAlgos, SIGNAL(currentTextChanged(QString)),
            this, SLOT(onChangeAlgorithm(QString)));

    connect(ui->comboShuffle, SIGNAL(currentTextChanged(QString)),
            this, SLOT(onChangeShuffle(QString)));

    sorting->createArray();
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
    sorting->setAlgorithm(algorithmName);
}

void MainWindow::onChangeShuffle(QString shuffleName) {
    sorting->setShuffle(shuffleName);
}

void MainWindow::on_buttonStart_pressed() {
    if (!isRunning) {
        isRunning = true;
        ui->buttonStart->setText("Stop");
        ui->buttonShuffle->setDisabled(true);

        sorting->setAnimSpeed(ui->spinAnimSpeed->value());

        paint.setAnim(true);
        paint.resetColor();

        timer.start();
        sorting->start();
    }
    else {
        isRunning = false;
        paint.setAnim(false);
        ui->buttonShuffle->setDisabled(false);
        paint.resetColor();
        ui->buttonStart->setText("Start");
        sorting->terminate();
    }
}

void MainWindow::on_buttonShuffle_pressed() {
    paint.resetColor();
    sorting->createArray();
}
