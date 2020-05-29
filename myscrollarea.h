#ifndef MYSCROLLAREA_H
#define MYSCROLLAREA_H
#include <QScrollArea>
#include <QLabel>
#include <QWidget>

class MyScrollArea : public QLabel
{
    Q_OBJECT
public:
    explicit MyScrollArea(QWidget *parent =0);

signals:
    sendLabelText(QString labelText);

public slots:
};

#endif // MYSCROLLAREA_H
