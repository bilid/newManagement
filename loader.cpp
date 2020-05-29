#include "loader.h"
#include "ui_loader.h"
#include <mypushbutton.h>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <mainsence.h>
Loader::Loader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Loader)
{
    ui->setupUi(this);
    //配置主场景
    QSize size(320*1.3,588*1.3);
    setFixedSize(size);
    //设置图标
    setWindowIcon(QIcon(":/res/guangai.png"));
    //设置标题
    setWindowTitle("生态管理器");
    MyPushButton *startBtn=new MyPushButton(":/res/camping_72px_1206967_easyicon.net.png","",2.0 );
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);
    QObject::connect(startBtn,&MyPushButton::clicked,[=](){
        qDebug ()<<"点击开始按钮";
        startBtn->zoom1();
        startBtn->zoom2();
        QTimer::singleShot(300,this,[=](){
            qDebug()<<"ok";
            MainSence *mainSence=new MainSence();
            mainSence->show();
            this->hide();

        });
    });
}

Loader::~Loader()
{
    delete ui;
}

void Loader::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/1.JPG");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
