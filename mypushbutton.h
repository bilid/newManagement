#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
   // explicit MyPushButton(QWidget *parent = 0);
    //构造函数 参数1：正常显示图片的路径 参数2： 按下显示图片的路径
    MyPushButton(QString normaImg,QString pressImg = "" ,float ratio=1.0 );
    //成员变量 俩个图片的路径
    QString normaImgPath;
    QString pressImgPath;
    //弹跳特效
    void zoom1();//向下跳
    void zoom2();//向上跳

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
