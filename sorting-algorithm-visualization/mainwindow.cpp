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
//    ui->sliderAnimSpeed->setMaximum(sThread->getAnimSpeedMax());
//    ui->spinAnimSpeed->setMaximum(sThread->getAnimSpeedMax());

    s->setAlgorithm(ui->comboAlgos->currentText());
    paint.setSizePolicy(QSizePolicy::Policy::Expanding,QSizePolicy::Policy::Expanding);
    paint.setPenWidth(5);
    paint.setSpacing(2);
    paint.update();

    // CONNECT
    connect(s, SIGNAL(numbersChanged(std::vector<int>, std::vector<int>)),
            this, SLOT(onNumbersChanged(std::vector<int>, std::vector<int>)));

    connect(s, SIGNAL(sortingFinished()),
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

void MainWindow::onNumbersChanged(std::vector<int> nums, std::vector<int> idx) {
    paint.setPaintData(nums, idx);
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
