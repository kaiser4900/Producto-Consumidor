#include "consumidor.h"
#include <QMutex>
#include "QRandomGenerator64"

Consumidor::Consumidor(QObject *parent)
    :QThread (parent)
{

}

void Consumidor::run()
{
    int consumiendo = 0;
    int desperdicio = 0;
    while(true)
    {
        consumiendo++;
        if(*canasta <= 0)
        {
            std::uniform_int_distribution<int>distribution(1,500);
            int value = distribution(*QRandomGenerator::global());
            desperdicio+=value;
            emit desperdicios(desperdicio);
            msleep(value);
        }
        else {
            QMutex m;
            m.lock();
            emit consumir2(consumiendo);
            *canasta-=1;
            emit consumir1(*canasta);
            m.unlock();
            msleep(90);
        }
    }
}
void Consumidor :: setcanasta(int canasta0)
{
    canasta = &canasta0;
}
