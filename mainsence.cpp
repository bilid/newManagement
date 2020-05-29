#include "mainsence.h"
#include "QScrollArea"
#include <QGridLayout>
#include <QTimer>
#include <system.h>
#include <connectionpool.h>
#include <QDebug>
#include <systempage.h>
#include <QPainter>

MainSence::MainSence()
{
    QSize size(320*1.3,588*1.3);
    setFixedSize(size);
    setWindowIcon(QIcon(":/res/camping_72px_1206967_easyicon.net.png"));
    setWindowTitle("生态管理器");

    QScrollArea *scrollArea =new QScrollArea(this);
    scrollArea->setStyleSheet("border:0px;background-color:rgba(0,0,0,0);");
    scrollArea->setGeometry(0,200,this->width(),this->height()-200);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setWidgetResizable(true);
    QGridLayout *pLayout = new QGridLayout();//网格布局
    QWidget *contenWidget=new QWidget(scrollArea);
    scrollArea->setWidget(contenWidget);
    contenWidget->setLayout(pLayout);
//    scrollArea->setStyleSheet("QScrollArea {background-color:transparent;}");
//    scrollArea->viewport()->setStyleSheet("background-color:transparent;");
    scrollArea->setFrameShape(QFrame::NoFrame);
    //数据库操作 读取添加系统
    QTimer *timer=new QTimer;
    timer->start(1000);
    connect(timer,QTimer::timeout,[=](){
        QSqlDatabase db = ConnectionPool::openConnection();
        QSqlQuery query(db);
        query.exec("select * from onlist;");
        while (query.next()) {
            //如果不存在就添加系统
            QString IDAdress=QString("%1%2").arg(query.value("kind").toString()).arg(query.value("address").toString());
            if(!NowOnList.contains(IDAdress))
            {
                qDebug()<<IDAdress;
                NowOnList.append(IDAdress);
                System *system=new System(0,query.value("kind").toString() ,query.value("address").toString());
                pLayout->addWidget(system, i/2, i%2);
                i++;
                connect(system,&System::devicePressed,[=](QString DD,QString AA){
                    SystemPage*systmPage=new SystemPage(this,DD,AA);
                    systmPage->show();

                });
            }
        }

        // 连接使用完后需要释放回数据库连接池
        ConnectionPool::closeConnection(db);
    });


}

void MainSence::paintEvent(QPaintEvent *event)
{    QPainter painter(this);
     QPixmap pix;
      pix.load(":/res/1.JPG");
       painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
