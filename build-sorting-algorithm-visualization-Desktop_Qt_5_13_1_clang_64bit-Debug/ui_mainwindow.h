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
    QComboBox *comboBoxPaintType;
    QPushButton *buttonShuffle;
    QComboBox *comboBoxShuffle;
    QComboBox *comboBoxAlgorithm;
    QPushButton *buttonStart;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinBoxAnimSpeed;
    QLabel *label;
    QHBoxLayout *mainPainter;
    QGridLayout *gridLayout_1;
    QGridLayout *gridLayout_2;
    QLabel *labelComparisons;
    QLabel *labelChanges;
    QLabel *labelTime;

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
        comboBoxPaintType = new QComboBox(centralWidget);
        comboBoxPaintType->setObjectName(QString::fromUtf8("comboBoxPaintType"));

        gridLayout->addWidget(comboBoxPaintType, 0, 9, 1, 1);

        buttonShuffle = new QPushButton(centralWidget);
        buttonShuffle->setObjectName(QString::fromUtf8("buttonShuffle"));
        sizePolicy.setHeightForWidth(buttonShuffle->sizePolicy().hasHeightForWidth());
        buttonShuffle->setSizePolicy(sizePolicy);

        gridLayout->addWidget(buttonShuffle, 0, 10, 1, 1);

        comboBoxShuffle = new QComboBox(centralWidget);
        comboBoxShuffle->setObjectName(QString::fromUtf8("comboBoxShuffle"));

        gridLayout->addWidget(comboBoxShuffle, 0, 5, 1, 1);

        comboBoxAlgorithm = new QComboBox(centralWidget);
        comboBoxAlgorithm->setObjectName(QString::fromUtf8("comboBoxAlgorithm"));
        sizePolicy.setHeightForWidth(comboBoxAlgorithm->sizePolicy().hasHeightForWidth());
        comboBoxAlgorithm->setSizePolicy(sizePolicy);
        comboBoxAlgorithm->setMinimumSize(QSize(180, 0));

        gridLayout->addWidget(comboBoxAlgorithm, 0, 7, 1, 1);

        buttonStart = new QPushButton(centralWidget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        sizePolicy.setHeightForWidth(buttonStart->sizePolicy().hasHeightForWidth());
        buttonStart->setSizePolicy(sizePolicy);
        buttonStart->setMinimumSize(QSize(100, 21));

        gridLayout->addWidget(buttonStart, 0, 11, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        spinBoxAnimSpeed = new QSpinBox(centralWidget);
        spinBoxAnimSpeed->setObjectName(QString::fromUtf8("spinBoxAnimSpeed"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBoxAnimSpeed->sizePolicy().hasHeightForWidth());
        spinBoxAnimSpeed->setSizePolicy(sizePolicy1);
        spinBoxAnimSpeed->setMinimumSize(QSize(80, 23));

        verticalLayout_2->addWidget(spinBoxAnimSpeed);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        mainPainter = new QHBoxLayout();
        mainPainter->setSpacing(6);
        mainPainter->setObjectName(QString::fromUtf8("mainPainter"));
        mainPainter->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout->addLayout(mainPainter);

        gridLayout_1 = new QGridLayout();
        gridLayout_1->setSpacing(6);
        gridLayout_1->setObjectName(QString::fromUtf8("gridLayout_1"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelComparisons = new QLabel(centralWidget);
        labelComparisons->setObjectName(QString::fromUtf8("labelComparisons"));

        gridLayout_2->addWidget(labelComparisons, 0, 2, 1, 1);

        labelChanges = new QLabel(centralWidget);
        labelChanges->setObjectName(QString::fromUtf8("labelChanges"));

        gridLayout_2->addWidget(labelChanges, 0, 3, 1, 1);

        labelTime = new QLabel(centralWidget);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));

        gridLayout_2->addWidget(labelTime, 0, 4, 1, 1);


        gridLayout_1->addLayout(gridLayout_2, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_1);

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
        labelComparisons->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelChanges->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelTime->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
