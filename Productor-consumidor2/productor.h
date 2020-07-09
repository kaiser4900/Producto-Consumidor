#ifndef PRODUCTOR_H
#define PRODUCTOR_H

#include<QThread>

class Productor: public QThread
{
    Q_OBJECT
    int size = 0;
    int * canasta;
    int produciendo = 0;
    bool first = true;
    clock_t inicio;
    clock_t fin;
public:
    Productor(QObject *parent = nullptr);
    void setsize(int size0);
    void setcanasta(int canasta0);
    void setinicio(clock_t t0);
    void setfin(clock_t t1);
    void total();
signals:

    void producir1(int);
    void producir2(int);
    void desperdicios(int);
    void marca_total(int);

protected:
    void run() override;
};

#endif // PRODUCTOR_H
