#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

#include<QThread>

class Consumidor: public QThread
{
    Q_OBJECT
    int *canasta;
public:
    Consumidor(QObject *parent = nullptr);
    void setcanasta(int canasta0);
signals:

    void consumir1(int);
    void consumir2(int);
    void desperdicios(int);

protected:
    void run() override;
};

#endif // CONSUMIDOR_H
