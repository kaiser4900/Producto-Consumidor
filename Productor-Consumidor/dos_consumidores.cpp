#include "dos_consumidores.h"
#include "ui_dos_consumidores.h"
#include "consumidor.h"
#include "productor.h"

Dos_Consumidores::Dos_Consumidores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dos_Consumidores)
{
    ui->setupUi(this);

    int canasta_g2;

    c2_thread = new Productor(this);
    c2_thread->setcanasta(canasta_g2);


    c3_thread = new Consumidor(this);
    c3_thread->setcanasta(canasta_g2);


    c4_thread = new Consumidor(this);
    c4_thread->setcanasta(canasta_g2);

    ui->progressBar->setValue(0);

    connect(c2_thread, &Productor::producir1, ui->progressBar, &QProgressBar::setValue);
    connect(c3_thread, &Consumidor::consumir1, ui->progressBar, &QProgressBar::setValue);
    connect(c4_thread, &Consumidor::consumir1, ui->progressBar, &QProgressBar::setValue);

    connect(c2_thread, SIGNAL(producir2(int)),ui->lcdNumber,SLOT(display(int)));
    connect(c3_thread, SIGNAL(consumir2(int)),ui->lcdNumber_2,SLOT(display(int)));
    connect(c4_thread, SIGNAL(consumir2(int)),ui->lcdNumber_3,SLOT(display(int)));

    connect(c2_thread, SIGNAL(desperdicios(int)),ui->lcdNumber_5,SLOT(display(int)));
    connect(c3_thread, SIGNAL(desperdicios(int)),ui->lcdNumber_6,SLOT(display(int)));
    connect(c4_thread, SIGNAL(desperdicios(int)),ui->lcdNumber_7,SLOT(display(int)));
}

Dos_Consumidores::~Dos_Consumidores()
{
    delete ui;
}

void Dos_Consumidores::on_Iniciar_P_clicked()
{
    if(ui->radioButton->isChecked())
    {
        QString a0 = ui->lineEdit->text();
        int a1 = a0.toInt();
        ui->progressBar->setMaximum(a1);
        c2_thread->setsize(a1);
        c2_thread->start();
    }
    else {
        c2_thread->start();
    }
}

void Dos_Consumidores::on_detener_P_clicked()
{
    c2_thread->terminate();
}
