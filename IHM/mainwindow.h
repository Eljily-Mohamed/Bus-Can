#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <socketcan_cpp.h>
#include <objectgl.h>
#include <QtOpenGL>
#include <QGraphicsView>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void openCANPort();
    void sendCANMessage();
    void receiveCANMessage();
    void handleAnemometerData(const scpp::CanFrame& fr);
    void handleLuxTempHumData(const scpp::CanFrame& fr);
    void handleAccelerometerData(const scpp::CanFrame& fr);  // Nouvelle fonction pour gérer l'accéléromètre
    void handleMotorData(const scpp::CanFrame& fr);          // Nouvelle fonction pour gérer le moteur
    void handleOtherSensorData(const scpp::CanFrame& fr);

    void sendOrder(int id);  // Envoi d'une commande avec ID et ordre optionnel
    void setupTimers();  // Initialisation des timers

    ~MainWindow();

private slots:
    void on_OnOffButton_clicked();
    void on_BrightnessRadio_clicked();
    void on_DistanceRadio_clicked();
    void on_setSpeed_clicked();
    void onTimer_Tick();    // Mise à jour générale des données (appelé par `generalTimer`)
    void onAccelTimer_Tick();  // Fonction pour gérer les demandes de l'accéléromètre
    void onRefresh_Tick();  // Fonction pour gérer les demandes des cartes ID_1 et ID_3

    void on_autoToggleButton_clicked();

private:
    scpp::SocketCan socket_can;
    QTimer *timer_tick;       // Timer principal (général)
    QTimer *accelTimer;       // Timer pour l'accéléromètre
    QTimer *refreshTimer;     // Timer pour les cartes ID_1 et ID_3


    ObjectOpenGL *Object_GL;
    Ui::MainWindow *ui;

    int sendTurn = 0;  // Variable pour alterner les envois de demandes dans onRefresh_Tick
};
#endif // MAINWINDOW_H
