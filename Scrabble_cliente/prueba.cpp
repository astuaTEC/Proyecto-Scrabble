#include "prueba.h"
#include "ui_prueba.h"

prueba::prueba(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prueba)
{
    ui->setupUi(this);

    QPixmap pix("/home/kevin/Descargas/image1_opt.jpg");
    ui->imagen->setPixmap(pix);
}

prueba::~prueba()
{
    delete ui;
}
