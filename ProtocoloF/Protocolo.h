#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Protocolo{
    private:
        string rotor;
        string claveE;
        int fila, columna; string f, c;
        int lenViginere;
        string vig;
        string a,b;
        string mensaje;
    public:
        string alfabeto ="abcdefghijklmnopqrstuvwxyz0123456789 ";
        Protocolo(string,int,int,int);
        Protocolo(string);
        void creartxt(string , string);
        string leertxt(string);

        string Incriptado(string);
        string Desincriptado();

};