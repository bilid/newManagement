#include "vavlepage.h"
#include <QDebug>
#include <QPainter>
VavlePage::VavlePage(QWidget *parent,QString kind,QString ID,QString address) : QMainWindow(parent)
{
    //窗口关闭删除所有子对象
    this->setAttribute(Qt::WA_DeleteOnClose);
    //定义窗口大小布局
    QSize size(320*1.3,588*1.3);
    setFixedSize(size);
    setWindowIcon(QIcon(VavleImage[kind.toInt()][ID.toInt()] ));
    QString title=QString("%1 地址：%2").arg(VavleName[kind.toInt()][ID.toInt()].mid(0,5)).arg(address);
    setWindowTitle(title);
    //设置阈值选择按钮
    MyScrollArea *sc=new MyScrollArea();
    sc->setParent(this);
    connect(sc,&MyScrollArea::sendLabelText,[=](QString labelText){
        qDebug()<<labelText;
    });
    //设置图表

}

void VavlePage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/2.JPG");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
