/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
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
    QWidget *SensorValues;
    QGroupBox *windSpeedvalue;
    QLabel *windSpeedLabel;
    QGroupBox *TemperatureValue;
    QLabel *temperaturelabel;
    QGroupBox *HumidityValue;
    QLabel *HumidityLabel;
    QGroupBox *PressureValue;
    QLabel *PressureLabel;
    QWidget *threeDbox;
    QWidget *MotorBox;
    QLineEdit *MotorSpeed;
    QPushButton *setSpeed;
    QPushButton *OnOffButton;
    QPushButton *autoToggleButton;
    QWidget *DistanceBrightnessBox;
    QRadioButton *DistanceRadio;
    QRadioButton *BrightnessRadio;
    QLineEdit *DistanceBrightnessValue;
    QLabel *uniteLabel;
    QWidget *widget;
    QGroupBox *PsiValue;
    QLabel *PsiLabel;
    QGroupBox *ThetaValue;
    QLabel *ThetaLabel;
    QGroupBox *phiValue;
    QLabel *phiLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 800);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(900, 800));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setMaximumSize(QSize(900, 800));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 881, 741));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(10, 0, 10, 0);
        SensorValues = new QWidget(gridLayoutWidget);
        SensorValues->setObjectName(QString::fromUtf8("SensorValues"));
        windSpeedvalue = new QGroupBox(SensorValues);
        windSpeedvalue->setObjectName(QString::fromUtf8("windSpeedvalue"));
        windSpeedvalue->setGeometry(QRect(10, 0, 341, 51));
        windSpeedvalue->setStyleSheet(QString::fromUtf8(""));
        windSpeedvalue->setFlat(false);
        windSpeedLabel = new QLabel(windSpeedvalue);
        windSpeedLabel->setObjectName(QString::fromUtf8("windSpeedLabel"));
        windSpeedLabel->setGeometry(QRect(10, 20, 63, 31));
        TemperatureValue = new QGroupBox(SensorValues);
        TemperatureValue->setObjectName(QString::fromUtf8("TemperatureValue"));
        TemperatureValue->setGeometry(QRect(460, 0, 341, 51));
        temperaturelabel = new QLabel(TemperatureValue);
        temperaturelabel->setObjectName(QString::fromUtf8("temperaturelabel"));
        temperaturelabel->setGeometry(QRect(10, 20, 63, 31));
        HumidityValue = new QGroupBox(SensorValues);
        HumidityValue->setObjectName(QString::fromUtf8("HumidityValue"));
        HumidityValue->setGeometry(QRect(10, 60, 341, 51));
        HumidityLabel = new QLabel(HumidityValue);
        HumidityLabel->setObjectName(QString::fromUtf8("HumidityLabel"));
        HumidityLabel->setGeometry(QRect(10, 20, 63, 31));
        PressureValue = new QGroupBox(SensorValues);
        PressureValue->setObjectName(QString::fromUtf8("PressureValue"));
        PressureValue->setGeometry(QRect(460, 60, 341, 51));
        PressureLabel = new QLabel(PressureValue);
        PressureLabel->setObjectName(QString::fromUtf8("PressureLabel"));
        PressureLabel->setGeometry(QRect(10, 20, 63, 31));

        gridLayout->addWidget(SensorValues, 1, 0, 1, 2);

        threeDbox = new QWidget(gridLayoutWidget);
        threeDbox->setObjectName(QString::fromUtf8("threeDbox"));
        threeDbox->setMaximumSize(QSize(900, 300));
        threeDbox->setFocusPolicy(Qt::WheelFocus);

        gridLayout->addWidget(threeDbox, 2, 0, 1, 2);

        MotorBox = new QWidget(gridLayoutWidget);
        MotorBox->setObjectName(QString::fromUtf8("MotorBox"));
        MotorSpeed = new QLineEdit(MotorBox);
        MotorSpeed->setObjectName(QString::fromUtf8("MotorSpeed"));
        MotorSpeed->setGeometry(QRect(10, 20, 261, 28));
        setSpeed = new QPushButton(MotorBox);
        setSpeed->setObjectName(QString::fromUtf8("setSpeed"));
        setSpeed->setGeometry(QRect(290, 20, 83, 29));
        setSpeed->setCursor(QCursor(Qt::PointingHandCursor));
        setSpeed->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        OnOffButton = new QPushButton(MotorBox);
        OnOffButton->setObjectName(QString::fromUtf8("OnOffButton"));
        OnOffButton->setGeometry(QRect(10, 60, 121, 29));
        OnOffButton->setCursor(QCursor(Qt::PointingHandCursor));
        OnOffButton->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 141, 0);\n"
