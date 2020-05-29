#ifndef SYSTEM_H
#define SYSTEM_H

#include <QWidget>
#include <QLabel>
class System : public QLabel
{
    Q_OBJECT
public:
    explicit System(QWidget *parent ,QString ID,QString Address);
private:
    int i =0;
    //系统图片
    const QList<QString> deviceImgs={
        ":/res/guangai.png",
        ":/res/turang.png",
        ":/res/qixiang .png",
        ":/res/PID.png",
        ":/res/shuihuanjing .png",
    };
    //系统名称
    const QList<QString> deviceName={
        "灌溉",
        "土壤",
        "气象",
        "PID",
        "水环境"
    };
    QString DD;
    QString AA;
protected:
    void mousePressEvent(QMouseEvent *ev);
signals:
    devicePressed(QString d,QString a);

public slots:
};

#endif // SYSTEM_H
