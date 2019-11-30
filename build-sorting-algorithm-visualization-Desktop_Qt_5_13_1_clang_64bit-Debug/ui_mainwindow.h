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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QComboBox *comboPaintType;
    QPushButton *buttonShuffle;
    QComboBox *comboShuffle;
    QComboBox *comboAlgos;
    QPushButton *buttonStart;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinAnimSpeed;
    QLabel *label;
    QHBoxLayout *lyPainter;
    QGridLayout *lyGrid;
    QGridLayout *gridLayout_2;
    QLabel *labelComparison;
    QLabel *labelChanges;
    QLabel *labelExecTime;

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
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboPaintType = new QComboBox(centralWidget);
        comboPaintType->setObjectName(QString::fromUtf8("comboPaintType"));

        gridLayout->addWidget(comboPaintType, 0, 9, 1, 1);

        buttonShuffle = new QPushButton(centralWidget);
        buttonShuffle->setObjectName(QString::fromUtf8("buttonShuffle"));
        sizePolicy.setHeightForWidth(buttonShuffle->sizePolicy().hasHeightForWidth());
        buttonShuffle->setSizePolicy(sizePolicy);

        gridLayout->addWidget(buttonShuffle, 0, 10, 1, 1);

        comboShuffle = new QComboBox(centralWidget);
        comboShuffle->setObjectName(QString::fromUtf8("comboShuffle"));

        gridLayout->addWidget(comboShuffle, 0, 5, 1, 1);

        comboAlgos = new QComboBox(centralWidget);
        comboAlgos->setObjectName(QString::fromUtf8("comboAlgos"));
        sizePolicy.setHeightForWidth(comboAlgos->sizePolicy().hasHeightForWidth());
        comboAlgos->setSizePolicy(sizePolicy);
        comboAlgos->setMinimumSize(QSize(180, 0));

        gridLayout->addWidget(comboAlgos, 0, 7, 1, 1);

        buttonStart = new QPushButton(centralWidget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        sizePolicy.setHeightForWidth(buttonStart->sizePolicy().hasHeightForWidth());
        buttonStart->setSizePolicy(sizePolicy);
        buttonStart->setMinimumSize(QSize(100, 21));

        gridLayout->addWidget(buttonStart, 0, 11, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        spinAnimSpeed = new QSpinBox(centralWidget);
        spinAnimSpeed->setObjectName(QString::fromUtf8("spinAnimSpeed"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinAnimSpeed->sizePolicy().hasHeightForWidth());
        spinAnimSpeed->setSizePolicy(sizePolicy1);
        spinAnimSpeed->setMinimumSize(QSize(80, 23));

        verticalLayout_2->addWidget(spinAnimSpeed);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        lyPainter = new QHBoxLayout();
        lyPainter->setSpacing(6);
        lyPainter->setObjectName(QString::fromUtf8("lyPainter"));
        lyPainter->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout->addLayout(lyPainter);

        lyGrid = new QGridLayout();
        lyGrid->setSpacing(6);
        lyGrid->setObjectName(QString::fromUtf8("lyGrid"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelComparison = new QLabel(centralWidget);
        labelComparison->setObjectName(QString::fromUtf8("labelComparison"));

        gridLayout_2->addWidget(labelComparison, 0, 2, 1, 1);

        labelChanges = new QLabel(centralWidget);
        labelChanges->setObjectName(QString::fromUtf8("labelChanges"));

        gridLayout_2->addWidget(labelChanges, 0, 3, 1, 1);

        labelExecTime = new QLabel(centralWidget);
        labelExecTime->setObjectName(QString::fromUtf8("labelExecTime"));

        gridLayout_2->addWidget(labelExecTime, 0, 4, 1, 1);


        lyGrid->addLayout(gridLayout_2, 0, 0, 1, 1);


        verticalLayout->addLayout(lyGrid);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonShuffle->setText(QCoreApplication::translate("MainWindow", "Shuffle", nullptr));
        buttonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        labelComparison->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelChanges->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelExecTime->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
