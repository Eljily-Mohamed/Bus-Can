#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Object_GL = new ObjectOpenGL();
    Object_GL->setObjectName(QString::fromUtf8("ObjectOpenGL"));
    Object_GL->setGeometry(QRect(0, 0, this->width(), this->width()));

    ui->gridLayout->addWidget(Object_GL, 2, 0, 1, 2);

    openCANPort();
    setupTimers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OnOffButton_clicked()
{
    scpp::CanFrame frame_to_write;
    frame_to_write.id = 0x03;
    frame_to_write.len = 1;
    if(ui->OnOffButton->text() == "ON")
    {
        ui->OnOffButton->setText("OFF");
        ui->OnOffButton->setStyleSheet("background-color: red");
    }
    else
    {
        ui->OnOffButton->setText("ON");
        ui->OnOffButton->setStyleSheet("background-color: green");
    }
    frame_to_write.data[0] = 0x10; // Data for OFF/ON state
    socket_can.write(frame_to_write);
}


void MainWindow::on_DistanceRadio_clicked()
{
    scpp::CanFrame frame_to_write;
    if(ui->DistanceRadio->isChecked())
    {
        ui->uniteLabel->setText("mm");
        ui->DistanceBrightnessValue->setText("0");
        frame_to_write.id = 0x01;
        frame_to_write.len = 1;
        frame_to_write.data[0] = 0x20;
    }
    else
    {
        ui->uniteLabel->setText("Lux");
        ui->DistanceBrightnessValue->setText("0");
        frame_to_write.id = 0x01;
        frame_to_write.len = 1;
        frame_to_write.data[0] = 0x10;
    }
    socket_can.write(frame_to_write);
}

void MainWindow::on_BrightnessRadio_clicked()
{
    scpp::CanFrame frame_to_write;
    if(ui->DistanceRadio->isChecked())
    {
        ui->uniteLabel->setText("mm");
        ui->DistanceBrightnessValue->setText("0");
        frame_to_write.id = 0x01;
        frame_to_write.len = 1;
        frame_to_write.data[0] = 0x20;
    }
    else
    {
        ui->uniteLabel->setText("Lux");
        ui->DistanceBrightnessValue->setText("0");
        frame_to_write.id = 0x01;
        frame_to_write.len = 1;
        frame_to_write.data[0] = 0x10;
    }
    socket_can.write(frame_to_write);
}

//OpenCAN port

void MainWindow::openCANPort()
{

   if (socket_can.open("can0") == scpp::STATUS_OK)
   {
        printf("can socket opened");
   }
   else
   {
       printf("Cannot open can socket!");
   }

}

//send button


void MainWindow::on_setSpeed_clicked()
{
    scpp::CanFrame frame_to_write;

    frame_to_write.id = 0x3; 
    frame_to_write.len = 2;
    int motorSpeed = ui->MotorSpeed->text().toInt();
    if(motorSpeed >= 0 && motorSpeed <= 200)
    {
        frame_to_write.data[0] = 0x20;  
        frame_to_write.data[1] = static_cast<uint8_t>(motorSpeed); 
    }
    else
    {
        frame_to_write.data[0] = 0;  
        frame_to_write.data[1] = 0;
    }
    // Send CAN frame
    socket_can.write(frame_to_write);
    std::cout << "Speed (hex) = 0x" << std::hex << motorSpeed << std::endl;
}


void MainWindow::handleAnemometerData(const scpp::CanFrame& fr)
{
    uint8_t Spw = (fr.data[0]);
    ui->windSpeedLabel->setText(QString::number(Spw));
}

void MainWindow::handleLuxTempHumData(const scpp::CanFrame& fr)
{
    // Récupération de la valeur de luminosité (3 octets : octets [0], [1], [2])
    uint32_t lux = (fr.data[2] << 16) | (fr.data[1] << 8) | fr.data[0];
    ui->DistanceBrightnessValue->setText(QString::number(lux));

    // Récupération de la pression (2 octets : octets [3], [4])
    uint16_t Pa = (fr.data[4] << 8) | fr.data[3];
    float pressure = Pa / 10.0f;  // Diviser par 10 pour revenir en hPa
    ui->PressureLabel->setText(QString::number(pressure, 'f', 1));

    // Récupération de la température (2 octets : octets [5], [6])
    uint16_t temp = (fr.data[6] << 8) | fr.data[5];
    float temperature = temp / 100.0f;  // Diviser par 100 pour avoir les degrés Celsius (°C)
    ui->temperaturelabel->setText(QString::number(temperature, 'f', 2));

    // Récupération de l'humidité (1 octet : octet [7])
    uint8_t hum = fr.data[7];
    float humidity = hum; 
    ui->HumidityLabel->setText(QString::number(humidity, 'f', 0));
}



