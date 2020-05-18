#ifndef USUARIO_H
#define USUARIO_H
#include <QString>


class usuario{
    QString id;
    QString contrasena;
    public:
        usuario(QString,QString);
        QString get_id();
        void set_id(QString);
        QString get_cont();
        void set_cont(QString);
};

#endif // USUARIO_H
