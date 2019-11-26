/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lyPainter;
    QGridLayout *lyGrid;
    QLabel *labelAlg;
    QGridLayout *gridLayout_2;
    QSpinBox *spinAnimSpeed;
    QSlider *sliderAnimSpeed;
    QLabel *labelAnimSpeed;
    QGridLayout *gridLayout;
    QPushButton *buttonStart;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboAlgos;
    QLabel *labelExecTime;
    QPushButton *buttonShuffle;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(725, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(725, 700));
        MainWindow->setMaximumSize(QSize(725, 700));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lyPainter = new QHBoxLayout();
        lyPainter->setSpacing(6);
        lyPainter->setObjectName(QString::fromUtf8("lyPainter"));

        verticalLayout->addLayout(lyPainter);

        lyGrid = new QGridLayout();
        lyGrid->setSpacing(6);
        lyGrid->setObjectName(QString::fromUtf8("lyGrid"));
        labelAlg = new QLabel(centralWidget);
        labelAlg->setObjectName(QString::fromUtf8("labelAlg"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelAlg->sizePolicy().hasHeightForWidth());
        labelAlg->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(10);
        labelAlg->setFont(font);

        lyGrid->addWidget(labelAlg, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        spinAnimSpeed = new QSpinBox(centralWidget);
        spinAnimSpeed->setObjectName(QString::fromUtf8("spinAnimSpeed"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinAnimSpeed->sizePolicy().hasHeightForWidth());
        spinAnimSpeed->setSizePolicy(sizePolicy2);
        spinAnimSpeed->setMinimumSize(QSize(80, 23));

        gridLayout_2->addWidget(spinAnimSpeed, 0, 0, 1, 1);

        sliderAnimSpeed = new QSlider(centralWidget);
        sliderAnimSpeed->setObjectName(QString::fromUtf8("sliderAnimSpeed"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sliderAnimSpeed->sizePolicy().hasHeightForWidth());
        sliderAnimSpeed->setSizePolicy(sizePolicy3);
        sliderAnimSpeed->setMinimumSize(QSize(150, 0));
        sliderAnimSpeed->setFont(font);
        sliderAnimSpeed->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(sliderAnimSpeed, 0, 1, 1, 1);


        lyGrid->addLayout(gridLayout_2, 1, 1, 1, 1);

        labelAnimSpeed = new QLabel(centralWidget);
        labelAnimSpeed->setObjectName(QString::fromUtf8("labelAnimSpeed"));
        labelAnimSpeed->setFont(font);
        labelAnimSpeed->setAlignment(Qt::AlignCenter);

        lyGrid->addWidget(labelAnimSpeed, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonStart = new QPushButton(centralWidget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        sizePolicy.setHeightForWidth(buttonStart->sizePolicy().hasHeightForWidth());
        buttonStart->setSizePolicy(sizePolicy);
        buttonStart->setMinimumSize(QSize(100, 21));

        gridLayout->addWidget(buttonStart, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 6, 1, 1);

        comboAlgos = new QComboBox(centralWidget);
        comboAlgos->setObjectName(QString::fromUtf8("comboAlgos"));
        sizePolicy.setHeightForWidth(comboAlgos->sizePolicy().hasHeightForWidth());
        comboAlgos->setSizePolicy(sizePolicy);
        comboAlgos->setMinimumSize(QSize(180, 0));

        gridLayout->addWidget(comboAlgos, 0, 0, 1, 1);

        labelExecTime = new QLabel(centralWidget);
        labelExecTime->setObjectName(QString::fromUtf8("labelExecTime"));

        gridLayout->addWidget(labelExecTime, 0, 4, 1, 1);

        buttonShuffle = new QPushButton(centralWidget);
        buttonShuffle->setObjectName(QString::fromUtf8("buttonShuffle"));
        sizePolicy.setHeightForWidth(buttonShuffle->sizePolicy().hasHeightForWidth());
        buttonShuffle->setSizePolicy(sizePolicy);

        gridLayout->addWidget(buttonShuffle, 0, 3, 1, 1);


        lyGrid->addLayout(gridLayout, 0, 1, 1, 1);


        verticalLayout->addLayout(lyGrid);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(sliderAnimSpeed, SIGNAL(valueChanged(int)), spinAnimSpeed, SLOT(setValue(int)));
        QObject::connect(spinAnimSpeed, SIGNAL(valueChanged(int)), sliderAnimSpeed, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelAlg->setText(QCoreApplication::translate("MainWindow", "Algorithm", nullptr));
        labelAnimSpeed->setText(QCoreApplication::translate("MainWindow", "AnimSpeed", nullptr));
        buttonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        labelExecTime->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        buttonShuffle->setText(QCoreApplication::translate("MainWindow", "Shuffle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H