#include "productor.h"
#include <QMutex>
#include "QRandomGenerator64"

Productor::Productor(QObject *parent)
    :QThread (parent)
{

}

void Productor::run()
{
    int desperdicio = 0;
    if (first){
        *canasta = 0;
        first = false;
    }
    if(size == 0)
    {
        while(true)
        {
            QMutex m;
            m.lock();
            *canasta+=1;
            emit producir2(produciendo);
            produciendo++;
            m.unlock();
            msleep(90);
        }
    }
    else {
        while (true)
        {
            if(*canasta <= size)
            {
                QMutex m;
                m.lock();
                *canasta+=1;
                emit producir1(*canasta);
                emit producir2(produciendo);
                produciendo++;
                m.unlock();
                msleep(90);
            }
            else {
                std::uniform_int_distribution<int>distribution(1,500);
                int value = distribution(*QRandomGenerator::global());
                desperdicio+=value;
                emit desperdicios(desperdicio);
                msleep(value);
            }
        }
    }

}

void Productor :: setsize(int size0)
{
    size = size0;
}

void Productor :: setcanasta(int canasta0)
{
    canasta = &canasta0;
}
