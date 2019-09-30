#include <iostream>
#include <string.h>
#include <cmath>
#include <time.h>

using namespace std;

class Enigma{
    private:
        string clave;
        string rotor1, rotor2 ,rotor3;
    public:
        string rotorRan(string);
        //string alfabeto ="abcdefghijklmnopqrstuvwxyz0123456789 ";
        string alfabeto ="abcdefghijklmnopqrstuvwxyz ";
        int modulo(int,int);
        
        Enigma(string);
        Enigma(string,string,string);
        
        string Incriptado(string);
        string Desincriptado(string,string);

};
