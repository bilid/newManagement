#include "systempage.h"
#include "QScrollArea"
#include <QGridLayout>
#include <QTimer>
#include <system.h>
#include <connectionpool.h>
#include <QDebug>
#include <systempage.h>
#include <vavle.h>
#include <QPainter>
SystemPage::SystemPage(QWidget *parent,QString kind,QString address) : QMainWindow(parent)
{
    //窗口关闭删除所有子对象
    this->setAttribute(Qt::WA_DeleteOnClose);
    //定义窗口大小布局
    QSize size(320*1.3,588*1.3);
    setFixedSize(size);
    setWindowIcon(QIcon(deviceImgs.at(kind.toInt())));
    QString title=QString("%1 地址：%2").arg(deviceName.at(kind.toInt())).arg(address);
    setWindowTitle(title);
    scrollArea =new QScrollArea(this);
    scrollArea->setStyleSheet("border:0px;background-color:rgba(0,0,0,5);");
    scrollArea->setGeometry(0,200,this->width(),this->height()-200);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setWidgetResizable(true);
    pLayout = new QGridLayout(this);//网格布局
    QWidget *contenWidget=new QWidget(scrollArea);
    scrollArea->setWidget(contenWidget);
    contenWidget->setLayout(pLayout);
    //数据库操作 读取添加系统
    QTimer *timer=new QTimer(this);
    timer->start(1000);
    connect(timer,QTimer::timeout,[=](){
        QSqlDatabase db = ConnectionPool::openConnection();
        QSqlQuery query(db);
        QString qs=QString("select * from onlist where kind = '%1'  and address = '%2' ; ").arg(kind).arg(address);
        if(!query.exec(qs)) qDebug()<<qs;
        while (query.next()) {
            //如果不存在就添加系统
            QString kindIDAdress=QString("%1,%2,%3").arg(kind).arg(query.value("ID").toString()).arg(address);
            if(!NowOnList.contains(kindIDAdress))
            {
                qDebug()<<kindIDAdress;
                NowOnList.append(kindIDAdress);
                Vavle *vavle=new Vavle(this,kindIDAdress);
                pLayout->addWidget(vavle, i/2, i%2);
                i++;

            }
        }

        // 连接使用完后需要释放回数据库连接池
        ConnectionPool::closeConnection(db);
    });


}

void SystemPage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/3.JPG");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void SystemPage::closeEvent(QCloseEvent *event)
{

}


