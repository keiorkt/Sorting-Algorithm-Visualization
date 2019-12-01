#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->centralWidget()->setContentsMargins(0,0,0,0);
    setWindowTitle("Sorting Algorithm Visualization");

    ui->labelChanges->setText("Changes\n");
    ui->labelComparisons->setText("Comparisons\n");
    ui->labelTime->setText("Time\n00ms");

    sorting = new Sorting(this);

    ui->mainPainter->addWidget(&paint);
    ui->comboBoxAlgorithm->addItems(sorting->getAlgorithms());
    ui->comboBoxShuffle->addItems(sorting->getShuffles());
    ui->comboBoxPaintType->addItems(paint.getPaintTypes());
    ui->spinBoxAnimSpeed->setValue(sorting->getDefaultAnimSpeed());
    ui->spinBoxAnimSpeed->setMaximum(sorting->getMaxAnimSpeed());
    ui->SliderSpeed->setValue(sorting->getDefaultAnimSpeed());
    ui->SliderSpeed->setMaximum(sorting->getMaxAnimSpeed());
//    ui->sliderAnimSpeed->setMaximum(sorting->getMaxAnimSpeed());
//    ui->spinArraySize->setValue(sorting->getDefaultSize());
//    ui->spinArraySize->setMaximum(999);
    ui->comboBoxArraySize->addItems(sorting->getSizeList());
    ui->comboBoxArraySize->setCurrentText("32");

    sorting->setAlgorithm(ui->comboBoxAlgorithm->currentText());
    sorting->setShuffle(ui->comboBoxShuffle->currentText());
    paint.setPaintType(ui->comboBoxPaintType->currentText());
    paint.setSizePolicy(QSizePolicy::Policy::Expanding,QSizePolicy::Policy::Expanding);
    paint.setPenWidth(32);
    paint.setSpacing(0);
    paint.update();

    // CONNECT
    connect(sorting, SIGNAL(changed(int*, int, int*, int)),
            this, SLOT(onNumbersChanged(int*, int, int*, int)));

    connect(sorting, SIGNAL(done()),
            this, SLOT(onSortingFinished()));

    connect(ui->comboBoxAlgorithm, SIGNAL(currentTextChanged(QString)),
            this, SLOT(onChangeAlgorithm(QString)));

    connect(ui->comboBoxShuffle, SIGNAL(currentTextChanged(QString)),
            this, SLOT(onChangeShuffle(QString)));

    connect(ui->comboBoxPaintType, SIGNAL(currentTextChanged(QString)),
            this, SLOT(onChangePaintType(QString)));

    connect(ui->SliderSpeed, SIGNAL(valueChanged(int)),
            ui->spinBoxAnimSpeed,SLOT(setValue(int)));

    connect(ui->spinBoxAnimSpeed, SIGNAL(valueChanged(int)),
            ui->SliderSpeed, SLOT(setValue(int)));

    connect(ui->comboBoxArraySize, SIGNAL(currentTextChanged(QString)),
            this, SLOT(onNumberOfSizeChange(QString)));

    sorting->createArray();
}

void MainWindow::onNumberOfSizeChange(QString sizestring) {
    int newValue = sizestring.toInt();
    paint.setPenWidth(1024/newValue);
    paint.setLineColor(Qt::white);
    sorting->setSize(newValue);
    sorting->shuffle();
    sorting->createArray();
    paint.update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNumbersChanged(int* nums, int size, int* idx, int sizeIndices) {
    ui->labelComparisons->setText("Comparisons\n" + QString::number(sorting->get_num_comparisons()));
    ui->labelChanges->setText("Changes\n" + QString::number(sorting->get_num_changed()));
    paint.setPaintData(nums, idx, size, sizeIndices);
    paint.update();
}

void MainWindow::onSortingFinished() {
    ui->labelTime->setText("Time\n" + QString::number(timer.elapsed()) + "ms");
    paint.setAnimation(false);
    paint.setLineColor(Qt::yellow);
    paint.update();
    isSorting = false;
    ui->buttonShuffle->setDisabled(false);
    ui->buttonStart->setText("Start");
}


void MainWindow::onChangeAlgorithm(QString algorithmName) {
    sorting->setAlgorithm(algorithmName);
}

void MainWindow::onChangeShuffle(QString shuffleName) {
    sorting->setShuffle(shuffleName);
}

void MainWindow::onChangePaintType(QString paintTypeName) {
    paint.setPaintType(paintTypeName);
}

void MainWindow::on_buttonStart_pressed() {
    if (!isSorting) {
        isSorting = true;
        ui->buttonStart->setText("Stop");
        ui->buttonShuffle->setDisabled(true);
        sorting->setAnimSpeed(ui->spinBoxAnimSpeed->value());
        paint.setAnimation(true);
        paint.reset();
        timer.start();
        sorting->start();
    }
    else {
        isSorting = false;
        paint.setAnimation(false);
        ui->buttonShuffle->setDisabled(false);
        paint.reset();
        ui->buttonStart->setText("Start");
        sorting->terminate();
    }
}

void MainWindow::on_buttonShuffle_pressed() {
    paint.reset();
    sorting->createArray();
}
