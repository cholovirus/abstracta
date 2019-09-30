#include <iostream>
#include <string.h>
#include <cmath>
#include <time.h>
#include <fstream>

using namespace std;

class Vernar{
    private:
    string clave;

    public:
    string alfabeto= "abcdefghijklmnopqrstuvwxyz0123456789 ";
    string leertxt();
    void creartxt(string);
    string binario(int);
    string xorbinario(string, string);
    int bindecimal(string);
    
    Vernar(){}
    Vernar(int);
    string Incriptado(string);
    string Desincriptado(string);
};