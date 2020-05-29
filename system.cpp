#include "system.h"
#include <QPixmap>
#include <QDebug>
#include <QTimer>
#include <system.h>
#include <connectionpool.h>
#include <QLabel>
System::System(QWidget *parent,QString ID,QString Address)
{
    this->DD=ID;
    this->AA=Address;
    //设置背景
    QSize size(180,130);
    this->setFixedSize(size);
    QPixmap pix;
    pix.load(":/res/label.png");
    pix=pix.scaled(size );
    this->setStyleSheet("Device:{border:2px groove gray;border-radius:20px;padding:2px 4px;}");
    this->setPixmap(pix);
    QLabel *name =new QLabel(this);
    QLabel *addressLabel =new QLabel(this);
    name->setGeometry(0,70,100,25);
    addressLabel->setGeometry(0,100,100,25);
    addressLabel->setText(Address);
    //设置图片和标题
    QLabel *devp=new QLabel(this);
    devp->setGeometry(5,10,70,70);
    //如果不存在该设备

    if(ID.toInt()>4 )
    {
        devp->setPixmap(QPixmap(deviceImgs.at(0)).scaled(70,70));
        name->setText("协议出错设备");
        return;
    }
    devp->setPixmap(QPixmap(deviceImgs.at(ID.toInt())).scaled(70,70));
    name->setText(deviceName.at(ID.toInt()) );
    //设置开关状态
    QLabel *sw=new QLabel(this);
    sw->setGeometry(this->width()-40,5,35,20);
    QTimer *timer=new QTimer;
    timer->start(1000);
    connect(timer,QTimer::timeout,[=](){
        QSqlDatabase db = ConnectionPool::openConnection();
        QSqlQuery query(db);
        //更改在线按钮，如果不在线了就删掉
        query.exec("select * from onlist;");
        while (query.next()) {
            if(query.value("kind").toString() ==ID)
            {
                if(query.value("flag").toString()=="1")
                    sw->setPixmap(QPixmap(":/res/on.png").scaled(35,20));
                else
                    sw->setPixmap(QPixmap(":/res/off.png").scaled(35,20));
            }
            ConnectionPool::closeConnection(db);
        }
    });
}

void System::mousePressEvent(QMouseEvent *ev)
{
    qDebug()<<"鼠标按下";
    if(this->DD.toInt()<=4)
     emit devicePressed(DD,AA);

}

