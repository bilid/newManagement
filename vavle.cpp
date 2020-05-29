#include "vavle.h"
#include <QPixmap>
#include <connectionpool.h>
#include <QTimer>
#include <vavlepage.h>
Vavle::Vavle(QWidget *parent ,QString kindIDAddress)
{

    qDebug()<<kindIDAddress;

    this->kind=QString(kindIDAddress).section(",",0,0);
    this->ID=QString(kindIDAddress).section(",",1,1);
    this->address=QString(kindIDAddress).section(",",2,2);

    QSize size(180,160);
    this->setFixedSize(size);
    //设定组件背景
    //设置不规则图片样式 border-radius: 11px;
    this->setStyleSheet("Vavle:{border:2px groove gray;border-radius:20px;padding:2px 4px;}");
    this->setPixmap(QPixmap(":/res/label12.png").scaled(size));
    QLabel *name =new QLabel(this);
    name->setGeometry(0,80,180,80);
    name->setFont(QFont("Timers",11, QFont::Bold));
    name->setText(VavleName[kindIDAddress.section(",",0,0).toInt()][kindIDAddress.section(",",1,1).toInt()] );
    qDebug()<<VavleName[kindIDAddress.section(",",0,0).toInt()][kindIDAddress.section(",",1,1).toInt()];
    //设置图片和标题
    QLabel *devp=new QLabel(this);
    devp->setGeometry(5,10,70,70);
    devp->setPixmap(QPixmap(VavleImage[kindIDAddress.section(",",0,0).toInt()][kindIDAddress.section(",",1,1).toInt()]  ).scaled(70,70));
    //设置刷新显示标签
    QLabel *value =new QLabel(this);
    value->setGeometry(70,100,80,80);
    value->setFont(QFont("Timers",11, QFont::Bold));

    timer=new QTimer(this);
    timer->start(2000);
    connect(timer,QTimer::timeout,[=](){
        QSqlDatabase db = ConnectionPool::openConnection();
        QSqlQuery query(db);
        QString qs=QString("select * from bs where kind = '%1' and ID = '%2' and address = '%3' and flag = 'c'  order by  time desc limit 1").arg(kindIDAddress.section(",",0,0)).arg(kindIDAddress.section(",",1,1)).arg(kindIDAddress.section(",",2,2));
        qDebug()<<qs;
        if(!query.exec(qs)) qDebug()<<qs;
        while (query.next()) {
            value->setText(query.value("come").toString());
            qDebug()<<query.value("come").toString();

        }
        ConnectionPool::closeConnection(db);
    });

}

void Vavle::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<kind<<ID<<address;
    VavlePage *vavlePage=new VavlePage(this,kind,ID,address);
    vavlePage->show();
}
