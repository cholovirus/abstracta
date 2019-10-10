#include <iostream>
#include <string.h>
#include <cmath>
#include <time.h>
#include <sstream>


using namespace std;

class RSA{
    private:
        unsigned long long privada;
        unsigned long long publica=0;
        unsigned long long modN;
        unsigned long long phiN;
    public:
        string alfabeto= "abcdefghijklmnopqrstuvwxyz ";
        
        RSA(unsigned long long, unsigned long long);
        
        unsigned long long numexponente(int, unsigned long long, int);
        string Incriptado(string,unsigned long long, unsigned long long);
        string Desincriptado(string,unsigned long long);
};