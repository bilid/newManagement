#ifndef SYSTEMPAGE_H
#define SYSTEMPAGE_H
#include "QScrollArea"
#include <QGridLayout>
#include <QMainWindow>

class SystemPage : public QMainWindow
{
    Q_OBJECT
public:
    explicit SystemPage(QWidget *parent ,QString kind,QString address);

signals:

public slots:
private:
    const QList<QString> deviceImgs={
        ":/res/guangai.png",
        ":/res/turang.png",
        ":/res/qixiang .png",
        ":/res/PID.png",
        ":/res/shuihuanjing .png",
    };
    //系统名称
    const QList<QString> deviceName={
        "智能灌溉系统",
        "土壤环境监测系统",
        "气象环境监测系统",
        "PID水温控制系统",
        "水环境检测系统"
    };
private:
    QList<QString> NowOnList;
    int i=0;
    QScrollArea *scrollArea;
    QGridLayout *pLayout;
protected:
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *event);
};

#endif // SYSTEMPAGE_H
