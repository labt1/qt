#include "form.h"
#include "ui_form.h"
#include "inteface.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    mModel = new QSqlTableModel(this);
    mModel->setTable("usuario");
    mModel->select();
    ui->tableView->setModel(mModel);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
   inteface* i;
   i=new inteface();
   close();
   i->show();
}
