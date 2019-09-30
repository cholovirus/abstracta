#include "Vigenere.h"

using namespace std;

int main(){
    string mensaje;
    getline(cin,mensaje);
    int len=mensaje.size();
    Vigenere men(len);
    string cifrado=men.Incriptado(mensaje);
    //cout<<cifrado<<endl;
    cout<<men.Desincriptado(cifrado,men.Obtenerclave());
}
