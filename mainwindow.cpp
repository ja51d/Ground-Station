#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFile>
#include <QVideoWidget>
#include <QMediaContent>
#include <QMediaRecorder>
#include <QMediaPlayer>

#include <QQuickItem>





void MainWindow::playVideo(){



    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile("/Users/Javid/desktop/jovo.mov"));
    player->setVolume(10);


    vw->setGeometry(0,410,430,300);
    vw->show();
    player->play();



}
void MainWindow::playSound(){



    sound= new QMediaPlayer(this);
    sound->setMedia(QUrl::fromLocalFile("direction..."));

    sound->play();

}

void MainWindow::readData()
{

    while (socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size());




        QDataStream stream(datagram);
        stream.setByteOrder(QDataStream::LittleEndian);
        stream >>datas.packetnumber>>datas.cansatstatus>>datas.errorcode>>datas.sendtime>>datas.basinc1>>datas.basinc2
            >>datas.height1>>datas.height2>>datas.irtifafarki>>datas.landingspeed>>datas.temperature>>datas.voltage
            >>datas.gps1latitude>>datas.gps1longitude >> datas.gps1altitude >>datas.pitch>>datas.roll>>datas.yaw>>datas.teamno;



    }

}
void MainWindow::writeData(){



    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setByteOrder(QDataStream::LittleEndian);
    int numba = 1;
    out<< numba;

    QHostAddress receiverAddress("127.0.0.1");

    socket2->writeDatagram(data,data.size(),receiverAddress, 5005);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/testqml.qml")));
    ui->quickWidget->show();
    ui->quickWidget_2->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget_2->show();
    auto obj = ui->quickWidget_2->rootObject();
    connect(this, SIGNAL(setCenter(QVariant,QVariant)), obj, SLOT(setCenter(QVariant,QVariant)));


    auto objj = ui->quickWidget->rootObject();
    connect(this, SIGNAL(eulerFunction(QVariant,QVariant,QVariant)), objj, SLOT(eulerFunction(QVariant,QVariant,QVariant)));



   playVideo();

    QPixmap pix("/");
    ui->label_2->setPixmap(pix);




    QCPScatterStyle myScatter;
    myScatter.setShape(QCPScatterStyle::ssDisc);
    myScatter.setPen(QPen(Qt::black));
    myScatter.setSize(2);

    QFont plotFont= font();
    plotFont.setPointSize(6);
    ui->listWidget->setStyleSheet("color: white");
ui->label->setStyleSheet("color: #0300DC;");

    ui->bas1->addGraph();

    ui->bas1->graph(0)->setScatterStyle(myScatter);
    ui->bas1->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->bas1->graph(0)->setPen(QPen(QColor(15,65,74)));


    ui->bas1->xAxis->setLabel("Packet Number");
    ui->bas1->xAxis->setLabelFont(plotFont);
    ui->bas1->xAxis->setTickLabelFont(plotFont);
    ui->bas1->yAxis->setLabel("Basınc");
        ui->bas1->yAxis->setLabelFont(plotFont);
    ui->bas1->yAxis->setTickLabelFont(plotFont);

    ui->bas2->addGraph();

    ui->bas2->graph(0)->setScatterStyle(myScatter);
    ui->bas2->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->bas2->graph(0)->setPen(QPen(QColor(30,30,30)));



    ui->bas2->xAxis->setLabel("Packet Number");
    ui->bas2->yAxis->setLabel("Basınc");
        ui->bas2->xAxis->setLabelFont(plotFont);
    ui->bas2->xAxis->setTickLabelFont(plotFont);
    ui->bas2->yAxis->setLabelFont(plotFont);
    ui->bas2->yAxis->setTickLabelFont(plotFont);

    ui->height1->addGraph();

    ui->height1->graph(0)->setScatterStyle(myScatter);
    ui->height1->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->height1->graph(0)->setPen(QPen(QColor(5,25,88)));



    ui->height1->xAxis->setLabel("Packet Number");
    ui->height1->yAxis->setLabel("Height");
    ui->height1->xAxis->setLabelFont(plotFont);
    ui->height1->xAxis->setTickLabelFont(plotFont);
    ui->height1->yAxis->setLabelFont(plotFont);
    ui->height1->yAxis->setTickLabelFont(plotFont);

    ui->height2->addGraph();

    ui->height2->graph(0)->setScatterStyle(myScatter);
    ui->height2->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->height2->graph(0)->setPen(QPen(QColor(5,25,88)));



    ui->height2->xAxis->setLabel("Packet Number");
    ui->height2->yAxis->setLabel("Height");
    ui->height2->xAxis->setLabelFont(plotFont);
    ui->height2->xAxis->setTickLabelFont(plotFont);
    ui->height2->yAxis->setLabelFont(plotFont);
    ui->height2->yAxis->setTickLabelFont(plotFont);


    ui->temp->addGraph();

    ui->temp->graph(0)->setScatterStyle(myScatter);
    ui->temp->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->temp->graph(0)->setPen(QPen(QColor(20,75,15)));



    ui->temp->xAxis->setLabel("Packet Number");
    ui->temp->yAxis->setLabel("Temperature");
    ui->temp->xAxis->setLabelFont(plotFont);
    ui->temp->xAxis->setTickLabelFont(plotFont);
    ui->temp->yAxis->setLabelFont(plotFont);
    ui->temp->yAxis->setTickLabelFont(plotFont);


    ui->lspeed->addGraph();

    ui->lspeed->graph(0)->setScatterStyle(myScatter);
    ui->lspeed->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->lspeed->graph(0)->setPen(QPen(QColor(30,20,30)));


    ui->lspeed->xAxis->setLabel("Packet Number");
    ui->lspeed->yAxis->setLabel("Landing Speed");
    ui->lspeed->xAxis->setLabelFont(plotFont);
    ui->lspeed->xAxis->setTickLabelFont(plotFont);
    ui->lspeed->yAxis->setLabelFont(plotFont);
    ui->lspeed->yAxis->setTickLabelFont(plotFont);




    timer = new QTimer(this);
    connect(timer, SIGNAL (timeout()),this,SLOT(timerFunc()));


    timer2 = new QTimer(this);
    connect(timer, SIGNAL (timeout()),this,SLOT(timerFunc1()));






    socket = new QUdpSocket(this);

    socket->bind(QHostAddress::LocalHost, 5006);


    socket2 = new QUdpSocket(this);

    socket2->bind(QHostAddress::LocalHost, 5005);



}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_toggled(bool checked)
{


    if(checked==true){

        ui->pushButton->setText("Stop");

        timer->start(1000);




    }

    else{


        ui->pushButton->setText("Start");

        timer->stop();

    }
}

