#ifndef VIGENERE_H
#define VIGENERE_H
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>

using namespace std;

class Vigenere
{
    private:
        
        string clave;

    public:
        string alfabeto = "abcdefghijklmnopqrstuvwxyz0123456789 ";
        //string cifrado;
        int size_;
        Vigenere(){}
        Vigenere(int);
        void Incriptado(string);
        void Desincriptado(string,string);
        
        int modulo(int , int);
};

#endif // VIGENERE_H
