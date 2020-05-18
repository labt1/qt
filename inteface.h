#ifndef INTEFACE_H
#define INTEFACE_H

#include <QMainWindow>
#include <usuario.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class inteface; }
QT_END_NAMESPACE

class inteface : public QMainWindow
{
    Q_OBJECT

public:
    inteface(QWidget *parent = nullptr);
    ~inteface();
    void crear_tabla();
    

private slots:
    void on_pushButton_2_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

    void on_cancelar_clicked();

private:
    Ui::inteface *ui;
    usuario user;
    QSqlDatabase dbmain;
};
#endif // INTEFACE_H
