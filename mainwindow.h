#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QTimer>
#include <QWidget>
#include <QUdpSocket>
#include <QUrl>
#include <QVideoWidget>
#include <QMediaContent>
#include <QMediaRecorder>
#include <QMediaPlayer>
#include <qqml.h>



struct CanSatdata {
    double lat=41.102;
    double lon= 29.019;
    int packetnumber;
    double cansatstatus;
    double errorcode;
    double sendtime;
    double basinc1;
    double basinc2;
    double height1;
    double height2;
    double irtifafarki;
    double landingspeed;
    double temperature;
    double voltage;
    double gps1latitude;
    double gps1longitude;
    double gps1altitude;
    double pitch=100;
    double roll=100;
    double yaw=100;
    int teamno;

};
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void timerFunc();

    void readData();
    void writeData();
    void on_pushButton_toggled(bool checked);
    void playVideo();
    void playSound();
    void timerFunc1();


    void on_pushButton_2_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer2;
    QUdpSocket *socket;
    QUdpSocket *socket2;
    CanSatdata datas;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QMediaPlayer* sound;
    QMediaRecorder* recorder;
signals:
    void setCenter(QVariant, QVariant);
void eulerFunction(QVariant, QVariant, QVariant);

};


#endif // MAINWINDOW_H
