#include "Protocolo.h"

using namespace std;

int main(){
    //string mensaje;
    //getline(cin,mensaje);
    //string mensaje="formato de lectura para las claves y mensaje";
    //Protocolo a("bac");
    //cout<<a.Incriptado(mensaje);
    string mensaje;
    getline(cin,mensaje);

    Protocolo a("hol",2,19,mensaje.size());
    cout<<a.Incriptado(mensaje);
    cout<<endl;
    Protocolo h("cifrado");
    cout<<h.Desincriptado();
}

//44
//phwvrgilgebtyksihela12iprlxm2ltqydrc1pkl9uve