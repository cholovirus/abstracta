#include "Enigma.h"

int main(){
    Enigma a("98 ");
    string mensaje;
    getline(cin,mensaje);
    
    string b= a.Incriptado(mensaje);
    
    cout<<b<<endl;
    cout<< a.Desincriptado(b,"98 ");
}

