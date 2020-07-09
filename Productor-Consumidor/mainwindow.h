#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dos_consumidores.h>
namespace Ui {
class MainWindow;
}

class Consumidor;
class Productor;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    int canasta_g;
    ~MainWindow();

private slots:

    void on_radioButton_clicked();

    void on_Iniciar_P_clicked();

    void on_detener_P_clicked();

    void on_iniciar_C_clicked();

    void on_detener_C_clicked();


private:
    Ui::MainWindow *ui;

    Productor * c0_thread;
    Consumidor * c1_thread;
};

#endif // MAINWINDOW_H
