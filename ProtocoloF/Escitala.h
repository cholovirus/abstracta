#include <iostream>
#include <string.h>

using namespace std;

class Escitala{
    private:
        int columna,fila;   //clave
    public:
        string alfabeto = "abcdefghijklmnopqrstuvwxyz0123456789 ";
        Escitala(int, int);
        string Incriptado(string);
        string Descifrado(string,int , int);
        int modulo(int , int);
        
};