void MainWindow::handleOtherSensorData(const scpp::CanFrame& fr)
{
    if (fr.id == 0x57)
    {
        int16_t phi =  (fr.data[1] << 8) | fr.data[0];       
        int16_t theta = (fr.data[3] << 8) | fr.data[2];
        int16_t psi = (fr.data[5] << 8) | fr.data[4];

        float phi_deg = static_cast<float> (phi) / 100.0f;
        float theta_deg = static_cast<float>(theta) / 100.0f;
        float psi_deg = static_cast<float>(psi) / 100.0f;

        phi_deg = phi_deg * (180.0f / 3.14f);
        theta_deg = theta_deg * (180.0f/ 3.14f);    
        psi_deg = psi_deg * (180.0f / 3.14f);    


        // Affichage dans les labels UI
        ui->phiLabel->setText(QString::number(phi_deg, 'f', 2));      
        ui->ThetaLabel->setText(QString::number(theta_deg, 'f', 2));
        ui->PsiLabel->setText(QString::number(psi_deg, 'f', 2));

        // Mise à jour des angles pour l'objet OpenGL
        Object_GL->SetXRotation((-phi_deg)*16);
        Object_GL->SetYRotation((theta_deg)*16);
        Object_GL->SetZRotation((-psi_deg)*16);
        //Object_GL->setAngles(-phi_deg,theta_deg,psi_deg);
        Object_GL->updateGL();
    }
}

/////////

void MainWindow::receiveCANMessage()
{
    scpp::CanFrame fr;

    if (socket_can.read(fr) == scpp::STATUS_OK)
    {
        if (fr.id == 0x55)
        {
            handleAnemometerData(fr);
        }
        else if (fr.id == 0x56)
        {
            handleLuxTempHumData(fr);
        }
        else
        {
            handleOtherSensorData(fr);
        }
    }
}


void MainWindow::onTimer_Tick()
{
    receiveCANMessage();
    //Object_GL->updateGL();
}

void MainWindow::onRefresh_Tick()
{
    // Timer dédié à l'envoi périodique de demandes CAN
    switch (sendTurn) {
    case 0:
        sendOrder(0x01);  // Demande pour l'anémomètre (ID 3)
        break;
    case 1:
        sendOrder(0x03);  // Demande pour la carte ID_1
        break;
    default:
        break;
    }
    sendTurn = (sendTurn + 1) % 2;
}

void MainWindow::onAccelTimer_Tick()
{
    // Timer dédié à l'envoi des demandes de l'accéléromètre uniquement
    sendOrder(0x02);  // ID pour l'accéléromètre id 0x02
}

void MainWindow::sendOrder(int id) {
    scpp::CanFrame frame_to_write;
    frame_to_write.id   = id;
    frame_to_write.len  = 1;  
    frame_to_write.data[0] = id;
    socket_can.write(frame_to_write);
}

void MainWindow::setupTimers()
{
    timer_tick = new QTimer(this);  // Timer principal pour la mise à jour générale
    connect(timer_tick, &QTimer::timeout, this, &MainWindow::onTimer_Tick);
    timer_tick->start(10); 

    // Création d'un timer pour les demandes spécifiques à l'accéléromètre
    accelTimer = new QTimer(this);
    connect(accelTimer, &QTimer::timeout, this, &MainWindow::onAccelTimer_Tick);
    accelTimer->start(180);  

    // Timer pour envoyer des requêtes aux cartes ID_1 et ID_3
    refreshTimer = new QTimer(this);
    connect(refreshTimer, &QTimer::timeout, this, &MainWindow::onRefresh_Tick);
    refreshTimer->start(50); 
}


void MainWindow::on_autoToggleButton_clicked(){
    scpp::CanFrame frame_to_write;
    if(ui->autoToggleButton->text()=="Auto"){
        ui->autoToggleButton->setText("Manual");
    }else {
        ui->autoToggleButton->setText("Auto");
    }
    frame_to_write.id = 0x3; 
    frame_to_write.len = 1;
    frame_to_write.data[0] = 0x30; 
    frame_to_write.len  = 8;  
    for (int i = 1; i < 8; i++) {
        frame_to_write.data[i] = 0;
    }
    socket_can.write(frame_to_write); 
    // Send CAN frame
    //std::cout << "mode auto active" << std::endl;
}
