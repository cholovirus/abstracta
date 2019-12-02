#ifndef ELGAMAL_H
#define ELGAMAL_H
#include <iostream>
#include <NTL/ZZ.h>
#include <string.h>

using namespace std;
using namespace NTL;

class ElGamal
{
    private:
        ZZ primo;
        ZZ e1, e2;
        ZZ D;
        ZZ C1,C2;
        ZZ K;
        ZZ r;

    public:
        string alfabeto;
        ElGamal(int,string);
        ElGamal(ZZ,ZZ,ZZ,string);
        ElGamal(ZZ,ZZ,string);

        string Incriptado(string);
        string Desincriptado(string);

        //Operaciones

        ZZ raizPrimitiva(ZZ);
        ZZ exponencial(ZZ,ZZ,ZZ);
        ZZ euclides(ZZ,ZZ);
        ZZ modulo(ZZ,ZZ);
        ZZ euclidesE(ZZ,ZZ);
        ZZ numexponente(ZZ,ZZ,ZZ);
        bool testprimo(ZZ);
        ZZ genPrimo(int);

        //Auxiliares
        ZZ ZZtostring(string);
        string stringtoZZ(ZZ);

};

#endif // ELGAMAL_H
