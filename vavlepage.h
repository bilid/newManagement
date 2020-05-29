#ifndef VAVLEPAGE_H
#define VAVLEPAGE_H

#include <QMainWindow>
#include <myscrollarea.h>
class VavlePage : public QMainWindow
{
    Q_OBJECT
public:
    explicit VavlePage(QWidget *parent ,QString kind,QString ID,QString address);

signals:

public slots:
private:
    const QString VavleName[6][10]=
    {
        {"电磁阀0:     \n\n湿度：        %rh","电磁阀1:      \n\n湿度：        %rh","电磁阀2:      \n\n湿度：        %rh","电磁阀3:      \n\n湿度：        %rh","电磁阀4:      \n\n湿度：        %rh","电磁阀5:      \n\n湿度：        %rh","电磁阀6:      \n\n湿度：        %rh","电磁阀7:      \n\n湿度：        %rh","电磁阀8:      \n\n湿度：        %rh","电磁阀9:      \n\n湿度：        %rh"},
        {"土壤温度:     \n\n温度：        ℃","土壤湿度:        \n\n湿度：        %rh","土壤电导率:     \n\n电导率：        Ω·m","","","","","","",""},
        {"土壤温度:     \n\n温度：        ℃","土壤湿度:        \n\n湿度：        %rh","土壤电导率:     \n\n电导率：        Ω·m","土壤pH:     \n\npH：         ","光照强度:        \n\n光强：        lux","二氧化碳含量:        \n\浓度：        g/L","风速:     \n\浓度：        m/s","空气温度:       \n\n温度：        ℃","空气湿度:        \n\n湿度：        %rh","pM2.5含量:       \n\n湿度：        um"},
        {"加热器:      \n\n温度：        ℃","","","","","","","","",""},
        {"水温:       \n\n温度：        ℃","溶解氧含量:       \n\浓度：        g/L","酸碱pH:       \n\npH：         ","电导率:     \n\n电导率：        Ω·m","浊度:       \n\n浊度：        NTU","氨氮:        \n\浓度：        g/L","叶绿素、蓝藻素含量:      \n\浓度：        g/L","","",""},
        {"","","","","","","","","",""},

    };
    const QString VavleImage[10][10]=
    {
        {":/res/0,0.png",":/res/0,0.png",":/res/0,0.png",":/res/0,0.png",":/res/0,0.png",":/res/0,0.png",":/res/0,0.png",":/res/0,0.png",":/res/0,0.png",":/res/0,0.png"},
        {":/res/1,0.png",":/res/1,1.png",":/res/1,2.png","","","","","","",""},
        {":/res/1,0.png",":/res/1,1.png",":/res/1,2.png",":/res/2,3.png",":/res/2,4.png",":/res/2,5.png",":/res/2,6.png",":/res/2,7.png",":/res/2,8.png",":/res/2,9.png"},
        {":/res/3,0.png",":/res/3,0.png",":/res/3,0.png",":/res/3,0.png",":/res/3,0.png",":/res/3,0.png",":/res/3,0.png",":/res/3,0.png","",""},
        {":/res/4,0.png",":/res/4,1.png",":/res/4,2.png",":/res/4,3.png",":/res/4,4.png",":/res/4,5.png",":/res/4,6.png","","",""},
        {"","","","","","","","","",""},
    };
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // VAVLEPAGE_H