"color: rgb(255, 255, 255);"));
        autoToggleButton = new QPushButton(MotorBox);
        autoToggleButton->setObjectName(QString::fromUtf8("autoToggleButton"));
        autoToggleButton->setGeometry(QRect(150, 60, 121, 29));
        autoToggleButton->setCursor(QCursor(Qt::PointingHandCursor));
        autoToggleButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 110, 255);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(MotorBox, 0, 0, 1, 1);

        DistanceBrightnessBox = new QWidget(gridLayoutWidget);
        DistanceBrightnessBox->setObjectName(QString::fromUtf8("DistanceBrightnessBox"));
        DistanceRadio = new QRadioButton(DistanceBrightnessBox);
        DistanceRadio->setObjectName(QString::fromUtf8("DistanceRadio"));
        DistanceRadio->setGeometry(QRect(60, 70, 112, 26));
        DistanceRadio->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        DistanceRadio->setChecked(true);
        BrightnessRadio = new QRadioButton(DistanceBrightnessBox);
        BrightnessRadio->setObjectName(QString::fromUtf8("BrightnessRadio"));
        BrightnessRadio->setGeometry(QRect(230, 70, 112, 26));
        BrightnessRadio->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        DistanceBrightnessValue = new QLineEdit(DistanceBrightnessBox);
        DistanceBrightnessValue->setObjectName(QString::fromUtf8("DistanceBrightnessValue"));
        DistanceBrightnessValue->setGeometry(QRect(50, 20, 301, 28));
        uniteLabel = new QLabel(DistanceBrightnessBox);
        uniteLabel->setObjectName(QString::fromUtf8("uniteLabel"));
        uniteLabel->setGeometry(QRect(360, 24, 57, 21));

        gridLayout->addWidget(DistanceBrightnessBox, 0, 1, 1, 1);

        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        PsiValue = new QGroupBox(widget);
        PsiValue->setObjectName(QString::fromUtf8("PsiValue"));
        PsiValue->setGeometry(QRect(560, 40, 261, 51));
        PsiLabel = new QLabel(PsiValue);
        PsiLabel->setObjectName(QString::fromUtf8("PsiLabel"));
        PsiLabel->setGeometry(QRect(10, 20, 63, 31));
        ThetaValue = new QGroupBox(widget);
        ThetaValue->setObjectName(QString::fromUtf8("ThetaValue"));
        ThetaValue->setGeometry(QRect(280, 40, 251, 51));
        ThetaLabel = new QLabel(ThetaValue);
        ThetaLabel->setObjectName(QString::fromUtf8("ThetaLabel"));
        ThetaLabel->setGeometry(QRect(10, 20, 63, 20));
        phiValue = new QGroupBox(widget);
        phiValue->setObjectName(QString::fromUtf8("phiValue"));
        phiValue->setGeometry(QRect(30, 40, 221, 51));
        phiLabel = new QLabel(phiValue);
        phiLabel->setObjectName(QString::fromUtf8("phiLabel"));
        phiLabel->setGeometry(QRect(10, 20, 63, 20));

        gridLayout->addWidget(widget, 3, 0, 1, 2);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 3);
        gridLayout->setRowStretch(3, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 900, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Bus CAN", nullptr));
        windSpeedvalue->setTitle(QCoreApplication::translate("MainWindow", "WindSpeed (km/h)", nullptr));
        windSpeedLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        TemperatureValue->setTitle(QCoreApplication::translate("MainWindow", "Temperature (\302\260C)", nullptr));
        temperaturelabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        HumidityValue->setTitle(QCoreApplication::translate("MainWindow", "Humidity (%)", nullptr));
        HumidityLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        PressureValue->setTitle(QCoreApplication::translate("MainWindow", "Pressure (hPa)", nullptr));
        PressureLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        MotorSpeed->setPlaceholderText(QCoreApplication::translate("MainWindow", "Motor Speed", nullptr));
        setSpeed->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        OnOffButton->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        autoToggleButton->setText(QCoreApplication::translate("MainWindow", "Auto", nullptr));
        DistanceRadio->setText(QCoreApplication::translate("MainWindow", "Distance", nullptr));
        BrightnessRadio->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        DistanceBrightnessValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        uniteLabel->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        PsiValue->setTitle(QCoreApplication::translate("MainWindow", "Psi (\316\250)", nullptr));
        PsiLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ThetaValue->setTitle(QCoreApplication::translate("MainWindow", "Theta (\316\270)", nullptr));
        ThetaLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        phiValue->setTitle(QCoreApplication::translate("MainWindow", "Phi", nullptr));
        phiLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
