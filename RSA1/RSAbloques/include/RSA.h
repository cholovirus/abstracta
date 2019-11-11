#ifndef RSA_H
#define RSA_H
#include <iostream>
#include <string.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

class RSA
{
private:
    ZZ privada; //d
    ZZ publica; //e
    ZZ modN; //N
    ZZ phi;
    ZZ P,Q;
    string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
public:
    // RSA
    RSA(int); // cantidad de bits
    RSA(ZZ,ZZ);// cargar publica y modN
    RSA(ZZ,ZZ,ZZ);

    // Incriptado - Desincriptado

    string Incriptado(string);
    string Desincriptado(string);

    // Operaciones matematicas

    ZZ numexp(ZZ,ZZ,ZZ);
    ZZ resto_chino(ZZ);
    ZZ euclides(ZZ,ZZ);
    ZZ euclidesE(ZZ,ZZ);
    ZZ modulo(ZZ,ZZ);

    bool primalidad(ZZ);
    ZZ numaletorio(int);

    // Operaciones Utilitarias

    ZZ string_ZZ(string);
    string ZZ_string(ZZ);

};

#endif // RSA_H
