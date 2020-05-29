#include "myscrollarea.h"
#include <QPushButton>
#include <QLayout>
#include <QPixmap>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
MyScrollArea::MyScrollArea(QWidget *parent)
{
    QSize size(120,120);
    this->setFixedSize(size);
    //设定组件背景
    //设置不规则图片样式 border-radius: 11px;
    this->setStyleSheet("MyScrollArea:{border:2px groove gray;border-radius:20px;padding:2px 4px;}");
    this->setPixmap(QPixmap(":/res/1.png").scaled(size));

    QScrollArea *scrollArea =new QScrollArea(this);
    scrollArea->setStyleSheet("border:0px;background-color:rgba(0,0,0,0);");
    scrollArea->setGeometry(10,30,this->width()-20,this->height()-60);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setWidgetResizable(true);
    QGridLayout *pLayout = new QGridLayout();//网格布局
    QWidget *contenWidget=new QWidget(scrollArea);
    scrollArea->setWidget(contenWidget);
    contenWidget->setLayout(pLayout);
    //    scrollArea->setStyleSheet("QScrollArea {background-color:transparent;}");
    //    scrollArea->viewport()->setStyleSheet("background-color:transparent;");
    scrollArea->setFrameShape(QFrame::NoFrame);
    for(int i=0;i<=100;i++)
    {
        QPushButton *button=new QPushButton();
        button->setText(QString::number(i));
        button->resize(60,40);
        button->setFont(QFont("Timers",11, QFont::Bold));
        button->setStyleSheet("QPushButton {background-color:transparent;}");
        button->setStyleSheet("QPushButton:hover{border-width: 1px;border-style: solid;border-radius:24px;border-color:rgb(40, 20, 20);}");
        pLayout->addWidget(button);
        connect(button,&QPushButton::clicked,[=](){
            emit sendLabelText(QString::number(i));
        });

    }

}
