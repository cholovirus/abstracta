#include "Escitala.h"

using namespace std;

int main(){
    string mensaje;
    cout<<"Escriba un mensaje: "; getline(cin,mensaje);
    cout<<mensaje.size()<<endl;
    int fil, col;
    cout<<"Fila: "; cin>>fil; cout<<"Columna: "; cin>>col;
    
    Escitala men(fil,col);
    string a= men.Incriptado(mensaje);
    
     
    cout<<a<<endl;
    cout<<men.Descifrado(a,fil,col);
}