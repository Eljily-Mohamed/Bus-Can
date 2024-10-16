/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *DistanceBrightnessBox;
    QRadioButton *DistanceRadio;
    QRadioButton *BrightnessRadio;
    QLineEdit *DistanceBrightnessValue;
    QLabel *uniteLabel;
    QWidget *MotorBox;
    QLineEdit *MotorSpeed;
    QPushButton *setSpeed;
    QPushButton *OnOffButton;
    QWidget *threeDbox;
    QGroupBox *PhiValue;
    QLabel *phiLabel;
    QGroupBox *ThetaValue;
    QLabel *ThetaLabel;
    QGroupBox *PsiValue;
    QLabel *PsiLabel;
    QWidget *SensorValues;
    QGroupBox *windSpeedvalue;
    QLabel *windSpeedLabel;
    QGroupBox *TemperatureValue;
    QLabel *temperaturelabel;
    QGroupBox *HumidityValue;
    QLabel *HumidityLabel;
    QGroupBox *PressureValue;
    QLabel *PressureLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(802, 542);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(-1, -1, 791, 541));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        DistanceBrightnessBox = new QWidget(gridLayoutWidget);
        DistanceBrightnessBox->setObjectName("DistanceBrightnessBox");
        DistanceRadio = new QRadioButton(DistanceBrightnessBox);
        DistanceRadio->setObjectName("DistanceRadio");
        DistanceRadio->setGeometry(QRect(30, 70, 112, 26));
        DistanceRadio->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        DistanceRadio->setChecked(true);
        BrightnessRadio = new QRadioButton(DistanceBrightnessBox);
        BrightnessRadio->setObjectName("BrightnessRadio");
        BrightnessRadio->setGeometry(QRect(200, 70, 112, 26));
        BrightnessRadio->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        DistanceBrightnessValue = new QLineEdit(DistanceBrightnessBox);
        DistanceBrightnessValue->setObjectName("DistanceBrightnessValue");
        DistanceBrightnessValue->setGeometry(QRect(20, 20, 301, 28));
        uniteLabel = new QLabel(DistanceBrightnessBox);
        uniteLabel->setObjectName("uniteLabel");
        uniteLabel->setGeometry(QRect(330, 24, 57, 21));

        gridLayout->addWidget(DistanceBrightnessBox, 0, 1, 1, 1);

        MotorBox = new QWidget(gridLayoutWidget);
        MotorBox->setObjectName("MotorBox");
        MotorSpeed = new QLineEdit(MotorBox);
        MotorSpeed->setObjectName("MotorSpeed");
        MotorSpeed->setGeometry(QRect(10, 20, 261, 28));
        setSpeed = new QPushButton(MotorBox);
        setSpeed->setObjectName("setSpeed");
        setSpeed->setGeometry(QRect(290, 20, 83, 29));
        setSpeed->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        setSpeed->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        OnOffButton = new QPushButton(MotorBox);
        OnOffButton->setObjectName("OnOffButton");
        OnOffButton->setGeometry(QRect(150, 70, 121, 29));
        OnOffButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        OnOffButton->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 141, 0);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(MotorBox, 0, 0, 1, 1);

        threeDbox = new QWidget(gridLayoutWidget);
        threeDbox->setObjectName("threeDbox");
        PhiValue = new QGroupBox(threeDbox);
        PhiValue->setObjectName("PhiValue");
        PhiValue->setGeometry(QRect(420, 0, 341, 51));
        phiLabel = new QLabel(PhiValue);
        phiLabel->setObjectName("phiLabel");
        phiLabel->setGeometry(QRect(10, 20, 63, 20));
        ThetaValue = new QGroupBox(threeDbox);
        ThetaValue->setObjectName("ThetaValue");
        ThetaValue->setGeometry(QRect(420, 80, 341, 51));
        ThetaLabel = new QLabel(ThetaValue);
        ThetaLabel->setObjectName("ThetaLabel");
        ThetaLabel->setGeometry(QRect(10, 20, 63, 20));
        PsiValue = new QGroupBox(threeDbox);
        PsiValue->setObjectName("PsiValue");
        PsiValue->setGeometry(QRect(420, 160, 341, 51));
        PsiLabel = new QLabel(PsiValue);
        PsiLabel->setObjectName("PsiLabel");
        PsiLabel->setGeometry(QRect(10, 20, 63, 20));

        gridLayout->addWidget(threeDbox, 2, 0, 1, 2);

        SensorValues = new QWidget(gridLayoutWidget);
        SensorValues->setObjectName("SensorValues");
        windSpeedvalue = new QGroupBox(SensorValues);
        windSpeedvalue->setObjectName("windSpeedvalue");
        windSpeedvalue->setGeometry(QRect(10, 0, 341, 51));
        windSpeedLabel = new QLabel(windSpeedvalue);
        windSpeedLabel->setObjectName("windSpeedLabel");
        windSpeedLabel->setGeometry(QRect(10, 20, 63, 20));
        TemperatureValue = new QGroupBox(SensorValues);
        TemperatureValue->setObjectName("TemperatureValue");
        TemperatureValue->setGeometry(QRect(420, 0, 341, 51));
        temperaturelabel = new QLabel(TemperatureValue);
        temperaturelabel->setObjectName("temperaturelabel");
        temperaturelabel->setGeometry(QRect(10, 20, 63, 20));
        HumidityValue = new QGroupBox(SensorValues);
        HumidityValue->setObjectName("HumidityValue");
        HumidityValue->setGeometry(QRect(10, 60, 341, 51));
        HumidityLabel = new QLabel(HumidityValue);
        HumidityLabel->setObjectName("HumidityLabel");
        HumidityLabel->setGeometry(QRect(10, 20, 63, 20));
        PressureValue = new QGroupBox(SensorValues);
        PressureValue->setObjectName("PressureValue");
        PressureValue->setGeometry(QRect(420, 60, 341, 51));
        PressureLabel = new QLabel(PressureValue);
        PressureLabel->setObjectName("PressureLabel");
        PressureLabel->setGeometry(QRect(10, 20, 63, 20));

        gridLayout->addWidget(SensorValues, 1, 0, 1, 2);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 802, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        DistanceRadio->setText(QCoreApplication::translate("MainWindow", "Distance", nullptr));
        BrightnessRadio->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        DistanceBrightnessValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        uniteLabel->setText(QCoreApplication::translate("MainWindow", "cm", nullptr));
        MotorSpeed->setPlaceholderText(QCoreApplication::translate("MainWindow", "Motor Speed", nullptr));
        setSpeed->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        OnOffButton->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        PhiValue->setTitle(QCoreApplication::translate("MainWindow", "Phi (\316\246)", nullptr));
        phiLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ThetaValue->setTitle(QCoreApplication::translate("MainWindow", "Theta (\316\270)", nullptr));
        ThetaLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        PsiValue->setTitle(QCoreApplication::translate("MainWindow", "Psi (\316\250)", nullptr));
        PsiLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        windSpeedvalue->setTitle(QCoreApplication::translate("MainWindow", "WindSpeed (km/h)", nullptr));
        windSpeedLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        TemperatureValue->setTitle(QCoreApplication::translate("MainWindow", "Temperature (\302\260C)", nullptr));
        temperaturelabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        HumidityValue->setTitle(QCoreApplication::translate("MainWindow", "Humidity (%)", nullptr));
        HumidityLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        PressureValue->setTitle(QCoreApplication::translate("MainWindow", "Pressure (hPa)", nullptr));
        PressureLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
