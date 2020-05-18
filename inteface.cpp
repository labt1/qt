#include "inteface.h"
#include "ui_inteface.h"
#include "QDebug"
#include "form.h"
#include "QMessageBox"

inteface::inteface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inteface)
    , user("",""){
    ui->setupUi(this);
    QString nombre_db;
    nombre_db="Base_de_Datos.sqlite";
    dbmain=QSqlDatabase::addDatabase("QSQLITE");
    dbmain.setDatabaseName(nombre_db);
    if(dbmain.open()){
        qDebug()<<"Base de datos creada";
    }else{
        qDebug()<<"Error";
    }
    crear_tabla();
}

inteface::~inteface()
{
    delete ui;
}

void inteface::crear_tabla(){
    QString consulta;
    consulta.append("CREATE TABLE IF NOT EXISTS usuario("
                    "id VARCHAR(25) PRIMARY KEY,"
                    "contrasena VARCHAR(25)"
                    ");");
    QSqlQuery crear;
    crear.prepare(consulta);
    if(crear.exec()){
        qDebug()<<"Tabla creada";
    }else{
        qDebug()<<"Tabla no creada"<<crear.lastError();
    }
}

void inteface::on_pushButton_2_clicked(){
    user.set_id(ui->lineEdit->text());
    user.set_cont(ui->lineEdit_2->text());
    qDebug()<<user.get_id();
    qDebug()<<user.get_cont();
    QSqlQuery buscar;
    QString pass1;
    QString pass2;
    QString consulta;
    consulta.append("SELECT * FROM usuario where id='"+user.get_id()+"'");
    buscar.prepare(consulta);
    if(buscar.exec()){
        qDebug()<<"Consulta realizada";
        while(buscar.next()){
            pass1=buscar.value(0).toByteArray().constData();
            pass2=buscar.value(1).toByteArray().constData();
        }
    }
    if((pass1==user.get_id() && pass2==user.get_cont()) && (pass1!="" && pass2!="")){
        QMessageBox::information(this,tr("Nota"),tr("Bienvenido"));
        close();
        Form* v;
        v=new Form();
        v->show();
    }
    else if(pass1==user.get_id() && pass2!=user.get_cont()){
        QMessageBox::critical(this,tr("Error"),tr("La contraseña es incorrecta"));
    }
        else{
            {
                qDebug()<<"Nuevo usuario";
                QMessageBox::information(this,tr("Nota"),tr("Usuario nuevo"));

                //nuevos usuarios
                QSqlQuery insertar_db;
                insertar_db.prepare("INSERT INTO usuario(id,contrasena)"
                                "VALUES (:id,:contrasena)");
                insertar_db.bindValue(":id",user.get_id());
                insertar_db.bindValue(":contrasena",user.get_cont());
                if(insertar_db.exec()){
                    qDebug()<<"Datos ingresados";
                }else{
                qDebug()<<"Error al ingresar datos";
                }
         }
    }
}

void inteface::on_pushButton_clicked()
{
    close();
}

void inteface::on_lineEdit_cursorPositionChanged(int arg1, int arg2){}
