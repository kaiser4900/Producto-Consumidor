#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    int canasta_g2;
    ~MainWindow();

private slots:
    void on_Iniciar_P_clicked();

    void on_detener_P_clicked();

    void on_iniciar_C_clicked();

    void on_detener_C_clicked();

    void on_iniciar_C_2_clicked();

    void on_detener_C_2_clicked();

private:
    Ui::MainWindow *ui;

    Productor * c2_thread;
    Consumidor * c3_thread;
    Consumidor * c4_thread;
};

#endif // MAINWINDOW_H
