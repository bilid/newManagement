#ifndef MAINSENCE_H
#define MAINSENCE_H
#include <QList>
#include <QMainWindow>
class MainSence: public QMainWindow
{
    Q_OBJECT
public:
    MainSence();
private:
    int i=0;
private:
    QList<QString> NowOnList;
    void paintEvent(QPaintEvent *event);

};

#endif // MAINSENCE_H
