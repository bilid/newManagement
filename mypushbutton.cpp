#include "mypushbutton.h"
#include "QDebug"
#include "QPropertyAnimation"
MyPushButton::MyPushButton(QString normaImg, QString pressImg,float ratio )
{
    this->normaImgPath=normaImg;
    this->pressImgPath=pressImg;


    QPixmap pix;

    bool ret= pix.load(normaImg);

    if(!ret)
    {
        qDebug()<<"显示图片失败";
        return;
    }
     pix=pix.scaled(pix.width()*ratio,pix.height()*ratio);
    this->setFixedSize(pix.width() ,pix.height() );
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pix);
    this->setIconSize(QSize(pix.width() ,pix.height() ));


}

void MyPushButton::zoom1()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyPushButton::zoom2()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()  ,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}
