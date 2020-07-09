#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "consumidor.h"
#include "productor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    c0_thread = new Productor(this);
    c0_thread->setcanasta(canasta_g);


    c1_thread = new Consumidor(this);
    c1_thread->setcanasta(canasta_g);


    ui->progressBar->setValue(0);


    connect(c0_thread, SIGNAL(marca_total(int)),ui->lcdNumber_3,SLOT(display(int)));
    connect(c1_thread, SIGNAL(marca_total(int)),ui->lcdNumber_4,SLOT(display(int)));

    connect(c0_thread, &Productor::producir1, ui->progressBar, &QProgressBar::setValue);
    connect(c1_thread, &Consumidor::consumir1, ui->progressBar, &QProgressBar::setValue);

    connect(c0_thread, SIGNAL(producir2(int)),ui->lcdNumber,SLOT(display(int)));
    connect(c1_thread, SIGNAL(consumir2(int)),ui->lcdNumber_2,SLOT(display(int)));

    connect(c0_thread, SIGNAL(desperdicios(int)),ui->lcdNumber_6,SLOT(display(int)));
    connect(c1_thread, SIGNAL(desperdicios(int)),ui->lcdNumber_5,SLOT(display(int)));

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_clicked()
{
    ui->progressBar->setValue(0);
}

void MainWindow::on_Iniciar_P_clicked()
{
    if(ui->radioButton->isChecked())
    {
        QString a0 = ui->lineEdit->text();
        int a1 = a0.toInt();
        ui->progressBar->setMaximum(a1);
        c0_thread->setsize(a1);
        c0_thread->start();
    }
    else {
        c0_thread->start();
    }
    srand(time(NULL));
    clock_t inicio = clock();
    c0_thread->setinicio(inicio);
}

void MainWindow::on_detener_P_clicked()
{
    srand(time(NULL));
    clock_t fin = clock();
    c0_thread->setfin(fin);
    c0_thread->total();
    c0_thread->terminate();
}

void MainWindow::on_iniciar_C_clicked()
{
    c1_thread->start();
    srand(time(NULL));
    clock_t inicio = clock();
    c1_thread->setinicio(inicio);
}

void MainWindow::on_detener_C_clicked()
{
    srand(time(NULL));
    clock_t fin = clock();
    c1_thread->setfin(fin);
    c1_thread->total();
    c1_thread->terminate();
}