void MainWindow::timerFunc(){
writeData();
readData();
 QString datab= QString::number(datas.packetnumber)+","+ QString::number(datas.cansatstatus)
                    +","+ QString::number(datas.errorcode) + ","+ QString::number(datas.sendtime) +","+
                    QString::number(datas.basinc1) + ","+ QString::number(datas.basinc2) + ","+ QString::number(datas.height1) +
                    ","+QString::number(datas.height2)+","+QString::number(datas.irtifafarki) +","+  QString::number(datas.landingspeed) +
                    ","+QString::number(datas.temperature) +","+  QString::number(datas.voltage) +","+
                    QString::number(datas.gps1latitude)  +","+QString::number(datas.gps1longitude)+ ","+QString::number(datas.gps1altitude)+
                    ","+QString::number(datas.pitch) + ","+QString::number(datas.roll)+","+ QString::number(datas.yaw)+ ","+QString::number(datas.teamno);
 ui->listWidget->addItem(datab);
 ui->listWidget_2->clear();
 ui->listWidget_2->addItem(QString::number(datas.irtifafarki));
 datas.lat+=0.01;
 datas.lon+=0.01;
 datas.roll+=10;
 datas.yaw+=10;
 datas.pitch+=10;
 emit setCenter(datas.lat, datas.lon);
emit eulerFunction(datas.roll, datas.yaw, datas.pitch);


    int  x=datas.packetnumber;
    double  y1=datas.basinc1;
    double  y2=datas.basinc2;
    double  y3=datas.height1;
    double  y4=datas.height2;
    double  y5=datas.temperature;
    double  y6=datas.landingspeed;
    ui->bas1->addGraph();
    ui->bas1->graph(0)->addData(x, y1);
    ui->bas1->rescaleAxes();
    ui->bas1->replot();
    ui->bas1->update();
    ui->bas2->addGraph();
    ui->bas2->graph(0)->addData(x, y2);
    ui->bas2->rescaleAxes();
    ui->bas2->replot();
    ui->bas2->update();
    ui->height1->addGraph();
    ui->height1->graph(0)->addData(x, y3);
    ui->height1->rescaleAxes();
    ui->height1->replot();
    ui->height1->update();
    ui->height2->addGraph();
    ui->height2->graph(0)->addData(x, y4);
    ui->height2->rescaleAxes();
    ui->height2->replot();
    ui->height2->update();
    ui->temp->addGraph();
    ui->temp->graph(0)->addData(x, y5);
    ui->temp->rescaleAxes();
    ui->temp->replot();
    ui->temp->update();
    ui->lspeed->addGraph();
    ui->lspeed->graph(0)->addData(x, y6);
    ui->lspeed->rescaleAxes();
    ui->lspeed->replot();
    ui->lspeed->update();
    if(datas.errorcode==0){
        playSound();
    }
    QFile File("/Users/javid/Desktop/cansat.csv");
    File.open(QIODevice::Append |QIODevice::WriteOnly);
    QTextStream stream(&File);
    stream<< datas.packetnumber<<datas.cansatstatus<<datas.errorcode<<datas.sendtime<<datas.basinc1<<datas.basinc2
           <<datas.height1<<datas.height2<<datas.irtifafarki<<datas.landingspeed<<datas.temperature<<datas.voltage
           <<datas.gps1latitude<<datas.gps1longitude << datas.gps1altitude <<datas.pitch<<datas.roll<<datas.yaw<<datas.teamno;
    File.close();
}

void MainWindow::timerFunc1(){


    readData();




}

void MainWindow::on_pushButton_2_toggled(bool checked)
{
    QString filename = QFileDialog::getOpenFileName(this,"new video");


    player->setMedia(QUrl::fromLocalFile(filename));
    player->play();
}

