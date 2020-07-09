#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

#include<QThread>

class Consumidor: public QThread
{
    Q_OBJECT
    int *canasta;
    clock_t inicio;
    clock_t fin;

public:
    Consumidor(QObject *parent = nullptr);
    void setcanasta(int canasta0);
    void setinicio(clock_t t0);
    void setfin(clock_t t1);
    void total();
signals:

    void consumir1(int);
    void consumir2(int);
    void desperdicios(int);
    void marca_total(int);

protected:
    void run() override;
};

#endif // CONSUMIDOR_H
