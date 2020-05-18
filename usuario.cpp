#include "usuario.h"

usuario::usuario(QString nid, QString c){
    id=nid;
    contrasena=c;
}

QString usuario::get_id(){
    return id;
}

void usuario::set_id(QString nid){
    id=nid;
}

QString usuario::get_cont(){
    return contrasena;
}

void usuario::set_cont(QString cont){
    contrasena=cont;
}
