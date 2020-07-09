#ifndef DOS_CONSUMIDORES_H
#define DOS_CONSUMIDORES_H

#include <QWidget>

namespace Ui {
class Dos_Consumidores;
}

class Consumidor;
class Productor;

class Dos_Consumidores : public QWidget
{
    Q_OBJECT

public:
    explicit Dos_Consumidores(QWidget *parent = nullptr);
    ~Dos_Consumidores();

private slots:
    void on_Iniciar_P_clicked();

    void on_detener_P_clicked();

private:
    Ui::Dos_Consumidores *ui;

    Productor * c2_thread;
    Consumidor * c3_thread;
    Consumidor * c4_thread;
};

#endif // DOS_CONSUMIDORES_H
